//===- ExpandSmallArguments.cpp - Expand out arguments smaller than i32----===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// LLVM IR allows function return types and argument types such as
// "zeroext i8" and "signext i8".  The Language Reference says that
// zeroext "indicates to the code generator that the parameter or
// return value should be zero-extended to the extent required by the
// target's ABI (which is usually 32-bits, but is 8-bits for a i1 on
// x86-64) by the caller (for a parameter) or the callee (for a return
// value)".
//
// This can lead to non-portable behaviour when calling functions
// without C prototypes or with wrong C prototypes.
//
// In order to remove this non-portability from PNaCl, and to simplify
// the language that the PNaCl translator accepts, the
// ExpandSmallArguments pass widens integer arguments and return types
// to be at least 32 bits.  The pass inserts explicit cast
// instructions (ZExtInst/SExtInst/TruncInst) as needed.
//
// The pass chooses between ZExtInst and SExtInst widening based on
// whether a "signext" attribute is present.  However, in principle
// the pass could always use zero-extension, because the extent to
// which either zero-extension or sign-extension is done is up to the
// target ABI, which is up to PNaCl to specify.
//
//===----------------------------------------------------------------------===//

#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IntrinsicInst.h"
#include "llvm/IR/Module.h"
#include "llvm/Pass.h"
#include "llvm/Transforms/NaCl.h"

using namespace llvm;

namespace {
  // This is a ModulePass because the pass recreates functions in
  // order to change their arguments' types.
  class ExpandSmallArguments : public ModulePass {
  public:
    static char ID; // Pass identification, replacement for typeid
    ExpandSmallArguments() : ModulePass(ID) {
      initializeExpandSmallArgumentsPass(*PassRegistry::getPassRegistry());
    }

    virtual bool runOnModule(Module &M);
  };
}

char ExpandSmallArguments::ID = 0;
INITIALIZE_PASS(ExpandSmallArguments, "expand-small-arguments",
                "Expand function arguments to be at least 32 bits in size",
                false, false)

// Returns the normalized version of the given argument/return type.
static Type *NormalizeType(Type *Ty) {
  if (IntegerType *IntTy = dyn_cast<IntegerType>(Ty)) {
    if (IntTy->getBitWidth() < 32) {
      return IntegerType::get(Ty->getContext(), 32);
    }
  }
  return Ty;
}

// Returns the normalized version of the given function type.
static FunctionType *NormalizeFunctionType(FunctionType *FTy) {
  if (FTy->isVarArg()) {
    report_fatal_error(
        "ExpandSmallArguments does not handle varargs functions");
  }
  SmallVector<Type *, 8> ArgTypes;
  for (unsigned I = 0; I < FTy->getNumParams(); ++I) {
    ArgTypes.push_back(NormalizeType(FTy->getParamType(I)));
  }
  return FunctionType::get(NormalizeType(FTy->getReturnType()),
                           ArgTypes, false);
}

// Convert the given function to use normalized argument/return types.
static bool ConvertFunction(Function *Func) {
  FunctionType *FTy = Func->getFunctionType();
  FunctionType *NFTy = NormalizeFunctionType(FTy);
  if (NFTy == FTy)
    return false; // No change needed.
  Function *NewFunc = RecreateFunction(Func, NFTy);

  // Move the arguments across to the new function.
  for (Function::arg_iterator Arg = Func->arg_begin(), E = Func->arg_end(),
         NewArg = NewFunc->arg_begin();
       Arg != E; ++Arg, ++NewArg) {
    NewArg->takeName(Arg);
    if (Arg->getType() == NewArg->getType()) {
      Arg->replaceAllUsesWith(NewArg);
    } else {
      Instruction *Trunc = new TruncInst(
          NewArg, Arg->getType(), NewArg->getName() + ".arg_trunc",
          NewFunc->getEntryBlock().getFirstInsertionPt());
      Arg->replaceAllUsesWith(Trunc);
    }
  }

  if (FTy->getReturnType() != NFTy->getReturnType()) {
    // Fix up return instructions.
    Instruction::CastOps CastType =
        Func->getAttributes().hasAttribute(0, Attribute::SExt) ?
        Instruction::SExt : Instruction::ZExt;
    for (Function::iterator BB = NewFunc->begin(), E = NewFunc->end();
         BB != E;
         ++BB) {
      for (BasicBlock::iterator Iter = BB->begin(), E = BB->end();
           Iter != E; ) {
        Instruction *Inst = Iter++;
        if (ReturnInst *Ret = dyn_cast<ReturnInst>(Inst)) {
          Value *Ext = CopyDebug(
              CastInst::Create(CastType, Ret->getReturnValue(),
                               NFTy->getReturnType(),
                               Ret->getReturnValue()->getName() + ".ret_ext",
                               Ret),
              Ret);
          CopyDebug(ReturnInst::Create(Ret->getContext(), Ext, Ret), Ret);
          Ret->eraseFromParent();
        }
      }
    }
  }

  Func->eraseFromParent();
  return true;
}

