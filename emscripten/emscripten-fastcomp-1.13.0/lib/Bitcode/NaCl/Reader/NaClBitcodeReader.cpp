//===- NaClBitcodeReader.cpp ----------------------------------------------===//
//     Internal NaClBitcodeReader implementation
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "NaClBitcodeReader"

#include "llvm/Bitcode/NaCl/NaClReaderWriter.h"
#include "NaClBitcodeReader.h"
#include "llvm/ADT/SmallString.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/AutoUpgrade.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/InlineAsm.h"
#include "llvm/IR/IntrinsicInst.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/OperandTraits.h"
#include "llvm/IR/Operator.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/DataStream.h"
#include "llvm/Support/MathExtras.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/raw_ostream.h"
using namespace llvm;

void NaClBitcodeReader::FreeState() {
  if (BufferOwned)
    delete Buffer;
  Buffer = 0;
  std::vector<Type*>().swap(TypeList);
  ValueList.clear();

  std::vector<Function*>().swap(FunctionsWithBodies);
  DeferredFunctionInfo.clear();
}

//===----------------------------------------------------------------------===//
//  Helper functions to implement forward reference resolution, etc.
//===----------------------------------------------------------------------===//

/// ConvertToString - Convert a string from a record into an std::string, return
/// true on failure.
template<typename StrTy>
static bool ConvertToString(ArrayRef<uint64_t> Record, unsigned Idx,
                            StrTy &Result) {
  if (Idx > Record.size())
    return true;

  for (unsigned i = Idx, e = Record.size(); i != e; ++i)
    Result += (char)Record[i];
  return false;
}

static GlobalValue::LinkageTypes GetDecodedLinkage(unsigned Val) {
  switch (Val) {
  default: // Map unknown/new linkages to external
  case 0:  return GlobalValue::ExternalLinkage;
  case 1:  return GlobalValue::WeakAnyLinkage;
  case 2:  return GlobalValue::AppendingLinkage;
  case 3:  return GlobalValue::InternalLinkage;
  case 4:  return GlobalValue::LinkOnceAnyLinkage;
  case 5:  return GlobalValue::DLLImportLinkage;
  case 6:  return GlobalValue::DLLExportLinkage;
  case 7:  return GlobalValue::ExternalWeakLinkage;
  case 8:  return GlobalValue::CommonLinkage;
  case 9:  return GlobalValue::PrivateLinkage;
  case 10: return GlobalValue::WeakODRLinkage;
  case 11: return GlobalValue::LinkOnceODRLinkage;
  case 12: return GlobalValue::AvailableExternallyLinkage;
  case 13: return GlobalValue::LinkerPrivateLinkage;
  case 14: return GlobalValue::LinkerPrivateWeakLinkage;
  case 15: return GlobalValue::LinkOnceODRAutoHideLinkage;
  }
}

static int GetDecodedCastOpcode(unsigned Val) {
  switch (Val) {
  default: return -1;
  case naclbitc::CAST_TRUNC   : return Instruction::Trunc;
  case naclbitc::CAST_ZEXT    : return Instruction::ZExt;
  case naclbitc::CAST_SEXT    : return Instruction::SExt;
  case naclbitc::CAST_FPTOUI  : return Instruction::FPToUI;
  case naclbitc::CAST_FPTOSI  : return Instruction::FPToSI;
  case naclbitc::CAST_UITOFP  : return Instruction::UIToFP;
  case naclbitc::CAST_SITOFP  : return Instruction::SIToFP;
  case naclbitc::CAST_FPTRUNC : return Instruction::FPTrunc;
  case naclbitc::CAST_FPEXT   : return Instruction::FPExt;
  case naclbitc::CAST_BITCAST : return Instruction::BitCast;
  }
}
static int GetDecodedBinaryOpcode(unsigned Val, Type *Ty) {
  switch (Val) {
  default: return -1;
  case naclbitc::BINOP_ADD:
    return Ty->isFPOrFPVectorTy() ? Instruction::FAdd : Instruction::Add;
  case naclbitc::BINOP_SUB:
    return Ty->isFPOrFPVectorTy() ? Instruction::FSub : Instruction::Sub;
  case naclbitc::BINOP_MUL:
    return Ty->isFPOrFPVectorTy() ? Instruction::FMul : Instruction::Mul;
  case naclbitc::BINOP_UDIV: return Instruction::UDiv;
  case naclbitc::BINOP_SDIV:
    return Ty->isFPOrFPVectorTy() ? Instruction::FDiv : Instruction::SDiv;
  case naclbitc::BINOP_UREM: return Instruction::URem;
  case naclbitc::BINOP_SREM:
    return Ty->isFPOrFPVectorTy() ? Instruction::FRem : Instruction::SRem;
  case naclbitc::BINOP_SHL:  return Instruction::Shl;
  case naclbitc::BINOP_LSHR: return Instruction::LShr;
  case naclbitc::BINOP_ASHR: return Instruction::AShr;
  case naclbitc::BINOP_AND:  return Instruction::And;
  case naclbitc::BINOP_OR:   return Instruction::Or;
  case naclbitc::BINOP_XOR:  return Instruction::Xor;
  }
}

static CallingConv::ID GetDecodedCallingConv(unsigned Val) {
  switch (Val) {
  default:
    report_fatal_error("PNaCl bitcode contains invalid calling conventions.");
  case naclbitc::C_CallingConv: return CallingConv::C;
  }
}

void NaClBitcodeReaderValueList::AssignValue(Value *V, unsigned Idx) {
  assert(V);
  if (Idx == size()) {
    push_back(V);
    return;
  }

  if (Idx >= size())
    resize(Idx+1);

  WeakVH &OldV = ValuePtrs[Idx];
  if (OldV == 0) {
    OldV = V;
    return;
  }

  // If there was a forward reference to this value, replace it.
  Value *PrevVal = OldV;
  OldV->replaceAllUsesWith(V);
  delete PrevVal;
}

void NaClBitcodeReaderValueList::AssignGlobalVar(GlobalVariable *GV,
                                                 unsigned Idx) {
  assert(GV);

  if (Idx == size()) {
    push_back(GV);
    return;
  }

  if (Idx >= size())
    resize(Idx+1);

  WeakVH &OldV = ValuePtrs[Idx];
  if (OldV == 0) {
    OldV = GV;
    return;
  }

  // If there was a forward reference to this value, replace it.
  Value *PrevVal = OldV;
  GlobalVariable *Placeholder = cast<GlobalVariable>(PrevVal);
  Placeholder->replaceAllUsesWith(
      ConstantExpr::getBitCast(GV, Placeholder->getType()));
  Placeholder->eraseFromParent();
  ValuePtrs[Idx] = GV;
}

void NaClBitcodeReaderValueList::OverwriteValue(Value *V, unsigned Idx) {
  ValuePtrs[Idx] = V;
}

Value *NaClBitcodeReaderValueList::getValueFwdRef(unsigned Idx) {
  if (Idx >= size())
    return 0;

  if (Value *V = ValuePtrs[Idx])
    return V;

  return 0;
}

bool NaClBitcodeReaderValueList::createValueFwdRef(unsigned Idx, Type *Ty) {
  if (Idx >= size())
    resize(Idx + 1);

  // Return an error if this a duplicate definition of Idx.
  if (ValuePtrs[Idx])
    return true;

  // No type specified, must be invalid reference.
  if (Ty == 0)
    return true;

  // Create a placeholder, which will later be RAUW'd.
  ValuePtrs[Idx] = new Argument(Ty);
  return false;
}

Constant *NaClBitcodeReaderValueList::getOrCreateGlobalVarRef(
    unsigned Idx, Module *M) {
  // First make sure the element for Idx is defined.
  if (Idx >= size())
    resize(Idx + 1);

  // Now get its value (if applicable).
  if (Value *V = ValuePtrs[Idx])
    return dyn_cast<Constant>(V);

  // Create a placeholder, which will later be RAUW'd.
  Type *PlaceholderType = Type::getInt8Ty(Context);

  Constant *C =
      new GlobalVariable(*M, PlaceholderType, false,
                         GlobalValue::ExternalLinkage, 0);
  ValuePtrs[Idx] = C;
  return C;
}

