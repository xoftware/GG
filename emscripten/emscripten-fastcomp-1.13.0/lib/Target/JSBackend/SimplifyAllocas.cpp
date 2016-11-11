//===-- SimplifyAllocas.cpp - TargetMachine for the C++ backend --*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===-----------------------------------------------------------------------===//

#include <OptPasses.h>

#include "llvm/IR/Instruction.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Function.h"

// XXX
#include "llvm/Support/FormattedStream.h"
#include <stdio.h>
#define dump(x) fprintf(stderr, x "\n")
#define dumpv(x, ...) fprintf(stderr, x "\n", __VA_ARGS__)
#define dumpfail(x)       { fprintf(stderr, x "\n");              fprintf(stderr, "%s : %d\n", __FILE__, __LINE__); report_fatal_error("fail"); }
#define dumpfailv(x, ...) { fprintf(stderr, x "\n", __VA_ARGS__); fprintf(stderr, "%s : %d\n", __FILE__, __LINE__); report_fatal_error("fail"); }
#define dumpIR(value) { \
  std::string temp; \
  raw_string_ostream stream(temp); \
  stream << *(value); \
  fprintf(stderr, "%s\n", temp.c_str()); \
}
#undef assert
#define assert(x) { if (!(x)) dumpfail(#x); }
// XXX

namespace llvm {

/*
 * Find cases where an alloca is used only to load and store a single value,
 * even though it is bitcast. Then replace it with a direct alloca of that
 * simple type, and avoid the bitcasts.
 */

struct SimplifyAllocas : public FunctionPass {
  static char ID; // Pass identification, replacement for typeid
  SimplifyAllocas() : FunctionPass(ID) {}
    // XXX initialize..(*PassRegistry::getPassRegistry()); }

  virtual bool runOnFunction(Function &Func);

  virtual const char *getPassName() const { return "SimplifyAllocas"; }
};

char SimplifyAllocas::ID = 0;

bool SimplifyAllocas::runOnFunction(Function &Func) {
  bool Changed = false;
  Type *i32 = Type::getInt32Ty(Func.getContext());
  std::vector<Instruction*> ToRemove; // removing can invalidate our iterators, so do it all at the end
  for (Function::iterator B = Func.begin(), E = Func.end(); B != E; ++B) {
    for (BasicBlock::iterator BI = B->begin(), BE = B->end(); BI != BE; ) {
      Instruction *I = BI++;
      AllocaInst *AI = dyn_cast<AllocaInst>(I);
      if (!AI) continue;
      if (!isa<ConstantInt>(AI->getArraySize())) continue;
      bool Fail = false;
      Type *ActualType = NULL;
      #define CHECK_TYPE(TT) {              \
        Type *T = TT;                       \
        if (!ActualType) {                  \
          ActualType = T;                   \
        } else {                            \
          if (T != ActualType) Fail = true; \
        }                                   \
      }
      std::vector<Instruction*> Aliases; // the bitcasts of this alloca
      for (Instruction::use_iterator UI = AI->use_begin(), UE = AI->use_end(); UI != UE && !Fail; ++UI) {
        Instruction *U = cast<Instruction>(*UI);
        if (U->getOpcode() != Instruction::BitCast) { Fail = true; break; }
        // bitcasting just to do loads and stores is ok
        for (Instruction::use_iterator BUI = U->use_begin(), BUE = U->use_end(); BUI != BUE && !Fail; ++BUI) {
          Instruction *BU = cast<Instruction>(*BUI);
          if (BU->getOpcode() == Instruction::Load) {
            CHECK_TYPE(BU->getType());
            break;
          }
          if (BU->getOpcode() != Instruction::Store) { Fail = true; break; }
          CHECK_TYPE(BU->getOperand(0)->getType());
          if (BU->getOperand(0) == U) { Fail = true; break; }
        }
        if (!Fail) Aliases.push_back(U);
      }
      if (!Fail && Aliases.size() > 0 && ActualType) {
        // success, replace the alloca and the bitcast aliases with a single simple alloca
        AllocaInst *NA = new AllocaInst(ActualType, ConstantInt::get(i32, 1), "", I);
        NA->takeName(AI);
        NA->setAlignment(AI->getAlignment());
        NA->setDebugLoc(AI->getDebugLoc());
        for (unsigned i = 0; i < Aliases.size(); i++) {
          Aliases[i]->replaceAllUsesWith(NA);
          ToRemove.push_back(Aliases[i]);
        }
        ToRemove.push_back(AI);
        Changed = true;
      }
    }
  }
  for (unsigned i = 0; i < ToRemove.size(); i++) {
    ToRemove[i]->eraseFromParent();
  }
  return Changed;
}

//

extern FunctionPass *createSimplifyAllocasPass() {
  return new SimplifyAllocas();
}

} // End llvm namespace

