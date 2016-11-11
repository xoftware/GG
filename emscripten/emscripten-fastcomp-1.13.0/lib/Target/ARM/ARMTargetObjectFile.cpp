//===-- llvm/Target/ARMTargetObjectFile.cpp - ARM Object Info Impl --------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "ARMTargetObjectFile.h"
#include "ARMSubtarget.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/ADT/Triple.h" // @LOCALMOD
#include "llvm/CodeGen/MachineModuleInfo.h" // @LOCALMOD
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCSectionELF.h"
#include "llvm/Support/Dwarf.h"
#include "llvm/Support/ELF.h"
#include "llvm/Target/Mangler.h"
#include "llvm/Target/TargetMachine.h"
using namespace llvm;
using namespace dwarf;

//===----------------------------------------------------------------------===//
//                               ELF Target
//===----------------------------------------------------------------------===//

void ARMElfTargetObjectFile::Initialize(MCContext &Ctx,
                                        const TargetMachine &TM) {
  bool isAAPCS_ABI = TM.getSubtarget<ARMSubtarget>().isAAPCS_ABI();
  TargetLoweringObjectFileELF::Initialize(Ctx, TM);
  InitializeELF(isAAPCS_ABI);

  // @LOCALMOD-BEGIN
  if (isAAPCS_ABI && !TM.getSubtarget<ARMSubtarget>().isTargetNaCl()) {
  // @LOCALMOD-END
    LSDASection = NULL;
  }

  AttributesSection =
    getContext().getELFSection(".ARM.attributes",
                               ELF::SHT_ARM_ATTRIBUTES,
                               0,
                               SectionKind::getMetadata());
}

const MCExpr *ARMElfTargetObjectFile::
getTTypeGlobalReference(const GlobalValue *GV, Mangler *Mang,
                        MachineModuleInfo *MMI, unsigned Encoding,
                        MCStreamer &Streamer) const {
  assert(Encoding == DW_EH_PE_absptr && "Can handle absptr encoding only");
  // @LOCALMOD-BEGIN
  // FIXME: There has got to be a better way to get this info.
  Triple T(MMI->getModule()->getTargetTriple());
  if (T.isOSNaCl())
    return TargetLoweringObjectFileELF::getTTypeGlobalReference(GV, Mang,
                                        MMI, Encoding, Streamer);
  // @LOCALMOD-END
  return MCSymbolRefExpr::Create(Mang->getSymbol(GV),
                                 MCSymbolRefExpr::VK_ARM_TARGET2,
                                 getContext());
}