Type *NaClBitcodeReader::getTypeByID(unsigned ID) {
  // The type table size is always specified correctly.
  if (ID >= TypeList.size())
    return 0;

  if (Type *Ty = TypeList[ID])
    return Ty;

  // If we have a forward reference, the only possible case is when it is to a
  // named struct.  Just create a placeholder for now.
  return TypeList[ID] = StructType::create(Context);
}


//===----------------------------------------------------------------------===//
//  Functions for parsing blocks from the bitcode file
//===----------------------------------------------------------------------===//


bool NaClBitcodeReader::ParseTypeTable() {
  DEBUG(dbgs() << "-> ParseTypeTable\n");
  if (Stream.EnterSubBlock(naclbitc::TYPE_BLOCK_ID_NEW))
    return Error("Malformed block record");

  bool result = ParseTypeTableBody();
  if (!result)
    DEBUG(dbgs() << "<- ParseTypeTable\n");
  return result;
}

bool NaClBitcodeReader::ParseTypeTableBody() {
  if (!TypeList.empty())
    return Error("Multiple TYPE_BLOCKs found!");

  SmallVector<uint64_t, 64> Record;
  unsigned NumRecords = 0;

  // Read all the records for this type table.
  while (1) {
    NaClBitstreamEntry Entry = Stream.advanceSkippingSubblocks();

    switch (Entry.Kind) {
    case NaClBitstreamEntry::SubBlock: // Handled for us already.
    case NaClBitstreamEntry::Error:
      Error("Error in the type table block");
      return true;
    case NaClBitstreamEntry::EndBlock:
      if (NumRecords != TypeList.size())
        return Error("Invalid type forward reference in TYPE_BLOCK");
      return false;
    case NaClBitstreamEntry::Record:
      // The interesting case.
      break;
    }

    // Read a record.
    Record.clear();
    Type *ResultTy = 0;
    unsigned TypeCode = Stream.readRecord(Entry.ID, Record);
    switch (TypeCode) {
    default: {
      std::string Message;
      raw_string_ostream StrM(Message);
      StrM << "Unknown type code in type table: " << TypeCode;
      StrM.flush();
      return Error(Message);
    }
    case naclbitc::TYPE_CODE_NUMENTRY: // TYPE_CODE_NUMENTRY: [numentries]
      // TYPE_CODE_NUMENTRY contains a count of the number of types in the
      // type list.  This allows us to reserve space.
      if (Record.size() < 1)
        return Error("Invalid TYPE_CODE_NUMENTRY record");
      TypeList.resize(Record[0]);
      continue;
    case naclbitc::TYPE_CODE_VOID:      // VOID
      ResultTy = Type::getVoidTy(Context);
      break;
    case naclbitc::TYPE_CODE_FLOAT:     // FLOAT
      ResultTy = Type::getFloatTy(Context);
      break;
    case naclbitc::TYPE_CODE_DOUBLE:    // DOUBLE
      ResultTy = Type::getDoubleTy(Context);
      break;
    case naclbitc::TYPE_CODE_INTEGER:   // INTEGER: [width]
      if (Record.size() < 1)
        return Error("Invalid Integer type record");

      ResultTy = IntegerType::get(Context, Record[0]);
      break;
    case naclbitc::TYPE_CODE_FUNCTION: {
      // FUNCTION: [vararg, retty, paramty x N]
      if (Record.size() < 2)
        return Error("Invalid FUNCTION type record");
      SmallVector<Type*, 8> ArgTys;
      for (unsigned i = 2, e = Record.size(); i != e; ++i) {
        if (Type *T = getTypeByID(Record[i]))
          ArgTys.push_back(T);
        else
          break;
      }

      ResultTy = getTypeByID(Record[1]);
      if (ResultTy == 0 || ArgTys.size() < Record.size()-2)
        return Error("invalid type in function type");

      ResultTy = FunctionType::get(ResultTy, ArgTys, Record[0]);
      break;
    }
    }

    if (NumRecords >= TypeList.size())
      return Error("invalid TYPE table");
    assert(ResultTy && "Didn't read a type?");
    assert(TypeList[NumRecords] == 0 && "Already read type?");
    TypeList[NumRecords++] = ResultTy;
  }
}

bool NaClBitcodeReader::ParseGlobalVars() {
  if (Stream.EnterSubBlock(naclbitc::GLOBALVAR_BLOCK_ID))
    return Error("Malformed block record");

  SmallVector<uint64_t, 64> Record;

  // True when processing a global variable. Stays true until all records
  // are processed, and the global variable is created.
  bool ProcessingGlobal = false;
  // The alignment value defined for the global variable.
  unsigned VarAlignment = 0;
  // True if the variable is read-only.
  bool VarIsConstant = false;
  // The initializer for the global variable.
  SmallVector<Constant *, 10> VarInit;
  // The number of initializers needed for the global variable.
  unsigned VarInitializersNeeded = 0;
  unsigned FirstValueNo = ValueList.size();
  // The index of the next global variable.
  unsigned NextValueNo = FirstValueNo;
  // The number of expected global variable definitions.
  unsigned NumGlobals = 0;

  // Read all global variable records.
  while (1) {
    NaClBitstreamEntry Entry = Stream.advanceSkippingSubblocks();
    switch (Entry.Kind) {
    case NaClBitstreamEntry::SubBlock:
    case NaClBitstreamEntry::Error:
      return Error("Error in the global vars block");
    case NaClBitstreamEntry::EndBlock:
      if (ProcessingGlobal || NumGlobals != (NextValueNo - FirstValueNo))
        return Error("Error in the global vars block");
      return false;
    case NaClBitstreamEntry::Record:
      // The interesting case.
      break;
    }

    // Read a record.
    Record.clear();
    unsigned Bitcode = Stream.readRecord(Entry.ID, Record);
    switch (Bitcode) {
    default: return Error("Unknown global variable entry");
    case naclbitc::GLOBALVAR_VAR:
      // Start the definition of a global variable.
      if (ProcessingGlobal || Record.size() != 2)
        return Error("Bad GLOBALVAR_VAR record");
      ProcessingGlobal = true;
      VarAlignment = (1 << Record[0]) >> 1;
      VarIsConstant = Record[1] != 0;
      // Assume (by default) there is a single initializer.
      VarInitializersNeeded = 1;
      break;
    case naclbitc::GLOBALVAR_COMPOUND:
      // Global variable has multiple initializers. Changes the
      // default number of initializers to the given value in
      // Record[0].
      if (!ProcessingGlobal || !VarInit.empty() ||
          VarInitializersNeeded != 1 || Record.size() != 1)
        return Error("Bad GLOBALVAR_COMPOUND record");
      VarInitializersNeeded = Record[0];
      break;
    case naclbitc::GLOBALVAR_ZEROFILL: {
      // Define an initializer that defines a sequence of zero-filled bytes.
      if (!ProcessingGlobal || Record.size() != 1)
        return Error("Bad GLOBALVAR_ZEROFILL record");
      Type *Ty = ArrayType::get(Type::getInt8Ty(Context), Record[0]);
      Constant *Zero = ConstantAggregateZero::get(Ty);
      VarInit.push_back(Zero);
      break;
    }
    case naclbitc::GLOBALVAR_DATA: {
      // Defines an initializer defined by a sequence of byte values.
      if (!ProcessingGlobal || Record.size() < 1)
        return Error("Bad GLOBALVAR_DATA record");
      unsigned Size = Record.size();
      uint8_t *Buf = new uint8_t[Size];
      assert(Buf);
      for (unsigned i = 0; i < Size; ++i)
        Buf[i] = Record[i];
      Constant *Init = ConstantDataArray::get(
          Context, ArrayRef<uint8_t>(Buf, Buf + Size));
      VarInit.push_back(Init);
      delete[] Buf;
      break;
    }
    case naclbitc::GLOBALVAR_RELOC: {
      // Define a relocation initializer.
      if (!ProcessingGlobal || Record.size() < 1 || Record.size() > 2)
        return Error("Bad GLOBALVAR_RELOC record");
      Constant *BaseVal =
          ValueList.getOrCreateGlobalVarRef(Record[0], TheModule);
      if (BaseVal == 0)
        return Error("Bad base value in GLOBALVAR_RELOC record");
      Type *IntPtrType = IntegerType::get(Context, 32);
      Constant *Val = ConstantExpr::getPtrToInt(BaseVal, IntPtrType);
      if (Record.size() == 2) {
        uint32_t Addend = Record[1];
        Val = ConstantExpr::getAdd(Val, ConstantInt::get(IntPtrType,
                                                         Addend));
      }
      VarInit.push_back(Val);
      break;
    }
    case naclbitc::GLOBALVAR_COUNT:
      if (Record.size() != 1 || NumGlobals != 0)
        return Error("Invalid global count record");
      NumGlobals = Record[0];
      break;
    }

    // If more initializers needed for global variable, continue processing.
    if (!ProcessingGlobal || VarInit.size() < VarInitializersNeeded)
      continue;

    Constant *Init = 0;
    switch (VarInit.size()) {
    case 0:
      return Error("No initializer for global variable in global vars block");
    case 1:
      Init = VarInit[0];
      break;
    default:
      Init = ConstantStruct::getAnon(Context, VarInit, true);
      break;
    }
    GlobalVariable *GV = new GlobalVariable(
        *TheModule, Init->getType(), VarIsConstant,
        GlobalValue::InternalLinkage, Init, "");
    GV->setAlignment(VarAlignment);
    ValueList.AssignGlobalVar(GV, NextValueNo);
    ++NextValueNo;
    ProcessingGlobal = false;
    VarAlignment = 0;
    VarIsConstant = false;
    VarInitializersNeeded = 0;
    VarInit.clear();
  }
}