// Convert the given call to use normalized argument/return types.
static bool ConvertCall(CallInst *Call) {
  // Don't try to change calls to intrinsics.
  if (isa<IntrinsicInst>(Call))
    return false;
  FunctionType *FTy = cast<FunctionType>(
      Call->getCalledValue()->getType()->getPointerElementType());
  FunctionType *NFTy = NormalizeFunctionType(FTy);
  if (NFTy == FTy)
    return false; // No change needed.

  // Convert arguments.
  SmallVector<Value *, 8> Args;
  for (unsigned I = 0; I < Call->getNumArgOperands(); ++I) {
    Value *Arg = Call->getArgOperand(I);
    if (NFTy->getParamType(I) != FTy->getParamType(I)) {
      Instruction::CastOps CastType =
          Call->getAttributes().hasAttribute(I + 1, Attribute::SExt) ?
          Instruction::SExt : Instruction::ZExt;
      Arg = CopyDebug(CastInst::Create(CastType, Arg, NFTy->getParamType(I),
                                       "arg_ext", Call), Call);
    }
    Args.push_back(Arg);
  }
  Value *CastFunc =
    CopyDebug(new BitCastInst(Call->getCalledValue(), NFTy->getPointerTo(),
                              Call->getName() + ".arg_cast", Call), Call);
  CallInst *NewCall = CallInst::Create(CastFunc, Args, "", Call);
  CopyDebug(NewCall, Call);
  NewCall->takeName(Call);
  NewCall->setAttributes(Call->getAttributes());
  NewCall->setCallingConv(Call->getCallingConv());
  NewCall->setTailCall(Call->isTailCall());
  Value *Result = NewCall;
  if (FTy->getReturnType() != NFTy->getReturnType()) {
    Result = CopyDebug(new TruncInst(NewCall, FTy->getReturnType(),
                                     NewCall->getName() + ".ret_trunc",
                                     Call), Call);
  }
  Call->replaceAllUsesWith(Result);
  Call->eraseFromParent();
  return true;
}

bool ExpandSmallArguments::runOnModule(Module &M) {
  bool Changed = false;
  for (Module::iterator Iter = M.begin(), E = M.end(); Iter != E; ) {
    Function *Func = Iter++;
    // Don't try to change intrinsic declarations because intrinsics
    // will continue to have non-normalized argument types.  For
    // example, memset() takes an i8 argument.  It shouldn't matter
    // whether we modify the types of other function declarations, but
    // we don't expect to see non-intrinsic function declarations in a
    // PNaCl pexe.
    if (Func->empty())
      continue;

    for (Function::iterator BB = Func->begin(), E = Func->end();
         BB != E; ++BB) {
      for (BasicBlock::iterator Iter = BB->begin(), E = BB->end();
           Iter != E; ) {
        Instruction *Inst = Iter++;
        if (CallInst *Call = dyn_cast<CallInst>(Inst)) {
          Changed |= ConvertCall(Call);
        } else if (isa<InvokeInst>(Inst)) {
          report_fatal_error(
              "ExpandSmallArguments does not handle invoke instructions");
        }
      }
    }

    Changed |= ConvertFunction(Func);
  }
  return Changed;
}

ModulePass *llvm::createExpandSmallArgumentsPass() {
  return new ExpandSmallArguments();
}
