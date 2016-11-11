//===-- NaCl.h - NaCl Transformations ---------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_TRANSFORMS_NACL_H
#define LLVM_TRANSFORMS_NACL_H

namespace llvm {

class BasicBlockPass;
class Function;
class FunctionPass;
class FunctionType;
class Instruction;
class ModulePass;
class PassManager;
class Use;
class Value;

BasicBlockPass *createExpandGetElementPtrPass();
BasicBlockPass *createPromoteI1OpsPass();
FunctionPass *createExpandConstantExprPass();
FunctionPass *createExpandStructRegsPass();
FunctionPass *createInsertDivideCheckPass();
FunctionPass *createPromoteIntegersPass();
FunctionPass *createRemoveAsmMemoryPass();
FunctionPass *createResolvePNaClIntrinsicsPass();
ModulePass *createAddPNaClExternalDeclsPass();
ModulePass *createCanonicalizeMemIntrinsicsPass();
ModulePass *createExpandArithWithOverflowPass();
ModulePass *createExpandByValPass();
ModulePass *createExpandCtorsPass();
ModulePass *createExpandSmallArgumentsPass();
ModulePass *createExpandTlsConstantExprPass();
ModulePass *createExpandTlsPass();
ModulePass *createExpandVarArgsPass();
ModulePass *createFlattenGlobalsPass();
ModulePass *createGlobalCleanupPass();
ModulePass *createPNaClSjLjEHPass();
ModulePass *createReplacePtrsWithIntsPass();
ModulePass *createResolveAliasesPass();
ModulePass *createRewriteAtomicsPass();
ModulePass *createRewriteLLVMIntrinsicsPass();
ModulePass *createRewritePNaClLibraryCallsPass();
ModulePass *createStripAttributesPass();
ModulePass *createStripMetadataPass();

ModulePass *createExpandI64Pass(); // XXX EMSCRIPTEN
ModulePass *createLowerEmExceptionsPass(); // XXX EMSCRIPTEN
ModulePass *createLowerEmSetjmpPass(); // XXX EMSCRIPTEN
ModulePass *createNoExitRuntimePass(); // XXX EMSCRIPTEN

void PNaClABISimplifyAddPreOptPasses(PassManager &PM);
void PNaClABISimplifyAddPostOptPasses(PassManager &PM);

Instruction *PhiSafeInsertPt(Use *U);
void PhiSafeReplaceUses(Use *U, Value *NewVal);

// Copy debug information from Original to NewInst, and return NewInst.
Instruction *CopyDebug(Instruction *NewInst, Instruction *Original);

template <class InstType>
static void CopyLoadOrStoreAttrs(InstType *Dest, InstType *Src) {
  Dest->setVolatile(Src->isVolatile());
  Dest->setAlignment(Src->getAlignment());
  Dest->setOrdering(Src->getOrdering());
  Dest->setSynchScope(Src->getSynchScope());
}

// In order to change a function's type, the function must be
// recreated.  RecreateFunction() recreates Func with type NewType.
// It copies or moves across everything except the argument values,
// which the caller must update because the argument types might be
// different.
Function *RecreateFunction(Function *Func, FunctionType *NewType);

}

#endif