bool NaClBitcodeReader::ParseValueSymbolTable() {
  DEBUG(dbgs() << "-> ParseValueSymbolTable\n");
  if (Stream.EnterSubBlock(naclbitc::VALUE_SYMTAB_BLOCK_ID))
    return Error("Malformed block record");

  SmallVector<uint64_t, 64> Record;

  // Read all the records for this value table.
  SmallString<128> ValueName;
  while (1) {
    NaClBitstreamEntry Entry = Stream.advanceSkippingSubblocks();

    switch (Entry.Kind) {
    case NaClBitstreamEntry::SubBlock: // Handled for us already.
    case NaClBitstreamEntry::Error:
      return Error("malformed value symbol table block");
    case NaClBitstreamEntry::EndBlock:
      DEBUG(dbgs() << "<- ParseValueSymbolTable\n");
      return false;
    case NaClBitstreamEntry::Record:
      // The interesting case.
      break;
    }

    // Read a record.
    Record.clear();
    switch (Stream.readRecord(Entry.ID, Record)) {
    default:  // Default behavior: unknown type.
      break;
    case naclbitc::VST_CODE_ENTRY: {  // VST_ENTRY: [valueid, namechar x N]
      if (ConvertToString(Record, 1, ValueName))
        return Error("Invalid VST_ENTRY record");
      unsigned ValueID = Record[0];
      if (ValueID >= ValueList.size())
        return Error("Invalid Value ID in VST_ENTRY record");
      Value *V = ValueList[ValueID];

      V->setName(StringRef(ValueName.data(), ValueName.size()));
      ValueName.clear();
      break;
    }
    case naclbitc::VST_CODE_BBENTRY: {
      if (ConvertToString(Record, 1, ValueName))
        return Error("Invalid VST_BBENTRY record");
      BasicBlock *BB = getBasicBlock(Record[0]);
      if (BB == 0)
        return Error("Invalid BB ID in VST_BBENTRY record");

      BB->setName(StringRef(ValueName.data(), ValueName.size()));
      ValueName.clear();
      break;
    }
    }
  }
}

static APInt ReadWideAPInt(ArrayRef<uint64_t> Vals, unsigned TypeBits) {
  SmallVector<uint64_t, 8> Words(Vals.size());
  std::transform(Vals.begin(), Vals.end(), Words.begin(),
                 NaClDecodeSignRotatedValue);

  return APInt(TypeBits, Words);
}

bool NaClBitcodeReader::ParseConstants() {
  DEBUG(dbgs() << "-> ParseConstants\n");
  if (Stream.EnterSubBlock(naclbitc::CONSTANTS_BLOCK_ID))
    return Error("Malformed block record");

  SmallVector<uint64_t, 64> Record;

  // Read all the records for this value table.
  Type *CurTy = Type::getInt32Ty(Context);
  unsigned NextCstNo = ValueList.size();
  while (1) {
    NaClBitstreamEntry Entry = Stream.advanceSkippingSubblocks();

    switch (Entry.Kind) {
    case NaClBitstreamEntry::SubBlock: // Handled for us already.
    case NaClBitstreamEntry::Error:
      return Error("malformed block record in AST file");
    case NaClBitstreamEntry::EndBlock:
      if (NextCstNo != ValueList.size())
        return Error("Invalid constant reference!");
      DEBUG(dbgs() << "<- ParseConstants\n");
      return false;
    case NaClBitstreamEntry::Record:
      // The interesting case.
      break;
    }

    // Read a record.
    Record.clear();
    Value *V = 0;
    unsigned BitCode = Stream.readRecord(Entry.ID, Record);
    switch (BitCode) {
    default: {
      std::string Message;
      raw_string_ostream StrM(Message);
      StrM << "Invalid Constant code: " << BitCode;
      StrM.flush();
      return Error(Message);
    }
    case naclbitc::CST_CODE_UNDEF:     // UNDEF
      V = UndefValue::get(CurTy);
      break;
    case naclbitc::CST_CODE_SETTYPE:   // SETTYPE: [typeid]
      if (Record.empty())
        return Error("Malformed CST_SETTYPE record");
      if (Record[0] >= TypeList.size())
        return Error("Invalid Type ID in CST_SETTYPE record");
      CurTy = TypeList[Record[0]];
      continue;  // Skip the ValueList manipulation.
    case naclbitc::CST_CODE_INTEGER:   // INTEGER: [intval]
      if (!CurTy->isIntegerTy() || Record.empty())
        return Error("Invalid CST_INTEGER record");
      V = ConstantInt::get(CurTy, NaClDecodeSignRotatedValue(Record[0]));
      break;
    case naclbitc::CST_CODE_FLOAT: {    // FLOAT: [fpval]
      if (Record.empty())
        return Error("Invalid FLOAT record");
      if (CurTy->isFloatTy())
        V = ConstantFP::get(Context, APFloat(APFloat::IEEEsingle,
                                             APInt(32, (uint32_t)Record[0])));
      else if (CurTy->isDoubleTy())
        V = ConstantFP::get(Context, APFloat(APFloat::IEEEdouble,
                                             APInt(64, Record[0])));
      else
        return Error("Unknown type for FLOAT record");
      break;
    }
    }

    ValueList.AssignValue(V, NextCstNo);
    ++NextCstNo;
  }
}

/// RememberAndSkipFunctionBody - When we see the block for a function body,
/// remember where it is and then skip it.  This lets us lazily deserialize the
/// functions.
bool NaClBitcodeReader::RememberAndSkipFunctionBody() {
  DEBUG(dbgs() << "-> RememberAndSkipFunctionBody\n");
  // Get the function we are talking about.
  if (FunctionsWithBodies.empty())
    return Error("Insufficient function protos");

  Function *Fn = FunctionsWithBodies.back();
  FunctionsWithBodies.pop_back();

  // Save the current stream state.
  uint64_t CurBit = Stream.GetCurrentBitNo();
  DeferredFunctionInfo[Fn] = CurBit;

  // Skip over the function block for now.
  if (Stream.SkipBlock())
    return Error("Malformed block record");
  DEBUG(dbgs() << "<- RememberAndSkipFunctionBody\n");
  return false;
}

bool NaClBitcodeReader::GlobalCleanup() {
  // Look for intrinsic functions which need to be upgraded at some point
  for (Module::iterator FI = TheModule->begin(), FE = TheModule->end();
       FI != FE; ++FI) {
    Function *NewFn;
    if (UpgradeIntrinsicFunction(FI, NewFn))
      UpgradedIntrinsics.push_back(std::make_pair(FI, NewFn));
  }

  // Look for global variables which need to be renamed.
  for (Module::global_iterator
         GI = TheModule->global_begin(), GE = TheModule->global_end();
       GI != GE; ++GI)
    UpgradeGlobalVariable(GI);
  return false;
}

FunctionType *NaClBitcodeReader::AddPointerTypesToIntrinsicType(
    StringRef Name, FunctionType *FTy) {
  Type *ReturnTy = FTy->getReturnType();
  SmallVector<Type *, 8> ArgTypes(FTy->param_begin(), FTy->param_end());

  // Ideally we wouldn't need a list of supported intrinsics here, but
  // Intrinsic::* doesn't provide a function for recovering the
  // expected type of an intrinsic given its full name.
  // TODO(mseaborn): We could reuse the intrinsic list from
  // PNaClABIVerifyModule.cpp here.
  if (Name == "llvm.nacl.read.tp" ||
      Name == "llvm.stacksave") {
    ReturnTy = Type::getInt8PtrTy(Context);
  } else if (Name == "llvm.nacl.setjmp" ||
             Name == "llvm.nacl.longjmp" ||
             Name == "llvm.stackrestore" ||
             Name.startswith("llvm.memset.")) {
    assert(ArgTypes.size() >= 1);
    ArgTypes[0] = Type::getInt8PtrTy(Context);
  } else if (Name.startswith("llvm.memcpy.") ||
             Name.startswith("llvm.memmove.")) {
    assert(ArgTypes.size() >= 2);
    ArgTypes[0] = Type::getInt8PtrTy(Context);
    ArgTypes[1] = Type::getInt8PtrTy(Context);
  } else if (Name.startswith("llvm.nacl.atomic.load.") ||
             Name.startswith("llvm.nacl.atomic.cmpxchg.")) {
    assert(ArgTypes.size() >= 1);
    ArgTypes[0] = ReturnTy->getPointerTo();
  } else if (Name.startswith("llvm.nacl.atomic.store.")) {
    assert(ArgTypes.size() >= 2);
    ArgTypes[1] = ArgTypes[0]->getPointerTo();
  } else if (Name.startswith("llvm.nacl.atomic.rmw.")) {
    assert(ArgTypes.size() >= 3);
    ArgTypes[1] = ArgTypes[2]->getPointerTo();
  } else if (Name == "llvm.nacl.atomic.is.lock.free") {
    assert(ArgTypes.size() >= 2);
    ArgTypes[1] = Type::getInt8PtrTy(Context);
  }
  return FunctionType::get(ReturnTy, ArgTypes, false);
}

void NaClBitcodeReader::AddPointerTypesToIntrinsicParams() {
  for (unsigned Index = 0, E = ValueList.size(); Index < E; ++Index) {
    if (Function *Func = dyn_cast<Function>(ValueList[Index])) {
      if (Func->isIntrinsic()) {
        FunctionType *FTy = AddPointerTypesToIntrinsicType(
            Func->getName(), Func->getFunctionType());
        Function *NewIntrinsic = Function::Create(
            FTy, GlobalValue::ExternalLinkage, "", TheModule);
        NewIntrinsic->takeName(Func);
        ValueList.OverwriteValue(NewIntrinsic, Index);
        Func->eraseFromParent();
      }
    }
  }
}

bool NaClBitcodeReader::ParseModule(bool Resume) {
  DEBUG(dbgs() << "-> ParseModule\n");
  if (Resume)
    Stream.JumpToBit(NextUnreadBit);
  else if (Stream.EnterSubBlock(naclbitc::MODULE_BLOCK_ID))
    return Error("Malformed block record");

  SmallVector<uint64_t, 64> Record;

  // Read all the records for this module.
  while (1) {
    NaClBitstreamEntry Entry = Stream.advance();

    switch (Entry.Kind) {
    case NaClBitstreamEntry::Error:
      Error("malformed module block");
      return true;
    case NaClBitstreamEntry::EndBlock:
      DEBUG(dbgs() << "<- ParseModule\n");
      return GlobalCleanup();

    case NaClBitstreamEntry::SubBlock:
      switch (Entry.ID) {
      default: {
        std::string Message;
        raw_string_ostream StrM(Message);
        StrM << "Unknown block ID: " << Entry.ID;
        return Error(StrM.str());
      }
      case naclbitc::BLOCKINFO_BLOCK_ID:
        if (Stream.ReadBlockInfoBlock())
          return Error("Malformed BlockInfoBlock");
        break;
      case naclbitc::TYPE_BLOCK_ID_NEW:
        if (ParseTypeTable())
          return true;
        break;
      case naclbitc::GLOBALVAR_BLOCK_ID:
        if (ParseGlobalVars())
          return true;
        break;
      case naclbitc::VALUE_SYMTAB_BLOCK_ID:
        if (ParseValueSymbolTable())
          return true;
        SeenValueSymbolTable = true;
        // Now that we know the names of the intrinsics, we can add
        // pointer types to the intrinsic declarations' types.
        AddPointerTypesToIntrinsicParams();
        break;
      case naclbitc::FUNCTION_BLOCK_ID:
        // If this is the first function body we've seen, reverse the
        // FunctionsWithBodies list.
        if (!SeenFirstFunctionBody) {
          std::reverse(FunctionsWithBodies.begin(), FunctionsWithBodies.end());
          if (GlobalCleanup())
            return true;
          SeenFirstFunctionBody = true;
        }

        if (RememberAndSkipFunctionBody())
          return true;

        // For streaming bitcode, suspend parsing when we reach the function
        // bodies. Subsequent materialization calls will resume it when
        // necessary. For streaming, the function bodies must be at the end of
        // the bitcode. If the bitcode file is old, the symbol table will be
        // at the end instead and will not have been seen yet. In this case,
        // just finish the parse now.
        if (LazyStreamer && SeenValueSymbolTable) {
          NextUnreadBit = Stream.GetCurrentBitNo();
          DEBUG(dbgs() << "<- ParseModule\n");
          return false;
        }
        break;
      }
      continue;

    case NaClBitstreamEntry::Record:
      // The interesting case.
      break;
    }

    // Read a record.
    unsigned Selector = Stream.readRecord(Entry.ID, Record);
    switch (Selector) {
    default: {
      std::string Message;
      raw_string_ostream StrM(Message);
      StrM << "Invalid MODULE_CODE: " << Selector;
      StrM.flush();
      return Error(Message);
    }
    case naclbitc::MODULE_CODE_VERSION: {  // VERSION: [version#]
      if (Record.size() < 1)
        return Error("Malformed MODULE_CODE_VERSION");
      // Only version #1 is supported for PNaCl. Version #0 is not supported.
      unsigned module_version = Record[0];
      if (module_version != 1)
        return Error("Unknown bitstream version!");
      break;
    }
    // FUNCTION:  [type, callingconv, isproto, linkage]
    case naclbitc::MODULE_CODE_FUNCTION: {
      if (Record.size() < 4)
        return Error("Invalid MODULE_CODE_FUNCTION record");
      Type *Ty = getTypeByID(Record[0]);
      if (!Ty) return Error("Invalid MODULE_CODE_FUNCTION record");
      FunctionType *FTy = dyn_cast<FunctionType>(Ty);
      if (!FTy)
        return Error("Function not declared with a function type!");

      Function *Func = Function::Create(FTy, GlobalValue::ExternalLinkage,
                                        "", TheModule);

      Func->setCallingConv(GetDecodedCallingConv(Record[1]));
      bool isProto = Record[2];
      Func->setLinkage(GetDecodedLinkage(Record[3]));
      ValueList.push_back(Func);

      // If this is a function with a body, remember the prototype we are
      // creating now, so that we can match up the body with them later.
      if (!isProto) {
        FunctionsWithBodies.push_back(Func);
        if (LazyStreamer) DeferredFunctionInfo[Func] = 0;
      }
      break;
    }
    }
    Record.clear();
  }
}

bool NaClBitcodeReader::ParseBitcodeInto(Module *M) {
  TheModule = 0;

  // PNaCl does not support different DataLayouts in pexes, so we
  // implicitly set the DataLayout to the following default.
  //
  // This is not usually needed by the backend, but it might be used
  // by IR passes that the PNaCl translator runs.  We set this in the
  // reader rather than in pnacl-llc so that 'opt' will also use the
  // correct DataLayout if it is run on a pexe.
  M->setDataLayout("e-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-"
                   "f32:32:32-f64:64:64-p:32:32:32-v128:32:32");

  if (InitStream()) return true; // InitSream will set the error string.

  // We expect a number of well-defined blocks, though we don't necessarily
  // need to understand them all.
  while (1) {
    if (Stream.AtEndOfStream())
      return false;

    NaClBitstreamEntry Entry =
      Stream.advance(NaClBitstreamCursor::AF_DontAutoprocessAbbrevs);

    switch (Entry.Kind) {
    case NaClBitstreamEntry::Error:
      Error("malformed module file");
      return true;
    case NaClBitstreamEntry::EndBlock:
      return false;

    case NaClBitstreamEntry::SubBlock:
      switch (Entry.ID) {
      case naclbitc::BLOCKINFO_BLOCK_ID:
        if (Stream.ReadBlockInfoBlock())
          return Error("Malformed BlockInfoBlock");
        break;
      case naclbitc::MODULE_BLOCK_ID:
        // Reject multiple MODULE_BLOCK's in a single bitstream.
        if (TheModule)
          return Error("Multiple MODULE_BLOCKs in same stream");
        TheModule = M;
        if (ParseModule(false))
          return true;
        if (LazyStreamer) return false;
        break;
      default:
        if (Stream.SkipBlock())
          return Error("Malformed block record");
        break;
      }
      continue;
    case NaClBitstreamEntry::Record:
      // There should be no records in the top-level of blocks.
      return Error("Invalid record at top-level");
    }
  }
}

// Returns true if error occured installing I into BB.
bool NaClBitcodeReader::InstallInstruction(
    BasicBlock *BB, Instruction *I) {
  // Add instruction to end of current BB.  If there is no current BB, reject
  // this file.
  if (BB == 0) {
    delete I;
    return Error("Invalid instruction with no BB");
  }
  BB->getInstList().push_back(I);
  return false;
}

CastInst *
NaClBitcodeReader::CreateCast(unsigned BBIndex, Instruction::CastOps Op,
                              Type *CT, Value *V, bool DeferInsertion) {
  if (BBIndex >= FunctionBBs.size())
    report_fatal_error("CreateCast on unknown basic block");
  BasicBlockInfo &BBInfo = FunctionBBs[BBIndex];
  NaClBitcodeReaderCast ModeledCast(Op, CT, V);
  CastInst *Cast = BBInfo.CastMap[ModeledCast];
  if (Cast == NULL) {
    Cast = CastInst::Create(Op, V, CT);
    BBInfo.CastMap[ModeledCast] = Cast;
    if (DeferInsertion) {
      BBInfo.PhiCasts.push_back(Cast);
    }
  }
  if (!DeferInsertion && Cast->getParent() == 0) {
    InstallInstruction(BBInfo.BB, Cast);
  }
  return Cast;
}

Value *NaClBitcodeReader::ConvertOpToScalar(Value *Op, unsigned BBIndex,
                                            bool DeferInsertion) {
  if (Op->getType()->isPointerTy()) {
    return CreateCast(BBIndex, Instruction::PtrToInt, IntPtrType, Op,
                      DeferInsertion);
  }
  return Op;
}

Value *NaClBitcodeReader::ConvertOpToType(Value *Op, Type *T,
                                          unsigned BBIndex) {
  Type *OpTy = Op->getType();
  if (OpTy == T) return Op;

  if (OpTy->isPointerTy()) {
    if (T == IntPtrType) {
      return ConvertOpToScalar(Op, BBIndex);
    } else {
      return CreateCast(BBIndex, Instruction::BitCast, T, Op);
    }
  } else if (OpTy == IntPtrType) {
    return CreateCast(BBIndex, Instruction::IntToPtr, T, Op);
  }

  std::string Message;
  raw_string_ostream StrM(Message);
  StrM << "Can't convert " << *Op << " to type " << *T << "\n";
  report_fatal_error(StrM.str());
}

/// ParseFunctionBody - Lazily parse the specified function body block.
bool NaClBitcodeReader::ParseFunctionBody(Function *F) {
  DEBUG(dbgs() << "-> ParseFunctionBody\n");
  if (Stream.EnterSubBlock(naclbitc::FUNCTION_BLOCK_ID))
    return Error("Malformed block record");

  unsigned ModuleValueListSize = ValueList.size();

  // Add all the function arguments to the value table.
  for(Function::arg_iterator I = F->arg_begin(), E = F->arg_end(); I != E; ++I)
    ValueList.push_back(I);

  unsigned NextValueNo = ValueList.size();
  BasicBlock *CurBB = 0;
  unsigned CurBBNo = 0;

  // Read all the records.
  SmallVector<uint64_t, 64> Record;
  while (1) {
    NaClBitstreamEntry Entry = Stream.advance();

    switch (Entry.Kind) {
    case NaClBitstreamEntry::Error:
      return Error("Bitcode error in function block");
    case NaClBitstreamEntry::EndBlock:
      goto OutOfRecordLoop;

    case NaClBitstreamEntry::SubBlock:
      switch (Entry.ID) {
      default:  // Skip unknown content.
        dbgs() << "default skip block\n";
        if (Stream.SkipBlock())
          return Error("Malformed block record");
        break;
      case naclbitc::CONSTANTS_BLOCK_ID:
        if (ParseConstants())
          return true;
        NextValueNo = ValueList.size();
        break;
      case naclbitc::VALUE_SYMTAB_BLOCK_ID:
        if (ParseValueSymbolTable())
          return true;
        break;
      }
      continue;

    case NaClBitstreamEntry::Record:
      // The interesting case.
      break;
    }

    // Read a record.
    Record.clear();
    Instruction *I = 0;
    unsigned BitCode = Stream.readRecord(Entry.ID, Record);
    switch (BitCode) {
    default: {// Default behavior: reject
      std::string Message;
      raw_string_ostream StrM(Message);
      StrM << "Unknown instruction record: <" << BitCode;
      for (unsigned I = 0, E = Record.size(); I != E; ++I) {
        StrM << " " << Record[I];
      }
      StrM << ">";
      return Error(StrM.str());
    }

    case naclbitc::FUNC_CODE_DECLAREBLOCKS:     // DECLAREBLOCKS: [nblocks]
      if (Record.size() < 1 || Record[0] == 0)
        return Error("Invalid DECLAREBLOCKS record");
      // Create all the basic blocks for the function.
      FunctionBBs.resize(Record[0]);
      for (unsigned i = 0, e = FunctionBBs.size(); i != e; ++i) {
        BasicBlockInfo &BBInfo = FunctionBBs[i];
        BBInfo.BB = BasicBlock::Create(Context, "", F);
      }
      CurBB = FunctionBBs.at(0).BB;
      continue;

    case naclbitc::FUNC_CODE_INST_BINOP: {
      // BINOP: [opval, opval, opcode[, flags]]
      unsigned OpNum = 0;
      Value *LHS, *RHS;
      if (popValue(Record, &OpNum, NextValueNo, &LHS) ||
          popValue(Record, &OpNum, NextValueNo, &RHS) ||
          OpNum+1 > Record.size())
        return Error("Invalid BINOP record");

      LHS = ConvertOpToScalar(LHS, CurBBNo);
      RHS = ConvertOpToScalar(RHS, CurBBNo);

      int Opc = GetDecodedBinaryOpcode(Record[OpNum++], LHS->getType());
      if (Opc == -1) return Error("Invalid BINOP record");
      I = BinaryOperator::Create((Instruction::BinaryOps)Opc, LHS, RHS);
      if (OpNum < Record.size()) {
        if (Opc == Instruction::Add ||
            Opc == Instruction::Sub ||
            Opc == Instruction::Mul ||
            Opc == Instruction::Shl) {
          if (Record[OpNum] & (1 << naclbitc::OBO_NO_SIGNED_WRAP))
            cast<BinaryOperator>(I)->setHasNoSignedWrap(true);
          if (Record[OpNum] & (1 << naclbitc::OBO_NO_UNSIGNED_WRAP))
            cast<BinaryOperator>(I)->setHasNoUnsignedWrap(true);
        } else if (Opc == Instruction::SDiv ||
                   Opc == Instruction::UDiv ||
                   Opc == Instruction::LShr ||
                   Opc == Instruction::AShr) {
          if (Record[OpNum] & (1 << naclbitc::PEO_EXACT))
            cast<BinaryOperator>(I)->setIsExact(true);
        } else if (isa<FPMathOperator>(I)) {
          FastMathFlags FMF;
          if (0 != (Record[OpNum] & (1 << naclbitc::FPO_UNSAFE_ALGEBRA)))
            FMF.setUnsafeAlgebra();
          if (0 != (Record[OpNum] & (1 << naclbitc::FPO_NO_NANS)))
            FMF.setNoNaNs();
          if (0 != (Record[OpNum] & (1 << naclbitc::FPO_NO_INFS)))
            FMF.setNoInfs();
          if (0 != (Record[OpNum] & (1 << naclbitc::FPO_NO_SIGNED_ZEROS)))
            FMF.setNoSignedZeros();
          if (0 != (Record[OpNum] & (1 << naclbitc::FPO_ALLOW_RECIPROCAL)))
            FMF.setAllowReciprocal();
          if (FMF.any())
            I->setFastMathFlags(FMF);
        }

      }
      break;
    }
    case naclbitc::FUNC_CODE_INST_CAST: {    // CAST: [opval, destty, castopc]
      unsigned OpNum = 0;
      Value *Op;
      if (popValue(Record, &OpNum, NextValueNo, &Op) ||
          OpNum+2 != Record.size())
        return Error("Invalid CAST record: bad record size");

      Type *ResTy = getTypeByID(Record[OpNum]);
      if (ResTy == 0)
        return Error("Invalid CAST record: bad type ID");
      int Opc = GetDecodedCastOpcode(Record[OpNum+1]);
      if (Opc == -1)
        return Error("Invalid CAST record: bad opcode");

      // If a ptrtoint cast was elided on the argument of the cast,
      // add it back. Note: The casts allowed here should match the
      // casts in NaClValueEnumerator::ExpectsScalarValue.
      switch (Opc) {
      case Instruction::Trunc:
      case Instruction::ZExt:
      case Instruction::SExt:
      case Instruction::UIToFP:
      case Instruction::SIToFP:
        Op = ConvertOpToScalar(Op, CurBBNo);
        break;
      default:
        break;
      }

      I = CastInst::Create((Instruction::CastOps)Opc, Op, ResTy);
      break;
    }

    case naclbitc::FUNC_CODE_INST_VSELECT: {// VSELECT: [opval, opval, pred]
      // new form of select
      // handles select i1 or select [N x i1]
      unsigned OpNum = 0;
      Value *TrueVal, *FalseVal, *Cond;
      if (popValue(Record, &OpNum, NextValueNo, &TrueVal) ||
          popValue(Record, &OpNum, NextValueNo, &FalseVal) ||
          popValue(Record, &OpNum, NextValueNo, &Cond))
        return Error("Invalid SELECT record");

      TrueVal = ConvertOpToScalar(TrueVal, CurBBNo);
      FalseVal = ConvertOpToScalar(FalseVal, CurBBNo);

      // expect i1
      if (Cond->getType() != Type::getInt1Ty(Context))
        return Error("Invalid SELECT condition type");

      I = SelectInst::Create(Cond, TrueVal, FalseVal);
      break;
    }

    case naclbitc::FUNC_CODE_INST_CMP2: { // CMP2: [opval, opval, pred]
      // FCmp/ICmp returning bool or vector of bool

      unsigned OpNum = 0;
      Value *LHS, *RHS;
      if (popValue(Record, &OpNum, NextValueNo, &LHS) ||
          popValue(Record, &OpNum, NextValueNo, &RHS) ||
          OpNum+1 != Record.size())
        return Error("Invalid CMP record");

      LHS = ConvertOpToScalar(LHS, CurBBNo);
      RHS = ConvertOpToScalar(RHS, CurBBNo);

      if (LHS->getType()->isFPOrFPVectorTy())
        I = new FCmpInst((FCmpInst::Predicate)Record[OpNum], LHS, RHS);
      else
        I = new ICmpInst((ICmpInst::Predicate)Record[OpNum], LHS, RHS);
      break;
    }

    case naclbitc::FUNC_CODE_INST_RET: // RET: [opval<optional>]
      {
        unsigned Size = Record.size();
        if (Size == 0) {
          I = ReturnInst::Create(Context);
          break;
        }

        unsigned OpNum = 0;
        Value *Op = NULL;
        if (popValue(Record, &OpNum, NextValueNo, &Op))
          return Error("Invalid RET record");
        if (OpNum != Record.size())
          return Error("Invalid RET record");

        I = ReturnInst::Create(Context, ConvertOpToScalar(Op, CurBBNo));
        break;
      }
    case naclbitc::FUNC_CODE_INST_BR: { // BR: [bb#, bb#, opval] or [bb#]
      if (Record.size() != 1 && Record.size() != 3)
        return Error("Invalid BR record");
      BasicBlock *TrueDest = getBasicBlock(Record[0]);
      if (TrueDest == 0)
        return Error("Invalid BR record");

      if (Record.size() == 1) {
        I = BranchInst::Create(TrueDest);
      }
      else {
        BasicBlock *FalseDest = getBasicBlock(Record[1]);
        Value *Cond = getValue(Record, 2, NextValueNo);
        if (FalseDest == 0 || Cond == 0)
          return Error("Invalid BR record");
        I = BranchInst::Create(TrueDest, FalseDest, Cond);
      }
      break;
    }
    case naclbitc::FUNC_CODE_INST_SWITCH: { // SWITCH: [opty, op0, op1, ...]
      // New SwitchInst format with case ranges.
      if (Record.size() < 4)
        return Error("Invalid SWITCH record");
      Type *OpTy = getTypeByID(Record[0]);
      unsigned ValueBitWidth = cast<IntegerType>(OpTy)->getBitWidth();

      Value *Cond = getValue(Record, 1, NextValueNo);
      BasicBlock *Default = getBasicBlock(Record[2]);
      if (OpTy == 0 || Cond == 0 || Default == 0)
        return Error("Invalid SWITCH record");

      unsigned NumCases = Record[3];

      SwitchInst *SI = SwitchInst::Create(Cond, Default, NumCases);

      unsigned CurIdx = 4;
      for (unsigned i = 0; i != NumCases; ++i) {
        IntegersSubsetToBB CaseBuilder;
        unsigned NumItems = Record[CurIdx++];
        for (unsigned ci = 0; ci != NumItems; ++ci) {
          bool isSingleNumber = Record[CurIdx++];

          APInt Low;
          unsigned ActiveWords = 1;
          if (ValueBitWidth > 64)
            ActiveWords = Record[CurIdx++];
          Low = ReadWideAPInt(makeArrayRef(&Record[CurIdx], ActiveWords),
                              ValueBitWidth);
          CurIdx += ActiveWords;

          if (!isSingleNumber) {
            ActiveWords = 1;
            if (ValueBitWidth > 64)
              ActiveWords = Record[CurIdx++];
            APInt High =
                ReadWideAPInt(makeArrayRef(&Record[CurIdx], ActiveWords),
                              ValueBitWidth);

            CaseBuilder.add(IntItem::fromType(OpTy, Low),
                            IntItem::fromType(OpTy, High));
            CurIdx += ActiveWords;
          } else
            CaseBuilder.add(IntItem::fromType(OpTy, Low));
        }
        BasicBlock *DestBB = getBasicBlock(Record[CurIdx++]);
        IntegersSubset Case = CaseBuilder.getCase();
        SI->addCase(Case, DestBB);
      }
      I = SI;
      break;
    }
    case naclbitc::FUNC_CODE_INST_UNREACHABLE: // UNREACHABLE
      I = new UnreachableInst(Context);
      break;
    case naclbitc::FUNC_CODE_INST_PHI: { // PHI: [ty, val0,bb0, ...]
      if (Record.size() < 1 || ((Record.size()-1)&1))
        return Error("Invalid PHI record");
      Type *Ty = getTypeByID(Record[0]);
      if (!Ty) return Error("Invalid PHI record");

      PHINode *PN = PHINode::Create(Ty, (Record.size()-1)/2);

      for (unsigned i = 0, e = Record.size()-1; i != e; i += 2) {
        Value *V;
        // With relative value IDs, it is possible that operands have
        // negative IDs (for forward references).  Use a signed VBR
        // representation to keep the encoding small.
        V = getValueSigned(Record, 1+i, NextValueNo);
        unsigned BBIndex = Record[2+i];
        BasicBlock *BB = getBasicBlock(BBIndex);
        if (!V || !BB) return Error("Invalid PHI record");
        if (Ty == IntPtrType) {
          // Delay installing scalar casts until all instructions of
          // the function are rendered. This guarantees that we insert
          // the conversion just before the incoming edge (or use an
          // existing conversion if already installed).
          V = ConvertOpToScalar(V, BBIndex, /* DeferInsertion = */ true);
        }
        PN->addIncoming(V, BB);
      }
      I = PN;
      break;
    }

    case naclbitc::FUNC_CODE_INST_ALLOCA: { // ALLOCA: [op, align]
      if (Record.size() != 2)
        return Error("Invalid ALLOCA record");
      Value *Size;
      unsigned OpNum = 0;
      if (popValue(Record, &OpNum, NextValueNo, &Size))
        return Error("Invalid ALLOCA record");
      unsigned Align = Record[1];
      I = new AllocaInst(Type::getInt8Ty(Context), Size, (1 << Align) >> 1);
      break;
    }
    case naclbitc::FUNC_CODE_INST_LOAD: {
      // LOAD: [op, align, ty]
      unsigned OpNum = 0;
      Value *Op;
      if (popValue(Record, &OpNum, NextValueNo, &Op) ||
          Record.size() != 3)
        return Error("Invalid LOAD record");

      // Add pointer cast to op.
      Type *T = getTypeByID(Record[2]);
      if (T == 0)
        return Error("Invalid type for load instruction");
      Op = ConvertOpToType(Op, T->getPointerTo(), CurBBNo);
      if (Op == 0) return true;
      I = new LoadInst(Op, "", false, (1 << Record[OpNum]) >> 1);
      break;
    }
    case naclbitc::FUNC_CODE_INST_STORE: {
      // STORE: [ptr, val, align]
      unsigned OpNum = 0;
      Value *Val, *Ptr;
      if (popValue(Record, &OpNum, NextValueNo, &Ptr) ||
          popValue(Record, &OpNum, NextValueNo, &Val))
        return Error("Invalid STORE record");
      if (OpNum+1 != Record.size())
        return Error("Invalid STORE record");
      Val = ConvertOpToScalar(Val, CurBBNo);
      Ptr = ConvertOpToType(Ptr, Val->getType()->getPointerTo(), CurBBNo);
      I = new StoreInst(Val, Ptr, false, (1 << Record[OpNum]) >> 1);
      break;
    }
    case naclbitc::FUNC_CODE_INST_CALL:
    case naclbitc::FUNC_CODE_INST_CALL_INDIRECT: {
      // CALL: [cc, fnid, arg0, arg1...]
      // CALL_INDIRECT: [cc, fnid, fnty, args...]
      if ((Record.size() < 2) ||
          (BitCode == naclbitc::FUNC_CODE_INST_CALL_INDIRECT &&
           Record.size() < 3))
        return Error("Invalid CALL record");

      unsigned CCInfo = Record[0];

      unsigned OpNum = 1;
      Value *Callee;
      if (popValue(Record, &OpNum, NextValueNo, &Callee))
        return Error("Invalid CALL record");

      // Build function type for call.
      FunctionType *FTy = 0;
      Type *ReturnType = 0;
      if (BitCode == naclbitc::FUNC_CODE_INST_CALL_INDIRECT) {
        // Callee type has been elided, add back in.
        ReturnType = getTypeByID(Record[2]);
        ++OpNum;
      } else {
        // Get type signature from callee.
        if (PointerType *OpTy = dyn_cast<PointerType>(Callee->getType())) {
          FTy = dyn_cast<FunctionType>(OpTy->getElementType());
        }
        if (FTy == 0)
          return Error("Invalid type for CALL record");
      }

      unsigned NumParams = Record.size() - OpNum;
      if (FTy && NumParams != FTy->getNumParams())
        return Error("Invalid CALL record");

      // Process call arguments.
      SmallVector<Value*, 6> Args;
      for (unsigned Index = 0; Index < NumParams; ++Index) {
        Value *Arg;
        if (popValue(Record, &OpNum, NextValueNo, &Arg))
          Error("Invalid argument in CALL record");
        if (FTy) {
          // Add a cast, to a pointer type if necessary, in case this
          // is an intrinsic call that takes a pointer argument.
          Arg = ConvertOpToType(Arg, FTy->getParamType(Index), CurBBNo);
        } else {
          Arg = ConvertOpToScalar(Arg, CurBBNo);
        }
        Args.push_back(Arg);
      }

      if (FTy == 0) {
        // Reconstruct the function type and cast the function pointer
        // to it.
        SmallVector<Type*, 6> ArgTypes;
        for (unsigned Index = 0; Index < NumParams; ++Index)
          ArgTypes.push_back(Args[Index]->getType());
        FTy = FunctionType::get(ReturnType, ArgTypes, false);
        Callee = ConvertOpToType(Callee, FTy->getPointerTo(), CurBBNo);
      }

      // Construct call.
      I = CallInst::Create(Callee, Args);
      cast<CallInst>(I)->setCallingConv(GetDecodedCallingConv(CCInfo>>1));
      cast<CallInst>(I)->setTailCall(CCInfo & 1);
      break;
    }
    case naclbitc::FUNC_CODE_INST_FORWARDTYPEREF:
      // Build corresponding forward reference.
      if (Record.size() != 2 ||
          ValueList.createValueFwdRef(Record[0], getTypeByID(Record[1])))
        return Error("Invalid FORWARDTYPEREF record");
      continue;
    }

    if (InstallInstruction(CurBB, I))
      return true;

    // If this was a terminator instruction, move to the next block.
    if (isa<TerminatorInst>(I)) {
      ++CurBBNo;
      CurBB = getBasicBlock(CurBBNo);
    }

    // Non-void values get registered in the value table for future use.
    if (I && !I->getType()->isVoidTy()) {
      Value *NewVal = I;
      if (NewVal->getType()->isPointerTy() &&
          ValueList.getValueFwdRef(NextValueNo)) {
        // Forward-referenced values cannot have pointer type.
        NewVal = ConvertOpToScalar(NewVal, CurBBNo);
      }
      ValueList.AssignValue(NewVal, NextValueNo++);
    }
  }

OutOfRecordLoop:

  // Add PHI conversions to corresponding incoming block, if not
  // already in the block. Also clear all conversions after fixing
  // PHI conversions.
  for (unsigned I = 0, NumBBs = FunctionBBs.size(); I < NumBBs; ++I) {
    BasicBlockInfo &BBInfo = FunctionBBs[I];
    std::vector<CastInst*> &PhiCasts = BBInfo.PhiCasts;
    for (std::vector<CastInst*>::iterator Iter = PhiCasts.begin(),
           IterEnd = PhiCasts.end(); Iter != IterEnd; ++Iter) {
      CastInst *Cast = *Iter;
      if (Cast->getParent() == 0) {
        BasicBlock *BB = BBInfo.BB;
        BB->getInstList().insert(BB->getTerminator(), Cast);
      }
    }
    PhiCasts.clear();
    BBInfo.CastMap.clear();
  }

  // Check the function list for unresolved values.
  if (Argument *A = dyn_cast<Argument>(ValueList.back())) {
    if (A->getParent() == 0) {
      // We found at least one unresolved value.  Nuke them all to avoid leaks.
      for (unsigned i = ModuleValueListSize, e = ValueList.size(); i != e; ++i){
        if ((A = dyn_cast<Argument>(ValueList[i])) && A->getParent() == 0) {
          A->replaceAllUsesWith(UndefValue::get(A->getType()));
          delete A;
        }
      }
      return Error("Never resolved value found in function!");
    }
  }

  // Trim the value list down to the size it was before we parsed this function.
  ValueList.shrinkTo(ModuleValueListSize);
  FunctionBBs.clear();
  DEBUG(dbgs() << "-> ParseFunctionBody\n");
  return false;
}

/// FindFunctionInStream - Find the function body in the bitcode stream
bool NaClBitcodeReader::FindFunctionInStream(Function *F,
       DenseMap<Function*, uint64_t>::iterator DeferredFunctionInfoIterator) {
  while (DeferredFunctionInfoIterator->second == 0) {
    if (Stream.AtEndOfStream())
      return Error("Could not find Function in stream");
    // ParseModule will parse the next body in the stream and set its
    // position in the DeferredFunctionInfo map.
    if (ParseModule(true)) return true;
  }
  return false;
}

//===----------------------------------------------------------------------===//
// GVMaterializer implementation
//===----------------------------------------------------------------------===//


bool NaClBitcodeReader::isMaterializable(const GlobalValue *GV) const {
  if (const Function *F = dyn_cast<Function>(GV)) {
    return F->isDeclaration() &&
      DeferredFunctionInfo.count(const_cast<Function*>(F));
  }
  return false;
}

bool NaClBitcodeReader::Materialize(GlobalValue *GV, std::string *ErrInfo) {
  Function *F = dyn_cast<Function>(GV);
  // If it's not a function or is already material, ignore the request.
  if (!F || !F->isMaterializable()) return false;

  DenseMap<Function*, uint64_t>::iterator DFII = DeferredFunctionInfo.find(F);
  assert(DFII != DeferredFunctionInfo.end() && "Deferred function not found!");
  // If its position is recorded as 0, its body is somewhere in the stream
  // but we haven't seen it yet.
  if (DFII->second == 0)
    if (LazyStreamer && FindFunctionInStream(F, DFII)) return true;

  // Move the bit stream to the saved position of the deferred function body.
  Stream.JumpToBit(DFII->second);

  if (ParseFunctionBody(F)) {
    if (ErrInfo) *ErrInfo = ErrorString;
    return true;
  }

  // Upgrade any old intrinsic calls in the function.
  for (UpgradedIntrinsicMap::iterator I = UpgradedIntrinsics.begin(),
       E = UpgradedIntrinsics.end(); I != E; ++I) {
    if (I->first != I->second) {
      for (Value::use_iterator UI = I->first->use_begin(),
           UE = I->first->use_end(); UI != UE; ) {
        if (CallInst* CI = dyn_cast<CallInst>(*UI++))
          UpgradeIntrinsicCall(CI, I->second);
      }
    }
  }

  return false;
}

bool NaClBitcodeReader::isDematerializable(const GlobalValue *GV) const {
  const Function *F = dyn_cast<Function>(GV);
  if (!F || F->isDeclaration())
    return false;
  return DeferredFunctionInfo.count(const_cast<Function*>(F));
}

void NaClBitcodeReader::Dematerialize(GlobalValue *GV) {
  Function *F = dyn_cast<Function>(GV);
  // If this function isn't dematerializable, this is a noop.
  if (!F || !isDematerializable(F))
    return;

  assert(DeferredFunctionInfo.count(F) && "No info to read function later?");

  // Just forget the function body, we can remat it later.
  F->deleteBody();
}


bool NaClBitcodeReader::MaterializeModule(Module *M, std::string *ErrInfo) {
  assert(M == TheModule &&
         "Can only Materialize the Module this NaClBitcodeReader is attached to.");
  // Iterate over the module, deserializing any functions that are still on
  // disk.
  for (Module::iterator F = TheModule->begin(), E = TheModule->end();
       F != E; ++F)
    if (F->isMaterializable() &&
        Materialize(F, ErrInfo))
      return true;

  // At this point, if there are any function bodies, the current bit is
  // pointing to the END_BLOCK record after them. Now make sure the rest
  // of the bits in the module have been read.
  if (NextUnreadBit)
    ParseModule(true);

  // Upgrade any intrinsic calls that slipped through (should not happen!) and
  // delete the old functions to clean up. We can't do this unless the entire
  // module is materialized because there could always be another function body
  // with calls to the old function.
  for (std::vector<std::pair<Function*, Function*> >::iterator I =
       UpgradedIntrinsics.begin(), E = UpgradedIntrinsics.end(); I != E; ++I) {
    if (I->first != I->second) {
      for (Value::use_iterator UI = I->first->use_begin(),
           UE = I->first->use_end(); UI != UE; ) {
        if (CallInst* CI = dyn_cast<CallInst>(*UI++))
          UpgradeIntrinsicCall(CI, I->second);
      }
      if (!I->first->use_empty())
        I->first->replaceAllUsesWith(I->second);
      I->first->eraseFromParent();
    }
  }
  std::vector<std::pair<Function*, Function*> >().swap(UpgradedIntrinsics);

  return false;
}

bool NaClBitcodeReader::InitStream() {
  if (LazyStreamer) return InitLazyStream();
  return InitStreamFromBuffer();
}

bool NaClBitcodeReader::InitStreamFromBuffer() {
  const unsigned char *BufPtr = (const unsigned char*)Buffer->getBufferStart();
  const unsigned char *BufEnd = BufPtr+Buffer->getBufferSize();

  if (Buffer->getBufferSize() & 3)
    return Error("Bitcode stream should be a multiple of 4 bytes in length");

  if (Header.Read(BufPtr, BufEnd))
    return Error(Header.Unsupported());

  StreamFile.reset(new NaClBitstreamReader(BufPtr, BufEnd));
  Stream.init(*StreamFile);

  if (AcceptHeader())
    return Error(Header.Unsupported());
  return false;
}

bool NaClBitcodeReader::InitLazyStream() {
  StreamingMemoryObject *Bytes = new StreamingMemoryObject(LazyStreamer);
  if (Header.Read(Bytes))
    return Error(Header.Unsupported());

  StreamFile.reset(new NaClBitstreamReader(Bytes, Header.getHeaderSize()));
  Stream.init(*StreamFile);
  if (AcceptHeader())
    return Error(Header.Unsupported());
  return false;
}

//===----------------------------------------------------------------------===//
// External interface
//===----------------------------------------------------------------------===//

/// getNaClLazyBitcodeModule - lazy function-at-a-time loading from a file.
///
Module *llvm::getNaClLazyBitcodeModule(MemoryBuffer *Buffer,
                                       LLVMContext& Context,
                                       std::string *ErrMsg,
                                       bool AcceptSupportedOnly) {
  Module *M = new Module(Buffer->getBufferIdentifier(), Context);
  NaClBitcodeReader *R =
      new NaClBitcodeReader(Buffer, Context, AcceptSupportedOnly);
  M->setMaterializer(R);
  if (R->ParseBitcodeInto(M)) {
    if (ErrMsg)
      *ErrMsg = R->getErrorString();

    delete M;  // Also deletes R.
    return 0;
  }
  // Have the NaClBitcodeReader dtor delete 'Buffer'.
  R->setBufferOwned(true);

  return M;
}


Module *llvm::getNaClStreamedBitcodeModule(const std::string &name,
                                           DataStreamer *streamer,
                                           LLVMContext &Context,
                                           std::string *ErrMsg,
                                           bool AcceptSupportedOnly) {
  Module *M = new Module(name, Context);
  NaClBitcodeReader *R =
      new NaClBitcodeReader(streamer, Context, AcceptSupportedOnly);
  M->setMaterializer(R);
  if (R->ParseBitcodeInto(M)) {
    if (ErrMsg)
      *ErrMsg = R->getErrorString();
    delete M;  // Also deletes R.
    return 0;
  }
  R->setBufferOwned(false); // no buffer to delete

  return M;
}

/// NaClParseBitcodeFile - Read the specified bitcode file, returning the module.
/// If an error occurs, return null and fill in *ErrMsg if non-null.
Module *llvm::NaClParseBitcodeFile(MemoryBuffer *Buffer, LLVMContext& Context,
                                   std::string *ErrMsg,
                                   bool AcceptSupportedOnly){
  Module *M = getNaClLazyBitcodeModule(Buffer, Context, ErrMsg,
                                       AcceptSupportedOnly);
  if (!M) return 0;

  // Don't let the NaClBitcodeReader dtor delete 'Buffer', regardless of whether
  // there was an error.
  static_cast<NaClBitcodeReader*>(M->getMaterializer())->setBufferOwned(false);

  // Read in the entire module, and destroy the NaClBitcodeReader.
  if (M->MaterializeAllPermanently(ErrMsg)) {
    delete M;
    return 0;
  }

  // TODO: Restore the use-lists to the in-memory state when the bitcode was
  // written.  We must defer until the Module has been fully materialized.

  return M;
}
