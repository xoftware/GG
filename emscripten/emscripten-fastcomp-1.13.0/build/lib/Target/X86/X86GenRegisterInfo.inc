/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*Target Register Enum Values                                                 *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_ENUM
#undef GET_REGINFO_ENUM
namespace llvm {

class MCRegisterClass;
extern const MCRegisterClass X86MCRegisterClasses[];

namespace X86 {
enum {
  NoRegister,
  AH = 1,
  AL = 2,
  AX = 3,
  BH = 4,
  BL = 5,
  BP = 6,
  BPL = 7,
  BX = 8,
  CH = 9,
  CL = 10,
  CR0 = 11,
  CR1 = 12,
  CR2 = 13,
  CR3 = 14,
  CR4 = 15,
  CR5 = 16,
  CR6 = 17,
  CR7 = 18,
  CR8 = 19,
  CR9 = 20,
  CR10 = 21,
  CR11 = 22,
  CR12 = 23,
  CR13 = 24,
  CR14 = 25,
  CR15 = 26,
  CS = 27,
  CX = 28,
  DH = 29,
  DI = 30,
  DIL = 31,
  DL = 32,
  DR0 = 33,
  DR1 = 34,
  DR2 = 35,
  DR3 = 36,
  DR4 = 37,
  DR5 = 38,
  DR6 = 39,
  DR7 = 40,
  DS = 41,
  DX = 42,
  EAX = 43,
  EBP = 44,
  EBX = 45,
  ECX = 46,
  EDI = 47,
  EDX = 48,
  EFLAGS = 49,
  EIP = 50,
  EIZ = 51,
  ES = 52,
  ESI = 53,
  ESP = 54,
  FP0 = 55,
  FP1 = 56,
  FP2 = 57,
  FP3 = 58,
  FP4 = 59,
  FP5 = 60,
  FP6 = 61,
  FPSW = 62,
  FS = 63,
  GS = 64,
  IP = 65,
  MM0 = 66,
  MM1 = 67,
  MM2 = 68,
  MM3 = 69,
  MM4 = 70,
  MM5 = 71,
  MM6 = 72,
  MM7 = 73,
  PSEUDO_NACL_SEG = 74,
  R8 = 75,
  R8B = 76,
  R8D = 77,
  R8W = 78,
  R9 = 79,
  R9B = 80,
  R9D = 81,
  R9W = 82,
  R10 = 83,
  R10B = 84,
  R10D = 85,
  R10W = 86,
  R11 = 87,
  R11B = 88,
  R11D = 89,
  R11W = 90,
  R12 = 91,
  R12B = 92,
  R12D = 93,
  R12W = 94,
  R13 = 95,
  R13B = 96,
  R13D = 97,
  R13W = 98,
  R14 = 99,
  R14B = 100,
  R14D = 101,
  R14W = 102,
  R15 = 103,
  R15B = 104,
  R15D = 105,
  R15W = 106,
  RAX = 107,
  RBP = 108,
  RBX = 109,
  RCX = 110,
  RDI = 111,
  RDX = 112,
  RIP = 113,
  RIZ = 114,
  RSI = 115,
  RSP = 116,
  SI = 117,
  SIL = 118,
  SP = 119,
  SPL = 120,
  SS = 121,
  ST0 = 122,
  ST1 = 123,
  ST2 = 124,
  ST3 = 125,
  ST4 = 126,
  ST5 = 127,
  ST6 = 128,
  ST7 = 129,
  XMM0 = 130,
  XMM1 = 131,
  XMM2 = 132,
  XMM3 = 133,
  XMM4 = 134,
  XMM5 = 135,
  XMM6 = 136,
  XMM7 = 137,
  XMM8 = 138,
  XMM9 = 139,
  XMM10 = 140,
  XMM11 = 141,
  XMM12 = 142,
  XMM13 = 143,
  XMM14 = 144,
  XMM15 = 145,
  YMM0 = 146,
  YMM1 = 147,
  YMM2 = 148,
  YMM3 = 149,
  YMM4 = 150,
  YMM5 = 151,
  YMM6 = 152,
  YMM7 = 153,
  YMM8 = 154,
  YMM9 = 155,
  YMM10 = 156,
  YMM11 = 157,
  YMM12 = 158,
  YMM13 = 159,
  YMM14 = 160,
  YMM15 = 161,
  NUM_TARGET_REGS 	// 162
};
}

// Register classes
namespace X86 {
enum {
  GR8RegClassID = 0,
  GR8_NOREXRegClassID = 1,
  GR8_ABCD_HRegClassID = 2,
  GR8_ABCD_LRegClassID = 3,
  GR16RegClassID = 4,
  GR16_NOREXRegClassID = 5,
  SEGMENT_REGRegClassID = 6,
  GR16_ABCDRegClassID = 7,
  FPCCRRegClassID = 8,
  FR32RegClassID = 9,
  GR32RegClassID = 10,
  GR32_NOAXRegClassID = 11,
  GR32_NOSPRegClassID = 12,
  GR32_NOAX_and_GR32_NOSPRegClassID = 13,
  DEBUG_REGRegClassID = 14,
  GR32_NOREXRegClassID = 15,
  GR32_TC_64RegClassID = 16,
  GR32_NOAX_and_GR32_NOREXRegClassID = 17,
  GR32_NOAX_and_GR32_TC_64RegClassID = 18,
  GR32_NOREX_NOSPRegClassID = 19,
  RFP32RegClassID = 20,
  GR32_NOAX_and_GR32_NOREX_NOSPRegClassID = 21,
  GR32_NOREX_and_GR32_TC_64RegClassID = 22,
  GR32_ABCDRegClassID = 23,
  GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64RegClassID = 24,
  GR32_ABCD_and_GR32_NOAXRegClassID = 25,
  GR32_TCRegClassID = 26,
  GR32_ADRegClassID = 27,
  GR32_NOAX_and_GR32_TCRegClassID = 28,
  CCRRegClassID = 29,
  GR32_AD_and_GR32_NOAXRegClassID = 30,
  RFP64RegClassID = 31,
  GR64RegClassID = 32,
  CONTROL_REGRegClassID = 33,
  FR64RegClassID = 34,
  GR64_with_sub_8bitRegClassID = 35,
  GR64_NOSPRegClassID = 36,
  GR64_with_sub_32bit_in_GR32_NOAXRegClassID = 37,
  GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSPRegClassID = 38,
  GR64_NOREXRegClassID = 39,
  GR64_TCRegClassID = 40,
  GR64_with_sub_16bit_in_GR16_NOREXRegClassID = 41,
  GR64_with_sub_32bit_in_GR32_TC_64RegClassID = 42,
  VR64RegClassID = 43,
  GR64_NOREX_NOSPRegClassID = 44,
  GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREXRegClassID = 45,
  GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64RegClassID = 46,
  GR64_NOREX_and_GR64_TCRegClassID = 47,
  GR64_TCW64RegClassID = 48,
  GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSPRegClassID = 49,
  GR64_TCW64_and_GR64_with_sub_32bit_in_GR32_NOAXRegClassID = 50,
  GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64RegClassID = 51,
  GR64_ABCDRegClassID = 52,
  GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64RegClassID = 53,
  GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAXRegClassID = 54,
  GR64_with_sub_32bit_in_GR32_TCRegClassID = 55,
  GR64_with_sub_32bit_in_GR32_ADRegClassID = 56,
  GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TCRegClassID = 57,
  GR64_with_sub_32bit_in_GR32_AD_and_GR32_NOAXRegClassID = 58,
  RSTRegClassID = 59,
  RFP80RegClassID = 60,
  VR128RegClassID = 61,
  VR256RegClassID = 62
  };
}

// Subregister indices
namespace X86 {
enum {
  NoSubRegister,
  sub_8bit,	// 1
  sub_8bit_hi,	// 2
  sub_16bit,	// 3
  sub_32bit,	// 4
  sub_xmm,	// 5
  NUM_TARGET_SUBREGS
};
}
} // End llvm namespace 
#endif // GET_REGINFO_ENUM

/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*MC Register Information                                                     *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_MC_DESC
#undef GET_REGINFO_MC_DESC
namespace llvm {

extern const MCPhysReg X86RegDiffLists[] = {
  /* 0 */ 0, 1, 0,
  /* 3 */ 1, 1, 1, 0,
  /* 7 */ 65533, 1, 1, 0,
  /* 11 */ 62, 2, 1, 0,
  /* 15 */ 65535, 2, 1, 0,
  /* 19 */ 62, 3, 1, 0,
  /* 23 */ 5, 1, 0,
  /* 26 */ 65474, 64, 1, 0,
  /* 30 */ 65474, 65, 1, 0,
  /* 34 */ 65211, 1, 0,
  /* 37 */ 65403, 1, 0,
  /* 40 */ 65472, 65498, 1, 0,
  /* 44 */ 65472, 65519, 1, 0,
  /* 48 */ 65534, 1, 2, 0,
  /* 52 */ 24, 2, 0,
  /* 55 */ 65471, 62, 2, 0,
  /* 59 */ 65470, 62, 3, 0,
  /* 63 */ 65472, 62, 3, 0,
  /* 67 */ 65471, 62, 4, 0,
  /* 71 */ 65453, 3, 10, 6, 0,
  /* 76 */ 65473, 15, 0,
  /* 79 */ 65455, 1, 16, 0,
  /* 83 */ 65435, 1, 18, 18, 0,
  /* 88 */ 25, 0,
  /* 90 */ 65434, 1, 37, 0,
  /* 94 */ 65431, 1, 3, 37, 0,
  /* 99 */ 65430, 1, 1, 40, 0,
  /* 104 */ 41, 0,
  /* 106 */ 42, 0,
  /* 108 */ 43, 0,
  /* 110 */ 44, 0,
  /* 112 */ 45, 0,
  /* 114 */ 46, 0,
  /* 116 */ 47, 0,
  /* 118 */ 15, 48, 0,
  /* 121 */ 61, 0,
  /* 123 */ 65535, 65471, 62, 0,
  /* 127 */ 65535, 65472, 62, 0,
  /* 131 */ 65521, 63, 0,
  /* 134 */ 10, 6, 64, 0,
  /* 138 */ 13, 6, 64, 0,
  /* 142 */ 1, 16, 64, 0,
  /* 146 */ 65523, 3, 16, 64, 0,
  /* 151 */ 65535, 17, 64, 0,
  /* 155 */ 18, 18, 64, 0,
  /* 159 */ 19, 18, 64, 0,
  /* 163 */ 65517, 1, 36, 64, 0,
  /* 168 */ 1, 37, 64, 0,
  /* 172 */ 3, 37, 64, 0,
  /* 176 */ 4, 37, 64, 0,
  /* 180 */ 65535, 38, 64, 0,
  /* 184 */ 65532, 1, 40, 64, 0,
  /* 189 */ 2, 40, 64, 0,
  /* 193 */ 65534, 1, 41, 64, 0,
  /* 198 */ 65, 0,
  /* 200 */ 66, 0,
  /* 202 */ 67, 0,
  /* 204 */ 68, 0,
  /* 206 */ 69, 0,
  /* 208 */ 65517, 3, 10, 70, 0,
  /* 213 */ 72, 0,
  /* 215 */ 74, 0,
  /* 217 */ 65519, 1, 80, 0,
  /* 221 */ 65499, 1, 18, 82, 0,
  /* 226 */ 65498, 1, 101, 0,
  /* 230 */ 65495, 1, 3, 101, 0,
  /* 235 */ 65494, 1, 1, 104, 0,
  /* 240 */ 64598, 0,
  /* 242 */ 65461, 0,
  /* 244 */ 65462, 0,
  /* 246 */ 65464, 0,
  /* 248 */ 65466, 0,
  /* 250 */ 65468, 0,
  /* 252 */ 65470, 0,
  /* 254 */ 65472, 0,
  /* 256 */ 65474, 0,
  /* 258 */ 65478, 0,
  /* 260 */ 65485, 0,
  /* 262 */ 65520, 0,
  /* 264 */ 65522, 0,
  /* 266 */ 65523, 0,
  /* 268 */ 65530, 0,
  /* 270 */ 65531, 0,
  /* 272 */ 65532, 0,
  /* 274 */ 65472, 65530, 65526, 65533, 0,
  /* 279 */ 2, 1, 65534, 0,
  /* 283 */ 2, 65535, 65534, 0,
  /* 287 */ 65472, 65518, 65518, 65535, 0,
  /* 292 */ 65472, 65499, 65533, 65535, 0,
  /* 297 */ 65472, 65496, 65535, 65535, 0,
};

extern const uint16_t X86SubRegIdxLists[] = {
  /* 0 */ 4, 3, 1, 0,
  /* 4 */ 4, 3, 1, 2, 0,
  /* 9 */ 4, 3, 0,
  /* 12 */ 5, 0,
};

extern const char X86RegStrings[] = {
  /* 0 */ 'X', 'M', 'M', '1', '0', 0,
  /* 6 */ 'Y', 'M', 'M', '1', '0', 0,
  /* 12 */ 'C', 'R', '1', '0', 0,
  /* 17 */ 'X', 'M', 'M', '0', 0,
  /* 22 */ 'Y', 'M', 'M', '0', 0,
  /* 27 */ 'F', 'P', '0', 0,
  /* 31 */ 'C', 'R', '0', 0,
  /* 35 */ 'D', 'R', '0', 0,
  /* 39 */ 'S', 'T', '0', 0,
  /* 43 */ 'X', 'M', 'M', '1', '1', 0,
  /* 49 */ 'Y', 'M', 'M', '1', '1', 0,
  /* 55 */ 'C', 'R', '1', '1', 0,
  /* 60 */ 'X', 'M', 'M', '1', 0,
  /* 65 */ 'Y', 'M', 'M', '1', 0,
  /* 70 */ 'F', 'P', '1', 0,
  /* 74 */ 'C', 'R', '1', 0,
  /* 78 */ 'D', 'R', '1', 0,
  /* 82 */ 'S', 'T', '1', 0,
  /* 86 */ 'X', 'M', 'M', '1', '2', 0,
  /* 92 */ 'Y', 'M', 'M', '1', '2', 0,
  /* 98 */ 'C', 'R', '1', '2', 0,
  /* 103 */ 'X', 'M', 'M', '2', 0,
  /* 108 */ 'Y', 'M', 'M', '2', 0,
  /* 113 */ 'F', 'P', '2', 0,
  /* 117 */ 'C', 'R', '2', 0,
  /* 121 */ 'D', 'R', '2', 0,
  /* 125 */ 'S', 'T', '2', 0,
  /* 129 */ 'X', 'M', 'M', '1', '3', 0,
  /* 135 */ 'Y', 'M', 'M', '1', '3', 0,
  /* 141 */ 'C', 'R', '1', '3', 0,
  /* 146 */ 'X', 'M', 'M', '3', 0,
  /* 151 */ 'Y', 'M', 'M', '3', 0,
  /* 156 */ 'F', 'P', '3', 0,
  /* 160 */ 'C', 'R', '3', 0,
  /* 164 */ 'D', 'R', '3', 0,
  /* 168 */ 'S', 'T', '3', 0,
  /* 172 */ 'X', 'M', 'M', '1', '4', 0,
  /* 178 */ 'Y', 'M', 'M', '1', '4', 0,
  /* 184 */ 'C', 'R', '1', '4', 0,
  /* 189 */ 'X', 'M', 'M', '4', 0,
  /* 194 */ 'Y', 'M', 'M', '4', 0,
  /* 199 */ 'F', 'P', '4', 0,
  /* 203 */ 'C', 'R', '4', 0,
  /* 207 */ 'D', 'R', '4', 0,
  /* 211 */ 'S', 'T', '4', 0,
  /* 215 */ 'X', 'M', 'M', '1', '5', 0,
  /* 221 */ 'Y', 'M', 'M', '1', '5', 0,
  /* 227 */ 'C', 'R', '1', '5', 0,
  /* 232 */ 'X', 'M', 'M', '5', 0,
  /* 237 */ 'Y', 'M', 'M', '5', 0,
  /* 242 */ 'F', 'P', '5', 0,
  /* 246 */ 'C', 'R', '5', 0,
  /* 250 */ 'D', 'R', '5', 0,
  /* 254 */ 'S', 'T', '5', 0,
  /* 258 */ 'X', 'M', 'M', '6', 0,
  /* 263 */ 'Y', 'M', 'M', '6', 0,
  /* 268 */ 'F', 'P', '6', 0,
  /* 272 */ 'C', 'R', '6', 0,
  /* 276 */ 'D', 'R', '6', 0,
  /* 280 */ 'S', 'T', '6', 0,
  /* 284 */ 'X', 'M', 'M', '7', 0,
  /* 289 */ 'Y', 'M', 'M', '7', 0,
  /* 294 */ 'C', 'R', '7', 0,
  /* 298 */ 'D', 'R', '7', 0,
  /* 302 */ 'S', 'T', '7', 0,
  /* 306 */ 'X', 'M', 'M', '8', 0,
  /* 311 */ 'Y', 'M', 'M', '8', 0,
  /* 316 */ 'C', 'R', '8', 0,
  /* 320 */ 'X', 'M', 'M', '9', 0,
  /* 325 */ 'Y', 'M', 'M', '9', 0,
  /* 330 */ 'C', 'R', '9', 0,
  /* 334 */ 'R', '1', '0', 'B', 0,
  /* 339 */ 'R', '1', '1', 'B', 0,
  /* 344 */ 'R', '1', '2', 'B', 0,
  /* 349 */ 'R', '1', '3', 'B', 0,
  /* 354 */ 'R', '1', '4', 'B', 0,
  /* 359 */ 'R', '1', '5', 'B', 0,
  /* 364 */ 'R', '8', 'B', 0,
  /* 368 */ 'R', '9', 'B', 0,
  /* 372 */ 'R', '1', '0', 'D', 0,
  /* 377 */ 'R', '1', '1', 'D', 0,
  /* 382 */ 'R', '1', '2', 'D', 0,
  /* 387 */ 'R', '1', '3', 'D', 0,
  /* 392 */ 'R', '1', '4', 'D', 0,
  /* 397 */ 'R', '1', '5', 'D', 0,
  /* 402 */ 'R', '8', 'D', 0,
  /* 406 */ 'R', '9', 'D', 0,
  /* 410 */ 'P', 'S', 'E', 'U', 'D', 'O', '_', 'N', 'A', 'C', 'L', '_', 'S', 'E', 'G', 0,
  /* 426 */ 'A', 'H', 0,
  /* 429 */ 'B', 'H', 0,
  /* 432 */ 'C', 'H', 0,
  /* 435 */ 'D', 'H', 0,
  /* 438 */ 'E', 'D', 'I', 0,
  /* 442 */ 'R', 'D', 'I', 0,
  /* 446 */ 'E', 'S', 'I', 0,
  /* 450 */ 'R', 'S', 'I', 0,
  /* 454 */ 'A', 'L', 0,
  /* 457 */ 'B', 'L', 0,
  /* 460 */ 'C', 'L', 0,
  /* 463 */ 'D', 'L', 0,
  /* 466 */ 'D', 'I', 'L', 0,
  /* 470 */ 'S', 'I', 'L', 0,
  /* 474 */ 'B', 'P', 'L', 0,
  /* 478 */ 'S', 'P', 'L', 0,
  /* 482 */ 'E', 'B', 'P', 0,
  /* 486 */ 'R', 'B', 'P', 0,
  /* 490 */ 'E', 'I', 'P', 0,
  /* 494 */ 'R', 'I', 'P', 0,
  /* 498 */ 'E', 'S', 'P', 0,
  /* 502 */ 'R', 'S', 'P', 0,
  /* 506 */ 'C', 'S', 0,
  /* 509 */ 'D', 'S', 0,
  /* 512 */ 'E', 'S', 0,
  /* 515 */ 'F', 'S', 0,
  /* 518 */ 'E', 'F', 'L', 'A', 'G', 'S', 0,
  /* 525 */ 'S', 'S', 0,
  /* 528 */ 'R', '1', '0', 'W', 0,
  /* 533 */ 'R', '1', '1', 'W', 0,
  /* 538 */ 'R', '1', '2', 'W', 0,
  /* 543 */ 'R', '1', '3', 'W', 0,
  /* 548 */ 'R', '1', '4', 'W', 0,
  /* 553 */ 'R', '1', '5', 'W', 0,
  /* 558 */ 'R', '8', 'W', 0,
  /* 562 */ 'R', '9', 'W', 0,
  /* 566 */ 'F', 'P', 'S', 'W', 0,
  /* 571 */ 'E', 'A', 'X', 0,
  /* 575 */ 'R', 'A', 'X', 0,
  /* 579 */ 'E', 'B', 'X', 0,
  /* 583 */ 'R', 'B', 'X', 0,
  /* 587 */ 'E', 'C', 'X', 0,
  /* 591 */ 'R', 'C', 'X', 0,
  /* 595 */ 'E', 'D', 'X', 0,
  /* 599 */ 'R', 'D', 'X', 0,
  /* 603 */ 'E', 'I', 'Z', 0,
  /* 607 */ 'R', 'I', 'Z', 0,
};

extern const MCRegisterDesc X86RegDesc[] = { // Descriptors
  { 5, 0, 0, 0, 0, 0 },
  { 426, 189, 2, 189, 3, 4641 },
  { 454, 185, 2, 185, 3, 4641 },
  { 572, 193, 299, 186, 6, 0 },
  { 429, 176, 2, 176, 3, 4497 },
  { 457, 172, 2, 172, 3, 4497 },
  { 483, 168, 1, 181, 2, 1104 },
  { 474, 180, 2, 180, 3, 1104 },
  { 580, 184, 294, 169, 6, 192 },
  { 432, 159, 2, 159, 3, 4353 },
  { 460, 155, 2, 155, 3, 4353 },
  { 31, 2, 2, 2, 3, 4353 },
  { 74, 2, 2, 2, 3, 4353 },
  { 117, 2, 2, 2, 3, 4353 },
  { 160, 2, 2, 2, 3, 4353 },
  { 203, 2, 2, 2, 3, 4353 },
  { 246, 2, 2, 2, 3, 4353 },
  { 272, 2, 2, 2, 3, 4353 },
  { 294, 2, 2, 2, 3, 4353 },
  { 316, 2, 2, 2, 3, 4353 },
  { 330, 2, 2, 2, 3, 4353 },
  { 12, 2, 2, 2, 3, 4353 },
  { 55, 2, 2, 2, 3, 4353 },
  { 98, 2, 2, 2, 3, 4353 },
  { 141, 2, 2, 2, 3, 4353 },
  { 184, 2, 2, 2, 3, 4353 },
  { 227, 2, 2, 2, 3, 4353 },
  { 506, 2, 2, 2, 3, 4353 },
  { 588, 163, 289, 156, 6, 368 },
  { 435, 138, 2, 138, 3, 4321 },
  { 439, 142, 1, 152, 2, 1408 },
  { 466, 151, 2, 151, 3, 1408 },
  { 463, 134, 2, 134, 3, 4289 },
  { 35, 2, 2, 2, 3, 4289 },
  { 78, 2, 2, 2, 3, 4289 },
  { 121, 2, 2, 2, 3, 4289 },
  { 164, 2, 2, 2, 3, 4289 },
  { 207, 2, 2, 2, 3, 4289 },
  { 250, 2, 2, 2, 3, 4289 },
  { 276, 2, 2, 2, 3, 4289 },
  { 298, 2, 2, 2, 3, 4289 },
  { 509, 2, 2, 2, 3, 4289 },
  { 596, 146, 276, 135, 6, 832 },
  { 571, 235, 298, 136, 5, 0 },
  { 482, 226, 41, 136, 1, 1104 },
  { 579, 230, 293, 136, 5, 595 },
  { 587, 221, 288, 136, 5, 595 },
  { 438, 217, 45, 136, 1, 1408 },
  { 595, 208, 275, 136, 5, 832 },
  { 518, 2, 2, 2, 3, 4257 },
  { 490, 118, 77, 132, 10, 4257 },
  { 603, 2, 2, 2, 3, 4257 },
  { 512, 2, 2, 2, 3, 4257 },
  { 446, 11, 27, 125, 1, 4257 },
  { 498, 19, 31, 125, 1, 4257 },
  { 27, 215, 2, 2, 3, 4257 },
  { 70, 213, 2, 2, 3, 4257 },
  { 113, 211, 2, 2, 3, 4257 },
  { 156, 204, 2, 2, 3, 4257 },
  { 199, 200, 2, 2, 3, 4257 },
  { 242, 136, 2, 2, 3, 4257 },
  { 268, 125, 2, 2, 3, 4257 },
  { 566, 2, 2, 2, 3, 4257 },
  { 515, 2, 2, 2, 3, 4257 },
  { 522, 2, 2, 2, 3, 4257 },
  { 491, 131, 2, 131, 3, 3855 },
  { 18, 2, 2, 2, 3, 4225 },
  { 61, 2, 2, 2, 3, 4225 },
  { 104, 2, 2, 2, 3, 4225 },
  { 147, 2, 2, 2, 3, 4225 },
  { 190, 2, 2, 2, 3, 4225 },
  { 233, 2, 2, 2, 3, 4225 },
  { 259, 2, 2, 2, 3, 4225 },
  { 285, 2, 2, 2, 3, 4225 },
  { 410, 2, 2, 2, 3, 4225 },
  { 317, 3, 279, 2, 0, 1936 },
  { 364, 15, 2, 283, 3, 1936 },
  { 402, 48, 280, 281, 1, 1936 },
  { 558, 7, 281, 284, 2, 1936 },
  { 331, 3, 279, 2, 0, 2000 },
  { 368, 15, 2, 283, 3, 2000 },
  { 406, 48, 280, 281, 1, 2000 },
  { 562, 7, 281, 284, 2, 2000 },
  { 13, 3, 279, 2, 0, 2112 },
  { 334, 15, 2, 283, 3, 2112 },
  { 372, 48, 280, 281, 1, 2112 },
  { 528, 7, 281, 284, 2, 2112 },
  { 56, 3, 279, 2, 0, 2176 },
  { 339, 15, 2, 283, 3, 2176 },
  { 377, 48, 280, 281, 1, 2176 },
  { 533, 7, 281, 284, 2, 2176 },
  { 99, 3, 279, 2, 0, 3168 },
  { 344, 15, 2, 283, 3, 3168 },
  { 382, 48, 280, 281, 1, 3168 },
  { 538, 7, 281, 284, 2, 3168 },
  { 142, 3, 279, 2, 0, 3200 },
  { 349, 15, 2, 283, 3, 3200 },
  { 387, 48, 280, 281, 1, 3200 },
  { 543, 7, 281, 284, 2, 3200 },
  { 185, 3, 279, 2, 0, 3232 },
  { 354, 15, 2, 283, 3, 3232 },
  { 392, 48, 280, 281, 1, 3232 },
  { 548, 7, 281, 284, 2, 3232 },
  { 228, 3, 279, 2, 0, 3264 },
  { 359, 15, 2, 283, 3, 3264 },
  { 397, 48, 280, 281, 1, 3264 },
  { 553, 7, 281, 284, 2, 3264 },
  { 575, 99, 297, 2, 4, 0 },
  { 486, 90, 40, 2, 0, 1104 },
  { 583, 94, 292, 2, 4, 547 },
  { 591, 83, 287, 2, 4, 547 },
  { 442, 79, 44, 2, 0, 1408 },
  { 599, 71, 274, 2, 4, 832 },
  { 494, 76, 76, 2, 9, 1472 },
  { 607, 2, 2, 2, 3, 3296 },
  { 450, 26, 26, 2, 0, 3873 },
  { 502, 30, 30, 2, 0, 3873 },
  { 447, 63, 1, 128, 2, 1632 },
  { 470, 55, 2, 127, 3, 1632 },
  { 499, 67, 1, 124, 2, 1664 },
  { 478, 59, 2, 123, 3, 1664 },
  { 525, 2, 2, 2, 3, 4161 },
  { 39, 2, 2, 2, 3, 4161 },
  { 82, 256, 2, 2, 3, 1904 },
  { 125, 254, 2, 2, 3, 1856 },
  { 168, 252, 2, 2, 3, 1824 },
  { 211, 250, 2, 2, 3, 1792 },
  { 254, 248, 2, 2, 3, 1760 },
  { 280, 246, 2, 2, 3, 1728 },
  { 302, 244, 2, 2, 3, 1696 },
  { 17, 81, 2, 81, 3, 4129 },
  { 60, 81, 2, 81, 3, 4129 },
  { 103, 81, 2, 81, 3, 4129 },
  { 146, 81, 2, 81, 3, 4129 },
  { 189, 81, 2, 81, 3, 4129 },
  { 232, 81, 2, 81, 3, 4129 },
  { 258, 81, 2, 81, 3, 4129 },
  { 284, 81, 2, 81, 3, 4129 },
  { 306, 81, 2, 81, 3, 4129 },
  { 320, 81, 2, 81, 3, 4129 },
  { 0, 81, 2, 81, 3, 4129 },
  { 43, 81, 2, 81, 3, 4129 },
  { 86, 81, 2, 81, 3, 4129 },
  { 129, 81, 2, 81, 3, 4129 },
  { 172, 81, 2, 81, 3, 4129 },
  { 215, 81, 2, 81, 3, 4129 },
  { 22, 262, 262, 2, 12, 3905 },
  { 65, 262, 262, 2, 12, 3905 },
  { 108, 262, 262, 2, 12, 3905 },
  { 151, 262, 262, 2, 12, 3905 },
  { 194, 262, 262, 2, 12, 3905 },
  { 237, 262, 262, 2, 12, 3905 },
  { 263, 262, 262, 2, 12, 3905 },
  { 289, 262, 262, 2, 12, 3905 },
  { 311, 262, 262, 2, 12, 3905 },
  { 325, 262, 262, 2, 12, 3905 },
  { 6, 262, 262, 2, 12, 3905 },
  { 49, 262, 262, 2, 12, 3905 },
  { 92, 262, 262, 2, 12, 3905 },
  { 135, 262, 262, 2, 12, 3905 },
  { 178, 262, 262, 2, 12, 3905 },
  { 221, 262, 262, 2, 12, 3905 },
};

extern const uint16_t X86RegUnitRoots[][2] = {
  { X86::AH },
  { X86::AL },
  { X86::BH },
  { X86::BL },
  { X86::BPL },
  { X86::CH },
  { X86::CL },
  { X86::CR0 },
  { X86::CR1 },
  { X86::CR2 },
  { X86::CR3 },
  { X86::CR4 },
  { X86::CR5 },
  { X86::CR6 },
  { X86::CR7 },
  { X86::CR8 },
  { X86::CR9 },
  { X86::CR10 },
  { X86::CR11 },
  { X86::CR12 },
  { X86::CR13 },
  { X86::CR14 },
  { X86::CR15 },
  { X86::CS },
  { X86::DH },
  { X86::DIL },
  { X86::DL },
  { X86::DR0 },
  { X86::DR1 },
  { X86::DR2 },
  { X86::DR3 },
  { X86::DR4 },
  { X86::DR5 },
  { X86::DR6 },
  { X86::DR7 },
  { X86::DS },
  { X86::EFLAGS },
  { X86::IP },
  { X86::EIZ },
  { X86::ES },
  { X86::SIL },
  { X86::SPL },
  { X86::FP0, X86::ST7 },
  { X86::FP1, X86::ST6 },
  { X86::FP2, X86::ST5 },
  { X86::FP3, X86::ST4 },
  { X86::FP4, X86::ST3 },
  { X86::FP5, X86::ST2 },
  { X86::FP6, X86::ST1 },
  { X86::FPSW },
  { X86::FS },
  { X86::GS },
  { X86::MM0 },
  { X86::MM1 },
  { X86::MM2 },
  { X86::MM3 },
  { X86::MM4 },
  { X86::MM5 },
  { X86::MM6 },
  { X86::MM7 },
  { X86::PSEUDO_NACL_SEG },
  { X86::R8B },
  { X86::R9B },
  { X86::R10B },
  { X86::R11B },
  { X86::R12B },
  { X86::R13B },
  { X86::R14B },
  { X86::R15B },
  { X86::RIZ },
  { X86::SS },
  { X86::ST0 },
  { X86::XMM0 },
  { X86::XMM1 },
  { X86::XMM2 },
  { X86::XMM3 },
  { X86::XMM4 },
  { X86::XMM5 },
  { X86::XMM6 },
  { X86::XMM7 },
  { X86::XMM8 },
  { X86::XMM9 },
  { X86::XMM10 },
  { X86::XMM11 },
  { X86::XMM12 },
  { X86::XMM13 },
  { X86::XMM14 },
  { X86::XMM15 },
};

namespace {     // Register classes...
  // GR8 Register Class...
  const uint16_t GR8[] = {
    X86::AL, X86::CL, X86::DL, X86::AH, X86::CH, X86::DH, X86::BL, X86::BH, X86::SIL, X86::DIL, X86::BPL, X86::SPL, X86::R8B, X86::R9B, X86::R10B, X86::R11B, X86::R14B, X86::R15B, X86::R12B, X86::R13B, 
  };

  // GR8 Bit set.
  const uint8_t GR8Bits[] = {
    0xb6, 0x06, 0x00, 0xa0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x10, 0x11, 0x11, 0x11, 0x01, 0x40, 0x01, 
  };

  // GR8_NOREX Register Class...
  const uint16_t GR8_NOREX[] = {
    X86::AL, X86::CL, X86::DL, X86::AH, X86::CH, X86::DH, X86::BL, X86::BH, 
  };

  // GR8_NOREX Bit set.
  const uint8_t GR8_NOREXBits[] = {
    0x36, 0x06, 0x00, 0x20, 0x01, 
  };

  // GR8_ABCD_H Register Class...
  const uint16_t GR8_ABCD_H[] = {
    X86::AH, X86::CH, X86::DH, X86::BH, 
  };

  // GR8_ABCD_H Bit set.
  const uint8_t GR8_ABCD_HBits[] = {
    0x12, 0x02, 0x00, 0x20, 
  };

  // GR8_ABCD_L Register Class...
  const uint16_t GR8_ABCD_L[] = {
    X86::AL, X86::CL, X86::DL, X86::BL, 
  };

  // GR8_ABCD_L Bit set.
  const uint8_t GR8_ABCD_LBits[] = {
    0x24, 0x04, 0x00, 0x00, 0x01, 
  };

  // GR16 Register Class...
  const uint16_t GR16[] = {
    X86::AX, X86::CX, X86::DX, X86::SI, X86::DI, X86::BX, X86::BP, X86::SP, X86::R8W, X86::R9W, X86::R10W, X86::R11W, X86::R14W, X86::R15W, X86::R12W, X86::R13W, 
  };

  // GR16 Bit set.
  const uint8_t GR16Bits[] = {
    0x48, 0x01, 0x00, 0x50, 0x00, 0x04, 0x00, 0x00, 0x00, 0x40, 0x44, 0x44, 0x44, 0x04, 0xa0, 
  };

  // GR16_NOREX Register Class...
  const uint16_t GR16_NOREX[] = {
    X86::AX, X86::CX, X86::DX, X86::SI, X86::DI, X86::BX, X86::BP, X86::SP, 
  };

  // GR16_NOREX Bit set.
  const uint8_t GR16_NOREXBits[] = {
    0x48, 0x01, 0x00, 0x50, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa0, 
  };

  // SEGMENT_REG Register Class...
  const uint16_t SEGMENT_REG[] = {
    X86::CS, X86::DS, X86::SS, X86::ES, X86::FS, X86::GS, 
  };

  // SEGMENT_REG Bit set.
  const uint8_t SEGMENT_REGBits[] = {
    0x00, 0x00, 0x00, 0x08, 0x00, 0x02, 0x10, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 
  };

  // GR16_ABCD Register Class...
  const uint16_t GR16_ABCD[] = {
    X86::AX, X86::CX, X86::DX, X86::BX, 
  };

  // GR16_ABCD Bit set.
  const uint8_t GR16_ABCDBits[] = {
    0x08, 0x01, 0x00, 0x10, 0x00, 0x04, 
  };

  // FPCCR Register Class...
  const uint16_t FPCCR[] = {
    X86::FPSW, 
  };

  // FPCCR Bit set.
  const uint8_t FPCCRBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 
  };

  // FR32 Register Class...
  const uint16_t FR32[] = {
    X86::XMM0, X86::XMM1, X86::XMM2, X86::XMM3, X86::XMM4, X86::XMM5, X86::XMM6, X86::XMM7, X86::XMM8, X86::XMM9, X86::XMM10, X86::XMM11, X86::XMM12, X86::XMM13, X86::XMM14, X86::XMM15, 
  };

  // FR32 Bit set.
  const uint8_t FR32Bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0x03, 
  };

  // GR32 Register Class...
  const uint16_t GR32[] = {
    X86::EAX, X86::ECX, X86::EDX, X86::ESI, X86::EDI, X86::EBX, X86::EBP, X86::ESP, X86::R8D, X86::R9D, X86::R10D, X86::R11D, X86::R14D, X86::R15D, X86::R12D, X86::R13D, 
  };

  // GR32 Bit set.
  const uint8_t GR32Bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x61, 0x00, 0x00, 0x20, 0x22, 0x22, 0x22, 0x02, 
  };

  // GR32_NOAX Register Class...
  const uint16_t GR32_NOAX[] = {
    X86::ECX, X86::EDX, X86::ESI, X86::EDI, X86::EBX, X86::EBP, X86::ESP, X86::R8D, X86::R9D, X86::R10D, X86::R11D, X86::R14D, X86::R15D, X86::R12D, X86::R13D, 
  };

  // GR32_NOAX Bit set.
  const uint8_t GR32_NOAXBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x61, 0x00, 0x00, 0x20, 0x22, 0x22, 0x22, 0x02, 
  };

  // GR32_NOSP Register Class...
  const uint16_t GR32_NOSP[] = {
    X86::EAX, X86::ECX, X86::EDX, X86::ESI, X86::EDI, X86::EBX, X86::EBP, X86::R8D, X86::R9D, X86::R10D, X86::R11D, X86::R14D, X86::R15D, X86::R12D, X86::R13D, 
  };

  // GR32_NOSP Bit set.
  const uint8_t GR32_NOSPBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x21, 0x00, 0x00, 0x20, 0x22, 0x22, 0x22, 0x02, 
  };

  // GR32_NOAX_and_GR32_NOSP Register Class...
  const uint16_t GR32_NOAX_and_GR32_NOSP[] = {
    X86::ECX, X86::EDX, X86::ESI, X86::EDI, X86::EBX, X86::EBP, X86::R8D, X86::R9D, X86::R10D, X86::R11D, X86::R14D, X86::R15D, X86::R12D, X86::R13D, 
  };

  // GR32_NOAX_and_GR32_NOSP Bit set.
  const uint8_t GR32_NOAX_and_GR32_NOSPBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x21, 0x00, 0x00, 0x20, 0x22, 0x22, 0x22, 0x02, 
  };

  // DEBUG_REG Register Class...
  const uint16_t DEBUG_REG[] = {
    X86::DR0, X86::DR1, X86::DR2, X86::DR3, X86::DR4, X86::DR5, X86::DR6, X86::DR7, 
  };

  // DEBUG_REG Bit set.
  const uint8_t DEBUG_REGBits[] = {
    0x00, 0x00, 0x00, 0x00, 0xfe, 0x01, 
  };

  // GR32_NOREX Register Class...
  const uint16_t GR32_NOREX[] = {
    X86::EAX, X86::ECX, X86::EDX, X86::ESI, X86::EDI, X86::EBX, X86::EBP, X86::ESP, 
  };

  // GR32_NOREX Bit set.
  const uint8_t GR32_NOREXBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x61, 
  };

  // GR32_TC_64 Register Class...
  const uint16_t GR32_TC_64[] = {
    X86::EAX, X86::ECX, X86::EDX, X86::ESI, X86::EDI, X86::R8D, X86::R9D, X86::R11D, 
  };

  // GR32_TC_64 Bit set.
  const uint8_t GR32_TC_64Bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0xc8, 0x21, 0x00, 0x00, 0x20, 0x02, 0x02, 
  };

  // GR32_NOAX_and_GR32_NOREX Register Class...
  const uint16_t GR32_NOAX_and_GR32_NOREX[] = {
    X86::ECX, X86::EDX, X86::ESI, X86::EDI, X86::EBX, X86::EBP, X86::ESP, 
  };

  // GR32_NOAX_and_GR32_NOREX Bit set.
  const uint8_t GR32_NOAX_and_GR32_NOREXBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x61, 
  };

  // GR32_NOAX_and_GR32_TC_64 Register Class...
  const uint16_t GR32_NOAX_and_GR32_TC_64[] = {
    X86::ECX, X86::EDX, X86::ESI, X86::EDI, X86::R8D, X86::R9D, X86::R11D, 
  };

  // GR32_NOAX_and_GR32_TC_64 Bit set.
  const uint8_t GR32_NOAX_and_GR32_TC_64Bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x21, 0x00, 0x00, 0x20, 0x02, 0x02, 
  };

  // GR32_NOREX_NOSP Register Class...
  const uint16_t GR32_NOREX_NOSP[] = {
    X86::EAX, X86::ECX, X86::EDX, X86::ESI, X86::EDI, X86::EBX, X86::EBP, 
  };

  // GR32_NOREX_NOSP Bit set.
  const uint8_t GR32_NOREX_NOSPBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x21, 
  };

  // RFP32 Register Class...
  const uint16_t RFP32[] = {
    X86::FP0, X86::FP1, X86::FP2, X86::FP3, X86::FP4, X86::FP5, X86::FP6, 
  };

  // RFP32 Bit set.
  const uint8_t RFP32Bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 
  };

  // GR32_NOAX_and_GR32_NOREX_NOSP Register Class...
  const uint16_t GR32_NOAX_and_GR32_NOREX_NOSP[] = {
    X86::ECX, X86::EDX, X86::ESI, X86::EDI, X86::EBX, X86::EBP, 
  };

  // GR32_NOAX_and_GR32_NOREX_NOSP Bit set.
  const uint8_t GR32_NOAX_and_GR32_NOREX_NOSPBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x21, 
  };

  // GR32_NOREX_and_GR32_TC_64 Register Class...
  const uint16_t GR32_NOREX_and_GR32_TC_64[] = {
    X86::EAX, X86::ECX, X86::EDX, X86::ESI, X86::EDI, 
  };

  // GR32_NOREX_and_GR32_TC_64 Bit set.
  const uint8_t GR32_NOREX_and_GR32_TC_64Bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0xc8, 0x21, 
  };

  // GR32_ABCD Register Class...
  const uint16_t GR32_ABCD[] = {
    X86::EAX, X86::ECX, X86::EDX, X86::EBX, 
  };

  // GR32_ABCD Bit set.
  const uint8_t GR32_ABCDBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x68, 0x01, 
  };

  // GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64 Register Class...
  const uint16_t GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64[] = {
    X86::ECX, X86::EDX, X86::ESI, X86::EDI, 
  };

  // GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64 Bit set.
  const uint8_t GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64Bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x21, 
  };

  // GR32_ABCD_and_GR32_NOAX Register Class...
  const uint16_t GR32_ABCD_and_GR32_NOAX[] = {
    X86::ECX, X86::EDX, X86::EBX, 
  };

  // GR32_ABCD_and_GR32_NOAX Bit set.
  const uint8_t GR32_ABCD_and_GR32_NOAXBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x01, 
  };

  // GR32_TC Register Class...
  const uint16_t GR32_TC[] = {
    X86::EAX, X86::ECX, X86::EDX, 
  };

  // GR32_TC Bit set.
  const uint8_t GR32_TCBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x01, 
  };

  // GR32_AD Register Class...
  const uint16_t GR32_AD[] = {
    X86::EAX, X86::EDX, 
  };

  // GR32_AD Bit set.
  const uint8_t GR32_ADBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x01, 
  };

  // GR32_NOAX_and_GR32_TC Register Class...
  const uint16_t GR32_NOAX_and_GR32_TC[] = {
    X86::ECX, X86::EDX, 
  };

  // GR32_NOAX_and_GR32_TC Bit set.
  const uint8_t GR32_NOAX_and_GR32_TCBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x01, 
  };

  // CCR Register Class...
  const uint16_t CCR[] = {
    X86::EFLAGS, 
  };

  // CCR Bit set.
  const uint8_t CCRBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 
  };

  // GR32_AD_and_GR32_NOAX Register Class...
  const uint16_t GR32_AD_and_GR32_NOAX[] = {
    X86::EDX, 
  };

  // GR32_AD_and_GR32_NOAX Bit set.
  const uint8_t GR32_AD_and_GR32_NOAXBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
  };

  // RFP64 Register Class...
  const uint16_t RFP64[] = {
    X86::FP0, X86::FP1, X86::FP2, X86::FP3, X86::FP4, X86::FP5, X86::FP6, 
  };

  // RFP64 Bit set.
  const uint8_t RFP64Bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 
  };

  // GR64 Register Class...
  const uint16_t GR64[] = {
    X86::RAX, X86::RCX, X86::RDX, X86::RSI, X86::RDI, X86::R8, X86::R9, X86::R10, X86::R11, X86::RBX, X86::R14, X86::R15, X86::R12, X86::R13, X86::RBP, X86::RSP, X86::RIP, 
  };

  // GR64 Bit set.
  const uint8_t GR64Bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0x88, 0x88, 0xf8, 0x1b, 
  };

  // CONTROL_REG Register Class...
  const uint16_t CONTROL_REG[] = {
    X86::CR0, X86::CR1, X86::CR2, X86::CR3, X86::CR4, X86::CR5, X86::CR6, X86::CR7, X86::CR8, X86::CR9, X86::CR10, X86::CR11, X86::CR12, X86::CR13, X86::CR14, X86::CR15, 
  };

  // CONTROL_REG Bit set.
  const uint8_t CONTROL_REGBits[] = {
    0x00, 0xf8, 0xff, 0x07, 
  };

  // FR64 Register Class...
  const uint16_t FR64[] = {
    X86::XMM0, X86::XMM1, X86::XMM2, X86::XMM3, X86::XMM4, X86::XMM5, X86::XMM6, X86::XMM7, X86::XMM8, X86::XMM9, X86::XMM10, X86::XMM11, X86::XMM12, X86::XMM13, X86::XMM14, X86::XMM15, 
  };

  // FR64 Bit set.
  const uint8_t FR64Bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0x03, 
  };

  // GR64_with_sub_8bit Register Class...
  const uint16_t GR64_with_sub_8bit[] = {
    X86::RAX, X86::RCX, X86::RDX, X86::RSI, X86::RDI, X86::R8, X86::R9, X86::R10, X86::R11, X86::RBX, X86::R14, X86::R15, X86::R12, X86::R13, X86::RBP, X86::RSP, 
  };

  // GR64_with_sub_8bit Bit set.
  const uint8_t GR64_with_sub_8bitBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0x88, 0x88, 0xf8, 0x19, 
  };

  // GR64_NOSP Register Class...
  const uint16_t GR64_NOSP[] = {
    X86::RAX, X86::RCX, X86::RDX, X86::RSI, X86::RDI, X86::R8, X86::R9, X86::R10, X86::R11, X86::RBX, X86::R14, X86::R15, X86::R12, X86::R13, X86::RBP, 
  };

  // GR64_NOSP Bit set.
  const uint8_t GR64_NOSPBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0x88, 0x88, 0xf8, 0x09, 
  };

  // GR64_with_sub_32bit_in_GR32_NOAX Register Class...
  const uint16_t GR64_with_sub_32bit_in_GR32_NOAX[] = {
    X86::RCX, X86::RDX, X86::RSI, X86::RDI, X86::R8, X86::R9, X86::R10, X86::R11, X86::RBX, X86::R14, X86::R15, X86::R12, X86::R13, X86::RBP, X86::RSP, 
  };

  // GR64_with_sub_32bit_in_GR32_NOAX Bit set.
  const uint8_t GR64_with_sub_32bit_in_GR32_NOAXBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0x88, 0x88, 0xf0, 0x19, 
  };

  // GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSP Register Class...
  const uint16_t GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSP[] = {
    X86::RCX, X86::RDX, X86::RSI, X86::RDI, X86::R8, X86::R9, X86::R10, X86::R11, X86::RBX, X86::R14, X86::R15, X86::R12, X86::R13, X86::RBP, 
  };

  // GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSP Bit set.
  const uint8_t GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSPBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0x88, 0x88, 0xf0, 0x09, 
  };

  // GR64_NOREX Register Class...
  const uint16_t GR64_NOREX[] = {
    X86::RAX, X86::RCX, X86::RDX, X86::RSI, X86::RDI, X86::RBX, X86::RBP, X86::RSP, X86::RIP, 
  };

  // GR64_NOREX Bit set.
  const uint8_t GR64_NOREXBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x1b, 
  };

  // GR64_TC Register Class...
  const uint16_t GR64_TC[] = {
    X86::RAX, X86::RCX, X86::RDX, X86::RSI, X86::RDI, X86::R8, X86::R9, X86::R11, X86::RIP, 
  };

  // GR64_TC Bit set.
  const uint8_t GR64_TCBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x80, 0x00, 0x00, 0xc8, 0x0b, 
  };

  // GR64_with_sub_16bit_in_GR16_NOREX Register Class...
  const uint16_t GR64_with_sub_16bit_in_GR16_NOREX[] = {
    X86::RAX, X86::RCX, X86::RDX, X86::RSI, X86::RDI, X86::RBX, X86::RBP, X86::RSP, 
  };

  // GR64_with_sub_16bit_in_GR16_NOREX Bit set.
  const uint8_t GR64_with_sub_16bit_in_GR16_NOREXBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x19, 
  };

  // GR64_with_sub_32bit_in_GR32_TC_64 Register Class...
  const uint16_t GR64_with_sub_32bit_in_GR32_TC_64[] = {
    X86::RAX, X86::RCX, X86::RDX, X86::RSI, X86::RDI, X86::R8, X86::R9, X86::R11, 
  };

  // GR64_with_sub_32bit_in_GR32_TC_64 Bit set.
  const uint8_t GR64_with_sub_32bit_in_GR32_TC_64Bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x80, 0x00, 0x00, 0xc8, 0x09, 
  };

  // VR64 Register Class...
  const uint16_t VR64[] = {
    X86::MM0, X86::MM1, X86::MM2, X86::MM3, X86::MM4, X86::MM5, X86::MM6, X86::MM7, 
  };

  // VR64 Bit set.
  const uint8_t VR64Bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x03, 
  };

  // GR64_NOREX_NOSP Register Class...
  const uint16_t GR64_NOREX_NOSP[] = {
    X86::RAX, X86::RCX, X86::RDX, X86::RSI, X86::RDI, X86::RBX, X86::RBP, 
  };

  // GR64_NOREX_NOSP Bit set.
  const uint8_t GR64_NOREX_NOSPBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x09, 
  };

  // GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX Register Class...
  const uint16_t GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX[] = {
    X86::RCX, X86::RDX, X86::RSI, X86::RDI, X86::RBX, X86::RBP, X86::RSP, 
  };

  // GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX Bit set.
  const uint8_t GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREXBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x19, 
  };

  // GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64 Register Class...
  const uint16_t GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64[] = {
    X86::RCX, X86::RDX, X86::RSI, X86::RDI, X86::R8, X86::R9, X86::R11, 
  };

  // GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64 Bit set.
  const uint8_t GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64Bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x80, 0x00, 0x00, 0xc0, 0x09, 
  };

  // GR64_NOREX_and_GR64_TC Register Class...
  const uint16_t GR64_NOREX_and_GR64_TC[] = {
    X86::RAX, X86::RCX, X86::RDX, X86::RSI, X86::RDI, X86::RIP, 
  };

  // GR64_NOREX_and_GR64_TC Bit set.
  const uint8_t GR64_NOREX_and_GR64_TCBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc8, 0x0b, 
  };

  // GR64_TCW64 Register Class...
  const uint16_t GR64_TCW64[] = {
    X86::RAX, X86::RCX, X86::RDX, X86::R8, X86::R9, X86::R11, 
  };

  // GR64_TCW64 Bit set.
  const uint8_t GR64_TCW64Bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x80, 0x00, 0x00, 0x48, 0x01, 
  };

  // GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSP Register Class...
  const uint16_t GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSP[] = {
    X86::RCX, X86::RDX, X86::RSI, X86::RDI, X86::RBX, X86::RBP, 
  };

  // GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSP Bit set.
  const uint8_t GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSPBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x09, 
  };

  // GR64_TCW64_and_GR64_with_sub_32bit_in_GR32_NOAX Register Class...
  const uint16_t GR64_TCW64_and_GR64_with_sub_32bit_in_GR32_NOAX[] = {
    X86::RCX, X86::RDX, X86::R8, X86::R9, X86::R11, 
  };

  // GR64_TCW64_and_GR64_with_sub_32bit_in_GR32_NOAX Bit set.
  const uint8_t GR64_TCW64_and_GR64_with_sub_32bit_in_GR32_NOAXBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x80, 0x00, 0x00, 0x40, 0x01, 
  };

  // GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64 Register Class...
  const uint16_t GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64[] = {
    X86::RAX, X86::RCX, X86::RDX, X86::RSI, X86::RDI, 
  };

  // GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64 Bit set.
  const uint8_t GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64Bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc8, 0x09, 
  };

  // GR64_ABCD Register Class...
  const uint16_t GR64_ABCD[] = {
    X86::RAX, X86::RCX, X86::RDX, X86::RBX, 
  };

  // GR64_ABCD Bit set.
  const uint8_t GR64_ABCDBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x68, 0x01, 
  };

  // GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64 Register Class...
  const uint16_t GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64[] = {
    X86::RCX, X86::RDX, X86::RSI, X86::RDI, 
  };

  // GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64 Bit set.
  const uint8_t GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64Bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x09, 
  };

  // GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAX Register Class...
  const uint16_t GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAX[] = {
    X86::RCX, X86::RDX, X86::RBX, 
  };

  // GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAX Bit set.
  const uint8_t GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAXBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x01, 
  };

  // GR64_with_sub_32bit_in_GR32_TC Register Class...
  const uint16_t GR64_with_sub_32bit_in_GR32_TC[] = {
    X86::RAX, X86::RCX, X86::RDX, 
  };

  // GR64_with_sub_32bit_in_GR32_TC Bit set.
  const uint8_t GR64_with_sub_32bit_in_GR32_TCBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x01, 
  };

  // GR64_with_sub_32bit_in_GR32_AD Register Class...
  const uint16_t GR64_with_sub_32bit_in_GR32_AD[] = {
    X86::RAX, X86::RDX, 
  };

  // GR64_with_sub_32bit_in_GR32_AD Bit set.
  const uint8_t GR64_with_sub_32bit_in_GR32_ADBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x01, 
  };

  // GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC Register Class...
  const uint16_t GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC[] = {
    X86::RCX, X86::RDX, 
  };

  // GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC Bit set.
  const uint8_t GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TCBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x01, 
  };

  // GR64_with_sub_32bit_in_GR32_AD_and_GR32_NOAX Register Class...
  const uint16_t GR64_with_sub_32bit_in_GR32_AD_and_GR32_NOAX[] = {
    X86::RDX, 
  };

  // GR64_with_sub_32bit_in_GR32_AD_and_GR32_NOAX Bit set.
  const uint8_t GR64_with_sub_32bit_in_GR32_AD_and_GR32_NOAXBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
  };

  // RST Register Class...
  const uint16_t RST[] = {
    X86::ST0, X86::ST1, X86::ST2, X86::ST3, X86::ST4, X86::ST5, X86::ST6, X86::ST7, 
  };

  // RST Bit set.
  const uint8_t RSTBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x03, 
  };

  // RFP80 Register Class...
  const uint16_t RFP80[] = {
    X86::FP0, X86::FP1, X86::FP2, X86::FP3, X86::FP4, X86::FP5, X86::FP6, 
  };

  // RFP80 Bit set.
  const uint8_t RFP80Bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 
  };

  // VR128 Register Class...
  const uint16_t VR128[] = {
    X86::XMM0, X86::XMM1, X86::XMM2, X86::XMM3, X86::XMM4, X86::XMM5, X86::XMM6, X86::XMM7, X86::XMM8, X86::XMM9, X86::XMM10, X86::XMM11, X86::XMM12, X86::XMM13, X86::XMM14, X86::XMM15, 
  };

  // VR128 Bit set.
  const uint8_t VR128Bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0x03, 
  };

  // VR256 Register Class...
  const uint16_t VR256[] = {
    X86::YMM0, X86::YMM1, X86::YMM2, X86::YMM3, X86::YMM4, X86::YMM5, X86::YMM6, X86::YMM7, X86::YMM8, X86::YMM9, X86::YMM10, X86::YMM11, X86::YMM12, X86::YMM13, X86::YMM14, X86::YMM15, 
  };

  // VR256 Bit set.
  const uint8_t VR256Bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0x03, 
  };

}

extern const MCRegisterClass X86MCRegisterClasses[] = {
  { "GR8", GR8, GR8Bits, 20, sizeof(GR8Bits), X86::GR8RegClassID, 1, 1, 1, 1 },
  { "GR8_NOREX", GR8_NOREX, GR8_NOREXBits, 8, sizeof(GR8_NOREXBits), X86::GR8_NOREXRegClassID, 1, 1, 1, 1 },
  { "GR8_ABCD_H", GR8_ABCD_H, GR8_ABCD_HBits, 4, sizeof(GR8_ABCD_HBits), X86::GR8_ABCD_HRegClassID, 1, 1, 1, 1 },
  { "GR8_ABCD_L", GR8_ABCD_L, GR8_ABCD_LBits, 4, sizeof(GR8_ABCD_LBits), X86::GR8_ABCD_LRegClassID, 1, 1, 1, 1 },
  { "GR16", GR16, GR16Bits, 16, sizeof(GR16Bits), X86::GR16RegClassID, 2, 2, 1, 1 },
  { "GR16_NOREX", GR16_NOREX, GR16_NOREXBits, 8, sizeof(GR16_NOREXBits), X86::GR16_NOREXRegClassID, 2, 2, 1, 1 },
  { "SEGMENT_REG", SEGMENT_REG, SEGMENT_REGBits, 6, sizeof(SEGMENT_REGBits), X86::SEGMENT_REGRegClassID, 2, 2, 1, 1 },
  { "GR16_ABCD", GR16_ABCD, GR16_ABCDBits, 4, sizeof(GR16_ABCDBits), X86::GR16_ABCDRegClassID, 2, 2, 1, 1 },
  { "FPCCR", FPCCR, FPCCRBits, 1, sizeof(FPCCRBits), X86::FPCCRRegClassID, 2, 2, -1, 0 },
  { "FR32", FR32, FR32Bits, 16, sizeof(FR32Bits), X86::FR32RegClassID, 4, 4, 1, 1 },
  { "GR32", GR32, GR32Bits, 16, sizeof(GR32Bits), X86::GR32RegClassID, 4, 4, 1, 1 },
  { "GR32_NOAX", GR32_NOAX, GR32_NOAXBits, 15, sizeof(GR32_NOAXBits), X86::GR32_NOAXRegClassID, 4, 4, 1, 1 },
  { "GR32_NOSP", GR32_NOSP, GR32_NOSPBits, 15, sizeof(GR32_NOSPBits), X86::GR32_NOSPRegClassID, 4, 4, 1, 1 },
  { "GR32_NOAX_and_GR32_NOSP", GR32_NOAX_and_GR32_NOSP, GR32_NOAX_and_GR32_NOSPBits, 14, sizeof(GR32_NOAX_and_GR32_NOSPBits), X86::GR32_NOAX_and_GR32_NOSPRegClassID, 4, 4, 1, 1 },
  { "DEBUG_REG", DEBUG_REG, DEBUG_REGBits, 8, sizeof(DEBUG_REGBits), X86::DEBUG_REGRegClassID, 4, 4, 1, 1 },
  { "GR32_NOREX", GR32_NOREX, GR32_NOREXBits, 8, sizeof(GR32_NOREXBits), X86::GR32_NOREXRegClassID, 4, 4, 1, 1 },
  { "GR32_TC_64", GR32_TC_64, GR32_TC_64Bits, 8, sizeof(GR32_TC_64Bits), X86::GR32_TC_64RegClassID, 4, 4, 1, 1 },
  { "GR32_NOAX_and_GR32_NOREX", GR32_NOAX_and_GR32_NOREX, GR32_NOAX_and_GR32_NOREXBits, 7, sizeof(GR32_NOAX_and_GR32_NOREXBits), X86::GR32_NOAX_and_GR32_NOREXRegClassID, 4, 4, 1, 1 },
  { "GR32_NOAX_and_GR32_TC_64", GR32_NOAX_and_GR32_TC_64, GR32_NOAX_and_GR32_TC_64Bits, 7, sizeof(GR32_NOAX_and_GR32_TC_64Bits), X86::GR32_NOAX_and_GR32_TC_64RegClassID, 4, 4, 1, 1 },
  { "GR32_NOREX_NOSP", GR32_NOREX_NOSP, GR32_NOREX_NOSPBits, 7, sizeof(GR32_NOREX_NOSPBits), X86::GR32_NOREX_NOSPRegClassID, 4, 4, 1, 1 },
  { "RFP32", RFP32, RFP32Bits, 7, sizeof(RFP32Bits), X86::RFP32RegClassID, 4, 4, 1, 1 },
  { "GR32_NOAX_and_GR32_NOREX_NOSP", GR32_NOAX_and_GR32_NOREX_NOSP, GR32_NOAX_and_GR32_NOREX_NOSPBits, 6, sizeof(GR32_NOAX_and_GR32_NOREX_NOSPBits), X86::GR32_NOAX_and_GR32_NOREX_NOSPRegClassID, 4, 4, 1, 1 },
  { "GR32_NOREX_and_GR32_TC_64", GR32_NOREX_and_GR32_TC_64, GR32_NOREX_and_GR32_TC_64Bits, 5, sizeof(GR32_NOREX_and_GR32_TC_64Bits), X86::GR32_NOREX_and_GR32_TC_64RegClassID, 4, 4, 1, 1 },
  { "GR32_ABCD", GR32_ABCD, GR32_ABCDBits, 4, sizeof(GR32_ABCDBits), X86::GR32_ABCDRegClassID, 4, 4, 1, 1 },
  { "GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64", GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64, GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64Bits, 4, sizeof(GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64Bits), X86::GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64RegClassID, 4, 4, 1, 1 },
  { "GR32_ABCD_and_GR32_NOAX", GR32_ABCD_and_GR32_NOAX, GR32_ABCD_and_GR32_NOAXBits, 3, sizeof(GR32_ABCD_and_GR32_NOAXBits), X86::GR32_ABCD_and_GR32_NOAXRegClassID, 4, 4, 1, 1 },
  { "GR32_TC", GR32_TC, GR32_TCBits, 3, sizeof(GR32_TCBits), X86::GR32_TCRegClassID, 4, 4, 1, 1 },
  { "GR32_AD", GR32_AD, GR32_ADBits, 2, sizeof(GR32_ADBits), X86::GR32_ADRegClassID, 4, 4, 1, 1 },
  { "GR32_NOAX_and_GR32_TC", GR32_NOAX_and_GR32_TC, GR32_NOAX_and_GR32_TCBits, 2, sizeof(GR32_NOAX_and_GR32_TCBits), X86::GR32_NOAX_and_GR32_TCRegClassID, 4, 4, 1, 1 },
  { "CCR", CCR, CCRBits, 1, sizeof(CCRBits), X86::CCRRegClassID, 4, 4, -1, 0 },
  { "GR32_AD_and_GR32_NOAX", GR32_AD_and_GR32_NOAX, GR32_AD_and_GR32_NOAXBits, 1, sizeof(GR32_AD_and_GR32_NOAXBits), X86::GR32_AD_and_GR32_NOAXRegClassID, 4, 4, 1, 1 },
  { "RFP64", RFP64, RFP64Bits, 7, sizeof(RFP64Bits), X86::RFP64RegClassID, 8, 4, 1, 1 },
  { "GR64", GR64, GR64Bits, 17, sizeof(GR64Bits), X86::GR64RegClassID, 8, 8, 1, 1 },
  { "CONTROL_REG", CONTROL_REG, CONTROL_REGBits, 16, sizeof(CONTROL_REGBits), X86::CONTROL_REGRegClassID, 8, 8, 1, 1 },
  { "FR64", FR64, FR64Bits, 16, sizeof(FR64Bits), X86::FR64RegClassID, 8, 8, 1, 1 },
  { "GR64_with_sub_8bit", GR64_with_sub_8bit, GR64_with_sub_8bitBits, 16, sizeof(GR64_with_sub_8bitBits), X86::GR64_with_sub_8bitRegClassID, 8, 8, 1, 1 },
  { "GR64_NOSP", GR64_NOSP, GR64_NOSPBits, 15, sizeof(GR64_NOSPBits), X86::GR64_NOSPRegClassID, 8, 8, 1, 1 },
  { "GR64_with_sub_32bit_in_GR32_NOAX", GR64_with_sub_32bit_in_GR32_NOAX, GR64_with_sub_32bit_in_GR32_NOAXBits, 15, sizeof(GR64_with_sub_32bit_in_GR32_NOAXBits), X86::GR64_with_sub_32bit_in_GR32_NOAXRegClassID, 8, 8, 1, 1 },
  { "GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSP", GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSP, GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSPBits, 14, sizeof(GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSPBits), X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSPRegClassID, 8, 8, 1, 1 },
  { "GR64_NOREX", GR64_NOREX, GR64_NOREXBits, 9, sizeof(GR64_NOREXBits), X86::GR64_NOREXRegClassID, 8, 8, 1, 1 },
  { "GR64_TC", GR64_TC, GR64_TCBits, 9, sizeof(GR64_TCBits), X86::GR64_TCRegClassID, 8, 8, 1, 1 },
  { "GR64_with_sub_16bit_in_GR16_NOREX", GR64_with_sub_16bit_in_GR16_NOREX, GR64_with_sub_16bit_in_GR16_NOREXBits, 8, sizeof(GR64_with_sub_16bit_in_GR16_NOREXBits), X86::GR64_with_sub_16bit_in_GR16_NOREXRegClassID, 8, 8, 1, 1 },
  { "GR64_with_sub_32bit_in_GR32_TC_64", GR64_with_sub_32bit_in_GR32_TC_64, GR64_with_sub_32bit_in_GR32_TC_64Bits, 8, sizeof(GR64_with_sub_32bit_in_GR32_TC_64Bits), X86::GR64_with_sub_32bit_in_GR32_TC_64RegClassID, 8, 8, 1, 1 },
  { "VR64", VR64, VR64Bits, 8, sizeof(VR64Bits), X86::VR64RegClassID, 8, 8, 1, 1 },
  { "GR64_NOREX_NOSP", GR64_NOREX_NOSP, GR64_NOREX_NOSPBits, 7, sizeof(GR64_NOREX_NOSPBits), X86::GR64_NOREX_NOSPRegClassID, 8, 8, 1, 1 },
  { "GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX", GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX, GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREXBits, 7, sizeof(GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREXBits), X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREXRegClassID, 8, 8, 1, 1 },
  { "GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64", GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64, GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64Bits, 7, sizeof(GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64Bits), X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64RegClassID, 8, 8, 1, 1 },
  { "GR64_NOREX_and_GR64_TC", GR64_NOREX_and_GR64_TC, GR64_NOREX_and_GR64_TCBits, 6, sizeof(GR64_NOREX_and_GR64_TCBits), X86::GR64_NOREX_and_GR64_TCRegClassID, 8, 8, 1, 1 },
  { "GR64_TCW64", GR64_TCW64, GR64_TCW64Bits, 6, sizeof(GR64_TCW64Bits), X86::GR64_TCW64RegClassID, 8, 8, 1, 1 },
  { "GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSP", GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSP, GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSPBits, 6, sizeof(GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSPBits), X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSPRegClassID, 8, 8, 1, 1 },
  { "GR64_TCW64_and_GR64_with_sub_32bit_in_GR32_NOAX", GR64_TCW64_and_GR64_with_sub_32bit_in_GR32_NOAX, GR64_TCW64_and_GR64_with_sub_32bit_in_GR32_NOAXBits, 5, sizeof(GR64_TCW64_and_GR64_with_sub_32bit_in_GR32_NOAXBits), X86::GR64_TCW64_and_GR64_with_sub_32bit_in_GR32_NOAXRegClassID, 8, 8, 1, 1 },
  { "GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64", GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64, GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64Bits, 5, sizeof(GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64Bits), X86::GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64RegClassID, 8, 8, 1, 1 },
  { "GR64_ABCD", GR64_ABCD, GR64_ABCDBits, 4, sizeof(GR64_ABCDBits), X86::GR64_ABCDRegClassID, 8, 8, 1, 1 },
  { "GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64", GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64, GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64Bits, 4, sizeof(GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64Bits), X86::GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64RegClassID, 8, 8, 1, 1 },
  { "GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAX", GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAX, GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAXBits, 3, sizeof(GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAXBits), X86::GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAXRegClassID, 8, 8, 1, 1 },
  { "GR64_with_sub_32bit_in_GR32_TC", GR64_with_sub_32bit_in_GR32_TC, GR64_with_sub_32bit_in_GR32_TCBits, 3, sizeof(GR64_with_sub_32bit_in_GR32_TCBits), X86::GR64_with_sub_32bit_in_GR32_TCRegClassID, 8, 8, 1, 1 },
  { "GR64_with_sub_32bit_in_GR32_AD", GR64_with_sub_32bit_in_GR32_AD, GR64_with_sub_32bit_in_GR32_ADBits, 2, sizeof(GR64_with_sub_32bit_in_GR32_ADBits), X86::GR64_with_sub_32bit_in_GR32_ADRegClassID, 8, 8, 1, 1 },
  { "GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC", GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC, GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TCBits, 2, sizeof(GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TCBits), X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TCRegClassID, 8, 8, 1, 1 },
  { "GR64_with_sub_32bit_in_GR32_AD_and_GR32_NOAX", GR64_with_sub_32bit_in_GR32_AD_and_GR32_NOAX, GR64_with_sub_32bit_in_GR32_AD_and_GR32_NOAXBits, 1, sizeof(GR64_with_sub_32bit_in_GR32_AD_and_GR32_NOAXBits), X86::GR64_with_sub_32bit_in_GR32_AD_and_GR32_NOAXRegClassID, 8, 8, 1, 1 },
  { "RST", RST, RSTBits, 8, sizeof(RSTBits), X86::RSTRegClassID, 10, 4, 1, 0 },
  { "RFP80", RFP80, RFP80Bits, 7, sizeof(RFP80Bits), X86::RFP80RegClassID, 10, 4, 1, 1 },
  { "VR128", VR128, VR128Bits, 16, sizeof(VR128Bits), X86::VR128RegClassID, 16, 16, 1, 1 },
  { "VR256", VR256, VR256Bits, 16, sizeof(VR256Bits), X86::VR256RegClassID, 32, 32, 1, 1 },
};

// X86 Dwarf<->LLVM register mappings.
extern const MCRegisterInfo::DwarfLLVMRegPair X86DwarfFlavour0Dwarf2L[] = {
  { 0U, X86::RAX },
  { 1U, X86::RDX },
  { 2U, X86::RCX },
  { 3U, X86::RBX },
  { 4U, X86::RSI },
  { 5U, X86::RDI },
  { 6U, X86::RBP },
  { 7U, X86::RSP },
  { 8U, X86::R8 },
  { 9U, X86::R9 },
  { 10U, X86::R10 },
  { 11U, X86::R11 },
  { 12U, X86::R12 },
  { 13U, X86::R13 },
  { 14U, X86::R14 },
  { 15U, X86::R15 },
  { 16U, X86::RIP },
  { 17U, X86::XMM0 },
  { 18U, X86::XMM1 },
  { 19U, X86::XMM2 },
  { 20U, X86::XMM3 },
  { 21U, X86::XMM4 },
  { 22U, X86::XMM5 },
  { 23U, X86::XMM6 },
  { 24U, X86::XMM7 },
  { 25U, X86::XMM8 },
  { 26U, X86::XMM9 },
  { 27U, X86::XMM10 },
  { 28U, X86::XMM11 },
  { 29U, X86::XMM12 },
  { 30U, X86::XMM13 },
  { 31U, X86::XMM14 },
  { 32U, X86::XMM15 },
  { 33U, X86::ST0 },
  { 34U, X86::ST1 },
  { 35U, X86::ST2 },
  { 36U, X86::ST3 },
  { 37U, X86::ST4 },
  { 38U, X86::ST5 },
  { 39U, X86::ST6 },
  { 40U, X86::ST7 },
  { 41U, X86::MM0 },
  { 42U, X86::MM1 },
  { 43U, X86::MM2 },
  { 44U, X86::MM3 },
  { 45U, X86::MM4 },
  { 46U, X86::MM5 },
  { 47U, X86::MM6 },
  { 48U, X86::MM7 },
};
extern const unsigned X86DwarfFlavour0Dwarf2LSize = sizeof(X86DwarfFlavour0Dwarf2L)/sizeof(MCRegisterInfo::DwarfLLVMRegPair);

extern const MCRegisterInfo::DwarfLLVMRegPair X86DwarfFlavour1Dwarf2L[] = {
  { 0U, X86::EAX },
  { 1U, X86::ECX },
  { 2U, X86::EDX },
  { 3U, X86::EBX },
  { 4U, X86::EBP },
  { 5U, X86::ESP },
  { 6U, X86::ESI },
  { 7U, X86::EDI },
  { 8U, X86::EIP },
  { 12U, X86::ST0 },
  { 13U, X86::ST1 },
  { 14U, X86::ST2 },
  { 15U, X86::ST3 },
  { 16U, X86::ST4 },
  { 17U, X86::ST5 },
  { 18U, X86::ST6 },
  { 19U, X86::ST7 },
  { 21U, X86::XMM0 },
  { 22U, X86::XMM1 },
  { 23U, X86::XMM2 },
  { 24U, X86::XMM3 },
  { 25U, X86::XMM4 },
  { 26U, X86::XMM5 },
  { 27U, X86::XMM6 },
  { 28U, X86::XMM7 },
  { 29U, X86::MM0 },
  { 30U, X86::MM1 },
  { 31U, X86::MM2 },
  { 32U, X86::MM3 },
  { 33U, X86::MM4 },
  { 34U, X86::MM5 },
  { 35U, X86::MM6 },
  { 36U, X86::MM7 },
};
extern const unsigned X86DwarfFlavour1Dwarf2LSize = sizeof(X86DwarfFlavour1Dwarf2L)/sizeof(MCRegisterInfo::DwarfLLVMRegPair);

extern const MCRegisterInfo::DwarfLLVMRegPair X86DwarfFlavour2Dwarf2L[] = {
  { 0U, X86::EAX },
  { 1U, X86::ECX },
  { 2U, X86::EDX },
  { 3U, X86::EBX },
  { 4U, X86::ESP },
  { 5U, X86::EBP },
  { 6U, X86::ESI },
  { 7U, X86::EDI },
  { 8U, X86::EIP },
  { 11U, X86::ST0 },
  { 12U, X86::ST1 },
  { 13U, X86::ST2 },
  { 14U, X86::ST3 },
  { 15U, X86::ST4 },
  { 16U, X86::ST5 },
  { 17U, X86::ST6 },
  { 18U, X86::ST7 },
  { 21U, X86::XMM0 },
  { 22U, X86::XMM1 },
  { 23U, X86::XMM2 },
  { 24U, X86::XMM3 },
  { 25U, X86::XMM4 },
  { 26U, X86::XMM5 },
  { 27U, X86::XMM6 },
  { 28U, X86::XMM7 },
  { 29U, X86::MM0 },
  { 30U, X86::MM1 },
  { 31U, X86::MM2 },
  { 32U, X86::MM3 },
  { 33U, X86::MM4 },
  { 34U, X86::MM5 },
  { 35U, X86::MM6 },
  { 36U, X86::MM7 },
};
extern const unsigned X86DwarfFlavour2Dwarf2LSize = sizeof(X86DwarfFlavour2Dwarf2L)/sizeof(MCRegisterInfo::DwarfLLVMRegPair);

extern const MCRegisterInfo::DwarfLLVMRegPair X86EHFlavour0Dwarf2L[] = {
  { 0U, X86::RAX },
  { 1U, X86::RDX },
  { 2U, X86::RCX },
  { 3U, X86::RBX },
  { 4U, X86::RSI },
  { 5U, X86::RDI },
  { 6U, X86::RBP },
  { 7U, X86::RSP },
  { 8U, X86::R8 },
  { 9U, X86::R9 },
  { 10U, X86::R10 },
  { 11U, X86::R11 },
  { 12U, X86::R12 },
  { 13U, X86::R13 },
  { 14U, X86::R14 },
  { 15U, X86::R15 },
  { 16U, X86::RIP },
  { 17U, X86::XMM0 },
  { 18U, X86::XMM1 },
  { 19U, X86::XMM2 },
  { 20U, X86::XMM3 },
  { 21U, X86::XMM4 },
  { 22U, X86::XMM5 },
  { 23U, X86::XMM6 },
  { 24U, X86::XMM7 },
  { 25U, X86::XMM8 },
  { 26U, X86::XMM9 },
  { 27U, X86::XMM10 },
  { 28U, X86::XMM11 },
  { 29U, X86::XMM12 },
  { 30U, X86::XMM13 },
  { 31U, X86::XMM14 },
  { 32U, X86::XMM15 },
  { 33U, X86::ST0 },
  { 34U, X86::ST1 },
  { 35U, X86::ST2 },
  { 36U, X86::ST3 },
  { 37U, X86::ST4 },
  { 38U, X86::ST5 },
  { 39U, X86::ST6 },
  { 40U, X86::ST7 },
  { 41U, X86::MM0 },
  { 42U, X86::MM1 },
  { 43U, X86::MM2 },
  { 44U, X86::MM3 },
  { 45U, X86::MM4 },
  { 46U, X86::MM5 },
  { 47U, X86::MM6 },
  { 48U, X86::MM7 },
};
extern const unsigned X86EHFlavour0Dwarf2LSize = sizeof(X86EHFlavour0Dwarf2L)/sizeof(MCRegisterInfo::DwarfLLVMRegPair);

extern const MCRegisterInfo::DwarfLLVMRegPair X86EHFlavour1Dwarf2L[] = {
  { 0U, X86::EAX },
  { 1U, X86::ECX },
  { 2U, X86::EDX },
  { 3U, X86::EBX },
  { 4U, X86::EBP },
  { 5U, X86::ESP },
  { 6U, X86::ESI },
  { 7U, X86::EDI },
  { 8U, X86::EIP },
  { 12U, X86::ST0 },
  { 13U, X86::ST1 },
  { 14U, X86::ST2 },
  { 15U, X86::ST3 },
  { 16U, X86::ST4 },
  { 17U, X86::ST5 },
  { 18U, X86::ST6 },
  { 19U, X86::ST7 },
  { 21U, X86::XMM0 },
  { 22U, X86::XMM1 },
  { 23U, X86::XMM2 },
  { 24U, X86::XMM3 },
  { 25U, X86::XMM4 },
  { 26U, X86::XMM5 },
  { 27U, X86::XMM6 },
  { 28U, X86::XMM7 },
  { 29U, X86::MM0 },
  { 30U, X86::MM1 },
  { 31U, X86::MM2 },
  { 32U, X86::MM3 },
  { 33U, X86::MM4 },
  { 34U, X86::MM5 },
  { 35U, X86::MM6 },
  { 36U, X86::MM7 },
};
extern const unsigned X86EHFlavour1Dwarf2LSize = sizeof(X86EHFlavour1Dwarf2L)/sizeof(MCRegisterInfo::DwarfLLVMRegPair);

extern const MCRegisterInfo::DwarfLLVMRegPair X86EHFlavour2Dwarf2L[] = {
  { 0U, X86::EAX },
  { 1U, X86::ECX },
  { 2U, X86::EDX },
  { 3U, X86::EBX },
  { 4U, X86::ESP },
  { 5U, X86::EBP },
  { 6U, X86::ESI },
  { 7U, X86::EDI },
  { 8U, X86::EIP },
  { 11U, X86::ST0 },
  { 12U, X86::ST1 },
  { 13U, X86::ST2 },
  { 14U, X86::ST3 },
  { 15U, X86::ST4 },
  { 16U, X86::ST5 },
  { 17U, X86::ST6 },
  { 18U, X86::ST7 },
  { 21U, X86::XMM0 },
  { 22U, X86::XMM1 },
  { 23U, X86::XMM2 },
  { 24U, X86::XMM3 },
  { 25U, X86::XMM4 },
  { 26U, X86::XMM5 },
  { 27U, X86::XMM6 },
  { 28U, X86::XMM7 },
  { 29U, X86::MM0 },
  { 30U, X86::MM1 },
  { 31U, X86::MM2 },
  { 32U, X86::MM3 },
  { 33U, X86::MM4 },
  { 34U, X86::MM5 },
  { 35U, X86::MM6 },
  { 36U, X86::MM7 },
};
extern const unsigned X86EHFlavour2Dwarf2LSize = sizeof(X86EHFlavour2Dwarf2L)/sizeof(MCRegisterInfo::DwarfLLVMRegPair);

extern const MCRegisterInfo::DwarfLLVMRegPair X86DwarfFlavour0L2Dwarf[] = {
  { X86::EAX, -2U },
  { X86::EBP, -2U },
  { X86::EBX, -2U },
  { X86::ECX, -2U },
  { X86::EDI, -2U },
  { X86::EDX, -2U },
  { X86::EIP, -2U },
  { X86::ESI, -2U },
  { X86::ESP, -2U },
  { X86::MM0, 41U },
  { X86::MM1, 42U },
  { X86::MM2, 43U },
  { X86::MM3, 44U },
  { X86::MM4, 45U },
  { X86::MM5, 46U },
  { X86::MM6, 47U },
  { X86::MM7, 48U },
  { X86::R8, 8U },
  { X86::R9, 9U },
  { X86::R10, 10U },
  { X86::R11, 11U },
  { X86::R12, 12U },
  { X86::R13, 13U },
  { X86::R14, 14U },
  { X86::R15, 15U },
  { X86::RAX, 0U },
  { X86::RBP, 6U },
  { X86::RBX, 3U },
  { X86::RCX, 2U },
  { X86::RDI, 5U },
  { X86::RDX, 1U },
  { X86::RIP, 16U },
  { X86::RSI, 4U },
  { X86::RSP, 7U },
  { X86::ST0, 33U },
  { X86::ST1, 34U },
  { X86::ST2, 35U },
  { X86::ST3, 36U },
  { X86::ST4, 37U },
  { X86::ST5, 38U },
  { X86::ST6, 39U },
  { X86::ST7, 40U },
  { X86::XMM0, 17U },
  { X86::XMM1, 18U },
  { X86::XMM2, 19U },
  { X86::XMM3, 20U },
  { X86::XMM4, 21U },
  { X86::XMM5, 22U },
  { X86::XMM6, 23U },
  { X86::XMM7, 24U },
  { X86::XMM8, 25U },
  { X86::XMM9, 26U },
  { X86::XMM10, 27U },
  { X86::XMM11, 28U },
  { X86::XMM12, 29U },
  { X86::XMM13, 30U },
  { X86::XMM14, 31U },
  { X86::XMM15, 32U },
  { X86::YMM0, 17U },
  { X86::YMM1, 18U },
  { X86::YMM2, 19U },
  { X86::YMM3, 20U },
  { X86::YMM4, 21U },
  { X86::YMM5, 22U },
  { X86::YMM6, 23U },
  { X86::YMM7, 24U },
  { X86::YMM8, 25U },
  { X86::YMM9, 26U },
  { X86::YMM10, 27U },
  { X86::YMM11, 28U },
  { X86::YMM12, 29U },
  { X86::YMM13, 30U },
  { X86::YMM14, 31U },
  { X86::YMM15, 32U },
};
extern const unsigned X86DwarfFlavour0L2DwarfSize = sizeof(X86DwarfFlavour0L2Dwarf)/sizeof(MCRegisterInfo::DwarfLLVMRegPair);

extern const MCRegisterInfo::DwarfLLVMRegPair X86DwarfFlavour1L2Dwarf[] = {
  { X86::EAX, 0U },
  { X86::EBP, 4U },
  { X86::EBX, 3U },
  { X86::ECX, 1U },
  { X86::EDI, 7U },
  { X86::EDX, 2U },
  { X86::EIP, 8U },
  { X86::ESI, 6U },
  { X86::ESP, 5U },
  { X86::MM0, 29U },
  { X86::MM1, 30U },
  { X86::MM2, 31U },
  { X86::MM3, 32U },
  { X86::MM4, 33U },
  { X86::MM5, 34U },
  { X86::MM6, 35U },
  { X86::MM7, 36U },
  { X86::R8, -2U },
  { X86::R9, -2U },
  { X86::R10, -2U },
  { X86::R11, -2U },
  { X86::R12, -2U },
  { X86::R13, -2U },
  { X86::R14, -2U },
  { X86::R15, -2U },
  { X86::RAX, -2U },
  { X86::RBP, -2U },
  { X86::RBX, -2U },
  { X86::RCX, -2U },
  { X86::RDI, -2U },
  { X86::RDX, -2U },
  { X86::RIP, -2U },
  { X86::RSI, -2U },
  { X86::RSP, -2U },
  { X86::ST0, 12U },
  { X86::ST1, 13U },
  { X86::ST2, 14U },
  { X86::ST3, 15U },
  { X86::ST4, 16U },
  { X86::ST5, 17U },
  { X86::ST6, 18U },
  { X86::ST7, 19U },
  { X86::XMM0, 21U },
  { X86::XMM1, 22U },
  { X86::XMM2, 23U },
  { X86::XMM3, 24U },
  { X86::XMM4, 25U },
  { X86::XMM5, 26U },
  { X86::XMM6, 27U },
  { X86::XMM7, 28U },
  { X86::XMM8, -2U },
  { X86::XMM9, -2U },
  { X86::XMM10, -2U },
  { X86::XMM11, -2U },
  { X86::XMM12, -2U },
  { X86::XMM13, -2U },
  { X86::XMM14, -2U },
  { X86::XMM15, -2U },
  { X86::YMM0, 21U },
  { X86::YMM1, 22U },
  { X86::YMM2, 23U },
  { X86::YMM3, 24U },
  { X86::YMM4, 25U },
  { X86::YMM5, 26U },
  { X86::YMM6, 27U },
  { X86::YMM7, 28U },
  { X86::YMM8, -2U },
  { X86::YMM9, -2U },
  { X86::YMM10, -2U },
  { X86::YMM11, -2U },
  { X86::YMM12, -2U },
  { X86::YMM13, -2U },
  { X86::YMM14, -2U },
  { X86::YMM15, -2U },
};
extern const unsigned X86DwarfFlavour1L2DwarfSize = sizeof(X86DwarfFlavour1L2Dwarf)/sizeof(MCRegisterInfo::DwarfLLVMRegPair);

extern const MCRegisterInfo::DwarfLLVMRegPair X86DwarfFlavour2L2Dwarf[] = {
  { X86::EAX, 0U },
  { X86::EBP, 5U },
  { X86::EBX, 3U },
  { X86::ECX, 1U },
  { X86::EDI, 7U },
  { X86::EDX, 2U },
  { X86::EIP, 8U },
  { X86::ESI, 6U },
  { X86::ESP, 4U },
  { X86::MM0, 29U },
  { X86::MM1, 30U },
  { X86::MM2, 31U },
  { X86::MM3, 32U },
  { X86::MM4, 33U },
  { X86::MM5, 34U },
  { X86::MM6, 35U },
  { X86::MM7, 36U },
  { X86::R8, -2U },
  { X86::R9, -2U },
  { X86::R10, -2U },
  { X86::R11, -2U },
  { X86::R12, -2U },
  { X86::R13, -2U },
  { X86::R14, -2U },
  { X86::R15, -2U },
  { X86::RAX, -2U },
  { X86::RBP, -2U },
  { X86::RBX, -2U },
  { X86::RCX, -2U },
  { X86::RDI, -2U },
  { X86::RDX, -2U },
  { X86::RIP, -2U },
  { X86::RSI, -2U },
  { X86::RSP, -2U },
  { X86::ST0, 11U },
  { X86::ST1, 12U },
  { X86::ST2, 13U },
  { X86::ST3, 14U },
  { X86::ST4, 15U },
  { X86::ST5, 16U },
  { X86::ST6, 17U },
  { X86::ST7, 18U },
  { X86::XMM0, 21U },
  { X86::XMM1, 22U },
  { X86::XMM2, 23U },
  { X86::XMM3, 24U },
  { X86::XMM4, 25U },
  { X86::XMM5, 26U },
  { X86::XMM6, 27U },
  { X86::XMM7, 28U },
  { X86::XMM8, -2U },
  { X86::XMM9, -2U },
  { X86::XMM10, -2U },
  { X86::XMM11, -2U },
  { X86::XMM12, -2U },
  { X86::XMM13, -2U },
  { X86::XMM14, -2U },
  { X86::XMM15, -2U },
  { X86::YMM0, 21U },
  { X86::YMM1, 22U },
  { X86::YMM2, 23U },
  { X86::YMM3, 24U },
  { X86::YMM4, 25U },
  { X86::YMM5, 26U },
  { X86::YMM6, 27U },
  { X86::YMM7, 28U },
  { X86::YMM8, -2U },
  { X86::YMM9, -2U },
  { X86::YMM10, -2U },
  { X86::YMM11, -2U },
  { X86::YMM12, -2U },
  { X86::YMM13, -2U },
  { X86::YMM14, -2U },
  { X86::YMM15, -2U },
};
extern const unsigned X86DwarfFlavour2L2DwarfSize = sizeof(X86DwarfFlavour2L2Dwarf)/sizeof(MCRegisterInfo::DwarfLLVMRegPair);

extern const MCRegisterInfo::DwarfLLVMRegPair X86EHFlavour0L2Dwarf[] = {
  { X86::EAX, -2U },
  { X86::EBP, -2U },
  { X86::EBX, -2U },
  { X86::ECX, -2U },
  { X86::EDI, -2U },
  { X86::EDX, -2U },
  { X86::EIP, -2U },
  { X86::ESI, -2U },
  { X86::ESP, -2U },
  { X86::MM0, 41U },
  { X86::MM1, 42U },
  { X86::MM2, 43U },
  { X86::MM3, 44U },
  { X86::MM4, 45U },
  { X86::MM5, 46U },
  { X86::MM6, 47U },
  { X86::MM7, 48U },
  { X86::R8, 8U },
  { X86::R9, 9U },
  { X86::R10, 10U },
  { X86::R11, 11U },
  { X86::R12, 12U },
  { X86::R13, 13U },
  { X86::R14, 14U },
  { X86::R15, 15U },
  { X86::RAX, 0U },
  { X86::RBP, 6U },
  { X86::RBX, 3U },
  { X86::RCX, 2U },
  { X86::RDI, 5U },
  { X86::RDX, 1U },
  { X86::RIP, 16U },
  { X86::RSI, 4U },
  { X86::RSP, 7U },
  { X86::ST0, 33U },
  { X86::ST1, 34U },
  { X86::ST2, 35U },
  { X86::ST3, 36U },
  { X86::ST4, 37U },
  { X86::ST5, 38U },
  { X86::ST6, 39U },
  { X86::ST7, 40U },
  { X86::XMM0, 17U },
  { X86::XMM1, 18U },
  { X86::XMM2, 19U },
  { X86::XMM3, 20U },
  { X86::XMM4, 21U },
  { X86::XMM5, 22U },
  { X86::XMM6, 23U },
  { X86::XMM7, 24U },
  { X86::XMM8, 25U },
  { X86::XMM9, 26U },
  { X86::XMM10, 27U },
  { X86::XMM11, 28U },
  { X86::XMM12, 29U },
  { X86::XMM13, 30U },
  { X86::XMM14, 31U },
  { X86::XMM15, 32U },
  { X86::YMM0, 17U },
  { X86::YMM1, 18U },
  { X86::YMM2, 19U },
  { X86::YMM3, 20U },
  { X86::YMM4, 21U },
  { X86::YMM5, 22U },
  { X86::YMM6, 23U },
  { X86::YMM7, 24U },
  { X86::YMM8, 25U },
  { X86::YMM9, 26U },
  { X86::YMM10, 27U },
  { X86::YMM11, 28U },
  { X86::YMM12, 29U },
  { X86::YMM13, 30U },
  { X86::YMM14, 31U },
  { X86::YMM15, 32U },
};
extern const unsigned X86EHFlavour0L2DwarfSize = sizeof(X86EHFlavour0L2Dwarf)/sizeof(MCRegisterInfo::DwarfLLVMRegPair);

extern const MCRegisterInfo::DwarfLLVMRegPair X86EHFlavour1L2Dwarf[] = {
  { X86::EAX, 0U },
  { X86::EBP, 4U },
  { X86::EBX, 3U },
  { X86::ECX, 1U },
  { X86::EDI, 7U },
  { X86::EDX, 2U },
  { X86::EIP, 8U },
  { X86::ESI, 6U },
  { X86::ESP, 5U },
  { X86::MM0, 29U },
  { X86::MM1, 30U },
  { X86::MM2, 31U },
  { X86::MM3, 32U },
  { X86::MM4, 33U },
  { X86::MM5, 34U },
  { X86::MM6, 35U },
  { X86::MM7, 36U },
  { X86::R8, -2U },
  { X86::R9, -2U },
  { X86::R10, -2U },
  { X86::R11, -2U },
  { X86::R12, -2U },
  { X86::R13, -2U },
  { X86::R14, -2U },
  { X86::R15, -2U },
  { X86::RAX, -2U },
  { X86::RBP, -2U },
  { X86::RBX, -2U },
  { X86::RCX, -2U },
  { X86::RDI, -2U },
  { X86::RDX, -2U },
  { X86::RIP, -2U },
  { X86::RSI, -2U },
  { X86::RSP, -2U },
  { X86::ST0, 12U },
  { X86::ST1, 13U },
  { X86::ST2, 14U },
  { X86::ST3, 15U },
  { X86::ST4, 16U },
  { X86::ST5, 17U },
  { X86::ST6, 18U },
  { X86::ST7, 19U },
  { X86::XMM0, 21U },
  { X86::XMM1, 22U },
  { X86::XMM2, 23U },
  { X86::XMM3, 24U },
  { X86::XMM4, 25U },
  { X86::XMM5, 26U },
  { X86::XMM6, 27U },
  { X86::XMM7, 28U },
  { X86::XMM8, -2U },
  { X86::XMM9, -2U },
  { X86::XMM10, -2U },
  { X86::XMM11, -2U },
  { X86::XMM12, -2U },
  { X86::XMM13, -2U },
  { X86::XMM14, -2U },
  { X86::XMM15, -2U },
  { X86::YMM0, 21U },
  { X86::YMM1, 22U },
  { X86::YMM2, 23U },
  { X86::YMM3, 24U },
  { X86::YMM4, 25U },
  { X86::YMM5, 26U },
  { X86::YMM6, 27U },
  { X86::YMM7, 28U },
  { X86::YMM8, -2U },
  { X86::YMM9, -2U },
  { X86::YMM10, -2U },
  { X86::YMM11, -2U },
  { X86::YMM12, -2U },
  { X86::YMM13, -2U },
  { X86::YMM14, -2U },
  { X86::YMM15, -2U },
};
extern const unsigned X86EHFlavour1L2DwarfSize = sizeof(X86EHFlavour1L2Dwarf)/sizeof(MCRegisterInfo::DwarfLLVMRegPair);

extern const MCRegisterInfo::DwarfLLVMRegPair X86EHFlavour2L2Dwarf[] = {
  { X86::EAX, 0U },
  { X86::EBP, 5U },
  { X86::EBX, 3U },
  { X86::ECX, 1U },
  { X86::EDI, 7U },
  { X86::EDX, 2U },
  { X86::EIP, 8U },
  { X86::ESI, 6U },
  { X86::ESP, 4U },
  { X86::MM0, 29U },
  { X86::MM1, 30U },
  { X86::MM2, 31U },
  { X86::MM3, 32U },
  { X86::MM4, 33U },
  { X86::MM5, 34U },
  { X86::MM6, 35U },
  { X86::MM7, 36U },
  { X86::R8, -2U },
  { X86::R9, -2U },
  { X86::R10, -2U },
  { X86::R11, -2U },
  { X86::R12, -2U },
  { X86::R13, -2U },
  { X86::R14, -2U },
  { X86::R15, -2U },
  { X86::RAX, -2U },
  { X86::RBP, -2U },
  { X86::RBX, -2U },
  { X86::RCX, -2U },
  { X86::RDI, -2U },
  { X86::RDX, -2U },
  { X86::RIP, -2U },
  { X86::RSI, -2U },
  { X86::RSP, -2U },
  { X86::ST0, 11U },
  { X86::ST1, 12U },
  { X86::ST2, 13U },
  { X86::ST3, 14U },
  { X86::ST4, 15U },
  { X86::ST5, 16U },
  { X86::ST6, 17U },
  { X86::ST7, 18U },
  { X86::XMM0, 21U },
  { X86::XMM1, 22U },
  { X86::XMM2, 23U },
  { X86::XMM3, 24U },
  { X86::XMM4, 25U },
  { X86::XMM5, 26U },
  { X86::XMM6, 27U },
  { X86::XMM7, 28U },
  { X86::XMM8, -2U },
  { X86::XMM9, -2U },
  { X86::XMM10, -2U },
  { X86::XMM11, -2U },
  { X86::XMM12, -2U },
  { X86::XMM13, -2U },
  { X86::XMM14, -2U },
  { X86::XMM15, -2U },
  { X86::YMM0, 21U },
  { X86::YMM1, 22U },
  { X86::YMM2, 23U },
  { X86::YMM3, 24U },
  { X86::YMM4, 25U },
  { X86::YMM5, 26U },
  { X86::YMM6, 27U },
  { X86::YMM7, 28U },
  { X86::YMM8, -2U },
  { X86::YMM9, -2U },
  { X86::YMM10, -2U },
  { X86::YMM11, -2U },
  { X86::YMM12, -2U },
  { X86::YMM13, -2U },
  { X86::YMM14, -2U },
  { X86::YMM15, -2U },
};
extern const unsigned X86EHFlavour2L2DwarfSize = sizeof(X86EHFlavour2L2Dwarf)/sizeof(MCRegisterInfo::DwarfLLVMRegPair);

extern const uint16_t X86RegEncodingTable[] = {
  0,
  4,
  0,
  0,
  7,
  3,
  5,
  5,
  3,
  5,
  1,
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
  12,
  13,
  14,
  15,
  1,
  1,
  6,
  7,
  7,
  2,
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  3,
  2,
  0,
  5,
  3,
  1,
  7,
  2,
  0,
  0,
  4,
  0,
  6,
  4,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  4,
  5,
  0,
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  4,
  8,
  8,
  8,
  8,
  9,
  9,
  9,
  9,
  10,
  10,
  10,
  10,
  11,
  11,
  11,
  11,
  12,
  12,
  12,
  12,
  13,
  13,
  13,
  13,
  14,
  14,
  14,
  14,
  15,
  15,
  15,
  15,
  0,
  5,
  3,
  1,
  7,
  2,
  0,
  4,
  6,
  4,
  6,
  6,
  4,
  4,
  2,
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
  12,
  13,
  14,
  15,
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
  12,
  13,
  14,
  15,
};
static inline void InitX86MCRegisterInfo(MCRegisterInfo *RI, unsigned RA, unsigned DwarfFlavour = 0, unsigned EHFlavour = 0, unsigned PC = 0) {
  RI->InitMCRegisterInfo(X86RegDesc, 162, RA, PC, X86MCRegisterClasses, 63, X86RegUnitRoots, 88, X86RegDiffLists, X86RegStrings, X86SubRegIdxLists, 6,
  X86RegEncodingTable);

  switch (DwarfFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    RI->mapDwarfRegsToLLVMRegs(X86DwarfFlavour0Dwarf2L, X86DwarfFlavour0Dwarf2LSize, false);
    break;
  case 1:
    RI->mapDwarfRegsToLLVMRegs(X86DwarfFlavour1Dwarf2L, X86DwarfFlavour1Dwarf2LSize, false);
    break;
  case 2:
    RI->mapDwarfRegsToLLVMRegs(X86DwarfFlavour2Dwarf2L, X86DwarfFlavour2Dwarf2LSize, false);
    break;
  }
  switch (EHFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    RI->mapDwarfRegsToLLVMRegs(X86EHFlavour0Dwarf2L, X86EHFlavour0Dwarf2LSize, true);
    break;
  case 1:
    RI->mapDwarfRegsToLLVMRegs(X86EHFlavour1Dwarf2L, X86EHFlavour1Dwarf2LSize, true);
    break;
  case 2:
    RI->mapDwarfRegsToLLVMRegs(X86EHFlavour2Dwarf2L, X86EHFlavour2Dwarf2LSize, true);
    break;
  }
  switch (DwarfFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    RI->mapLLVMRegsToDwarfRegs(X86DwarfFlavour0L2Dwarf, X86DwarfFlavour0L2DwarfSize, false);
    break;
  case 1:
    RI->mapLLVMRegsToDwarfRegs(X86DwarfFlavour1L2Dwarf, X86DwarfFlavour1L2DwarfSize, false);
    break;
  case 2:
    RI->mapLLVMRegsToDwarfRegs(X86DwarfFlavour2L2Dwarf, X86DwarfFlavour2L2DwarfSize, false);
    break;
  }
  switch (EHFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    RI->mapLLVMRegsToDwarfRegs(X86EHFlavour0L2Dwarf, X86EHFlavour0L2DwarfSize, true);
    break;
  case 1:
    RI->mapLLVMRegsToDwarfRegs(X86EHFlavour1L2Dwarf, X86EHFlavour1L2DwarfSize, true);
    break;
  case 2:
    RI->mapLLVMRegsToDwarfRegs(X86EHFlavour2L2Dwarf, X86EHFlavour2L2DwarfSize, true);
    break;
  }
}

} // End llvm namespace 
#endif // GET_REGINFO_MC_DESC

/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*Register Information Header Fragment                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_HEADER
#undef GET_REGINFO_HEADER
#include "llvm/Target/TargetRegisterInfo.h"

namespace llvm {

struct X86GenRegisterInfo : public TargetRegisterInfo {
  explicit X86GenRegisterInfo(unsigned RA, unsigned D = 0, unsigned E = 0, unsigned PC = 0);
  virtual bool needsStackRealignment(const MachineFunction &) const
     { return false; }
  virtual unsigned composeSubRegIndicesImpl(unsigned, unsigned) const;
  virtual const TargetRegisterClass *getSubClassWithSubReg(const TargetRegisterClass*, unsigned) const;
  virtual const RegClassWeight &getRegClassWeight(const TargetRegisterClass *RC) const;
  virtual unsigned getRegUnitWeight(unsigned RegUnit) const;
  virtual unsigned getNumRegPressureSets() const;
  virtual const char *getRegPressureSetName(unsigned Idx) const;
  virtual unsigned getRegPressureSetLimit(unsigned Idx) const;
  virtual const int *getRegClassPressureSets(const TargetRegisterClass *RC) const;
  virtual const int *getRegUnitPressureSets(unsigned RegUnit) const;
};

namespace X86 { // Register classes
  extern const TargetRegisterClass GR8RegClass;
  extern const TargetRegisterClass GR8_NOREXRegClass;
  extern const TargetRegisterClass GR8_ABCD_HRegClass;
  extern const TargetRegisterClass GR8_ABCD_LRegClass;
  extern const TargetRegisterClass GR16RegClass;
  extern const TargetRegisterClass GR16_NOREXRegClass;
  extern const TargetRegisterClass SEGMENT_REGRegClass;
  extern const TargetRegisterClass GR16_ABCDRegClass;
  extern const TargetRegisterClass FPCCRRegClass;
  extern const TargetRegisterClass FR32RegClass;
  extern const TargetRegisterClass GR32RegClass;
  extern const TargetRegisterClass GR32_NOAXRegClass;
  extern const TargetRegisterClass GR32_NOSPRegClass;
  extern const TargetRegisterClass GR32_NOAX_and_GR32_NOSPRegClass;
  extern const TargetRegisterClass DEBUG_REGRegClass;
  extern const TargetRegisterClass GR32_NOREXRegClass;
  extern const TargetRegisterClass GR32_TC_64RegClass;
  extern const TargetRegisterClass GR32_NOAX_and_GR32_NOREXRegClass;
  extern const TargetRegisterClass GR32_NOAX_and_GR32_TC_64RegClass;
  extern const TargetRegisterClass GR32_NOREX_NOSPRegClass;
  extern const TargetRegisterClass RFP32RegClass;
  extern const TargetRegisterClass GR32_NOAX_and_GR32_NOREX_NOSPRegClass;
  extern const TargetRegisterClass GR32_NOREX_and_GR32_TC_64RegClass;
  extern const TargetRegisterClass GR32_ABCDRegClass;
  extern const TargetRegisterClass GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64RegClass;
  extern const TargetRegisterClass GR32_ABCD_and_GR32_NOAXRegClass;
  extern const TargetRegisterClass GR32_TCRegClass;
  extern const TargetRegisterClass GR32_ADRegClass;
  extern const TargetRegisterClass GR32_NOAX_and_GR32_TCRegClass;
  extern const TargetRegisterClass CCRRegClass;
  extern const TargetRegisterClass GR32_AD_and_GR32_NOAXRegClass;
  extern const TargetRegisterClass RFP64RegClass;
  extern const TargetRegisterClass GR64RegClass;
  extern const TargetRegisterClass CONTROL_REGRegClass;
  extern const TargetRegisterClass FR64RegClass;
  extern const TargetRegisterClass GR64_with_sub_8bitRegClass;
  extern const TargetRegisterClass GR64_NOSPRegClass;
  extern const TargetRegisterClass GR64_with_sub_32bit_in_GR32_NOAXRegClass;
  extern const TargetRegisterClass GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSPRegClass;
  extern const TargetRegisterClass GR64_NOREXRegClass;
  extern const TargetRegisterClass GR64_TCRegClass;
  extern const TargetRegisterClass GR64_with_sub_16bit_in_GR16_NOREXRegClass;
  extern const TargetRegisterClass GR64_with_sub_32bit_in_GR32_TC_64RegClass;
  extern const TargetRegisterClass VR64RegClass;
  extern const TargetRegisterClass GR64_NOREX_NOSPRegClass;
  extern const TargetRegisterClass GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREXRegClass;
  extern const TargetRegisterClass GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64RegClass;
  extern const TargetRegisterClass GR64_NOREX_and_GR64_TCRegClass;
  extern const TargetRegisterClass GR64_TCW64RegClass;
  extern const TargetRegisterClass GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSPRegClass;
  extern const TargetRegisterClass GR64_TCW64_and_GR64_with_sub_32bit_in_GR32_NOAXRegClass;
  extern const TargetRegisterClass GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64RegClass;
  extern const TargetRegisterClass GR64_ABCDRegClass;
  extern const TargetRegisterClass GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64RegClass;
  extern const TargetRegisterClass GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAXRegClass;
  extern const TargetRegisterClass GR64_with_sub_32bit_in_GR32_TCRegClass;
  extern const TargetRegisterClass GR64_with_sub_32bit_in_GR32_ADRegClass;
  extern const TargetRegisterClass GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TCRegClass;
  extern const TargetRegisterClass GR64_with_sub_32bit_in_GR32_AD_and_GR32_NOAXRegClass;
  extern const TargetRegisterClass RSTRegClass;
  extern const TargetRegisterClass RFP80RegClass;
  extern const TargetRegisterClass VR128RegClass;
  extern const TargetRegisterClass VR256RegClass;
} // end of namespace X86

} // End llvm namespace 
#endif // GET_REGINFO_HEADER

/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*Target Register and Register Classes Information                            *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_TARGET_DESC
#undef GET_REGINFO_TARGET_DESC
namespace llvm {

extern const MCRegisterClass X86MCRegisterClasses[];

static const MVT::SimpleValueType VTLists[] = {
  /* 0 */ MVT::i8, MVT::Other,
  /* 2 */ MVT::i16, MVT::Other,
  /* 4 */ MVT::i32, MVT::Other,
  /* 6 */ MVT::i64, MVT::Other,
  /* 8 */ MVT::f80, MVT::f64, MVT::f32, MVT::Other,
  /* 12 */ MVT::f64, MVT::Other,
  /* 14 */ MVT::f80, MVT::Other,
  /* 16 */ MVT::v16i8, MVT::v8i16, MVT::v4i32, MVT::v2i64, MVT::v4f32, MVT::v2f64, MVT::Other,
  /* 23 */ MVT::v32i8, MVT::v16i16, MVT::v8i32, MVT::v4i64, MVT::v8f32, MVT::v4f64, MVT::Other,
  /* 30 */ MVT::x86mmx, MVT::Other,
};

static const char *const SubRegIndexNameTable[] = { "sub_8bit", "sub_8bit_hi", "sub_16bit", "sub_32bit", "sub_xmm" };


static const unsigned SubRegIndexLaneMaskTable[] = {
  ~0u,
  0x00000001, // sub_8bit
  0x00000002, // sub_8bit_hi
  0x00000003, // sub_16bit
  0x00000003, // sub_32bit
  0x00000004, // sub_xmm
 };



static const TargetRegisterClass *const NullRegClasses[] = { NULL };

static const uint32_t GR8SubClassMask[] = {
  0x0000000f, 0x00000000, 
  0x5fefbcb0, 0x07ff7678, // sub_8bit
  0x5e800080, 0x07d00000, // sub_8bit_hi
};

static const uint32_t GR8_NOREXSubClassMask[] = {
  0x0000000e, 0x00000000, 
  0x5e800080, 0x07d00000, // sub_8bit
  0x5e800080, 0x07d00000, // sub_8bit_hi
};

static const uint32_t GR8_ABCD_HSubClassMask[] = {
  0x00000004, 0x00000000, 
  0x5e800080, 0x07d00000, // sub_8bit_hi
};

static const uint32_t GR8_ABCD_LSubClassMask[] = {
  0x00000008, 0x00000000, 
  0x5e800080, 0x07d00000, // sub_8bit
};

static const uint32_t GR16SubClassMask[] = {
  0x000000b0, 0x00000000, 
  0x5fefbc00, 0x07ff7678, // sub_16bit
};

static const uint32_t GR16_NOREXSubClassMask[] = {
  0x000000a0, 0x00000000, 
  0x5fea8000, 0x07fa3200, // sub_16bit
};

static const uint32_t SEGMENT_REGSubClassMask[] = {
  0x00000040, 0x00000000, 
};

static const uint32_t GR16_ABCDSubClassMask[] = {
  0x00000080, 0x00000000, 
  0x5e800000, 0x07d00000, // sub_16bit
};

static const uint32_t FPCCRSubClassMask[] = {
  0x00000100, 0x00000000, 
};

static const uint32_t FR32SubClassMask[] = {
  0x00000200, 0x20000004, 
  0x00000000, 0x40000000, // sub_xmm
};

static const uint32_t GR32SubClassMask[] = {
  0x5fefbc00, 0x00000000, 
  0x00000000, 0x07ff7678, // sub_32bit
};

static const uint32_t GR32_NOAXSubClassMask[] = {
  0x53262800, 0x00000000, 
  0x00000000, 0x06666060, // sub_32bit
};

static const uint32_t GR32_NOSPSubClassMask[] = {
  0x5fed3000, 0x00000000, 
  0x00000000, 0x07ff5450, // sub_32bit
};

static const uint32_t GR32_NOAX_and_GR32_NOSPSubClassMask[] = {
  0x53242000, 0x00000000, 
  0x00000000, 0x06664040, // sub_32bit
};

static const uint32_t DEBUG_REGSubClassMask[] = {
  0x00004000, 0x00000000, 
};

static const uint32_t GR32_NOREXSubClassMask[] = {
  0x5fea8000, 0x00000000, 
  0x00000000, 0x07fa3200, // sub_32bit
};

static const uint32_t GR32_TC_64SubClassMask[] = {
  0x5d450000, 0x00000000, 
  0x00000000, 0x07ad4400, // sub_32bit
};

static const uint32_t GR32_NOAX_and_GR32_NOREXSubClassMask[] = {
  0x53220000, 0x00000000, 
  0x00000000, 0x06622000, // sub_32bit
};

static const uint32_t GR32_NOAX_and_GR32_TC_64SubClassMask[] = {
  0x51040000, 0x00000000, 
  0x00000000, 0x06244000, // sub_32bit
};

static const uint32_t GR32_NOREX_NOSPSubClassMask[] = {
  0x5fe80000, 0x00000000, 
  0x00000000, 0x07fa1000, // sub_32bit
};

static const uint32_t RFP32SubClassMask[] = {
  0x80100000, 0x10000000, 
};

static const uint32_t GR32_NOAX_and_GR32_NOREX_NOSPSubClassMask[] = {
  0x53200000, 0x00000000, 
  0x00000000, 0x06620000, // sub_32bit
};

static const uint32_t GR32_NOREX_and_GR32_TC_64SubClassMask[] = {
  0x5d400000, 0x00000000, 
  0x00000000, 0x07a80000, // sub_32bit
};

static const uint32_t GR32_ABCDSubClassMask[] = {
  0x5e800000, 0x00000000, 
  0x00000000, 0x07d00000, // sub_32bit
};

static const uint32_t GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64SubClassMask[] = {
  0x51000000, 0x00000000, 
  0x00000000, 0x06200000, // sub_32bit
};

static const uint32_t GR32_ABCD_and_GR32_NOAXSubClassMask[] = {
  0x52000000, 0x00000000, 
  0x00000000, 0x06400000, // sub_32bit
};

static const uint32_t GR32_TCSubClassMask[] = {
  0x5c000000, 0x00000000, 
  0x00000000, 0x07800000, // sub_32bit
};

static const uint32_t GR32_ADSubClassMask[] = {
  0x48000000, 0x00000000, 
  0x00000000, 0x05000000, // sub_32bit
};

static const uint32_t GR32_NOAX_and_GR32_TCSubClassMask[] = {
  0x50000000, 0x00000000, 
  0x00000000, 0x06000000, // sub_32bit
};

static const uint32_t CCRSubClassMask[] = {
  0x20000000, 0x00000000, 
};

static const uint32_t GR32_AD_and_GR32_NOAXSubClassMask[] = {
  0x40000000, 0x00000000, 
  0x00000000, 0x04000000, // sub_32bit
};

static const uint32_t RFP64SubClassMask[] = {
  0x80000000, 0x10000000, 
};

static const uint32_t GR64SubClassMask[] = {
  0x00000000, 0x07fff7f9, 
};

static const uint32_t CONTROL_REGSubClassMask[] = {
  0x00000000, 0x00000002, 
};

static const uint32_t FR64SubClassMask[] = {
  0x00000000, 0x20000004, 
  0x00000000, 0x40000000, // sub_xmm
};

static const uint32_t GR64_with_sub_8bitSubClassMask[] = {
  0x00000000, 0x07ff7678, 
};

static const uint32_t GR64_NOSPSubClassMask[] = {
  0x00000000, 0x07ff5450, 
};

static const uint32_t GR64_with_sub_32bit_in_GR32_NOAXSubClassMask[] = {
  0x00000000, 0x06666060, 
};

static const uint32_t GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSPSubClassMask[] = {
  0x00000000, 0x06664040, 
};

static const uint32_t GR64_NOREXSubClassMask[] = {
  0x00000000, 0x07fab280, 
};

static const uint32_t GR64_TCSubClassMask[] = {
  0x00000000, 0x07adc500, 
};

static const uint32_t GR64_with_sub_16bit_in_GR16_NOREXSubClassMask[] = {
  0x00000000, 0x07fa3200, 
};

static const uint32_t GR64_with_sub_32bit_in_GR32_TC_64SubClassMask[] = {
  0x00000000, 0x07ad4400, 
};

static const uint32_t VR64SubClassMask[] = {
  0x00000000, 0x00000800, 
};

static const uint32_t GR64_NOREX_NOSPSubClassMask[] = {
  0x00000000, 0x07fa1000, 
};

static const uint32_t GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREXSubClassMask[] = {
  0x00000000, 0x06622000, 
};

static const uint32_t GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64SubClassMask[] = {
  0x00000000, 0x06244000, 
};

static const uint32_t GR64_NOREX_and_GR64_TCSubClassMask[] = {
  0x00000000, 0x07a88000, 
};

static const uint32_t GR64_TCW64SubClassMask[] = {
  0x00000000, 0x07850000, 
};

static const uint32_t GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSPSubClassMask[] = {
  0x00000000, 0x06620000, 
};

static const uint32_t GR64_TCW64_and_GR64_with_sub_32bit_in_GR32_NOAXSubClassMask[] = {
  0x00000000, 0x06040000, 
};

static const uint32_t GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64SubClassMask[] = {
  0x00000000, 0x07a80000, 
};

static const uint32_t GR64_ABCDSubClassMask[] = {
  0x00000000, 0x07d00000, 
};

static const uint32_t GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64SubClassMask[] = {
  0x00000000, 0x06200000, 
};

static const uint32_t GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAXSubClassMask[] = {
  0x00000000, 0x06400000, 
};

static const uint32_t GR64_with_sub_32bit_in_GR32_TCSubClassMask[] = {
  0x00000000, 0x07800000, 
};

static const uint32_t GR64_with_sub_32bit_in_GR32_ADSubClassMask[] = {
  0x00000000, 0x05000000, 
};

static const uint32_t GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TCSubClassMask[] = {
  0x00000000, 0x06000000, 
};

static const uint32_t GR64_with_sub_32bit_in_GR32_AD_and_GR32_NOAXSubClassMask[] = {
  0x00000000, 0x04000000, 
};

static const uint32_t RSTSubClassMask[] = {
  0x00000000, 0x08000000, 
};

static const uint32_t RFP80SubClassMask[] = {
  0x00000000, 0x10000000, 
};

static const uint32_t VR128SubClassMask[] = {
  0x00000000, 0x20000000, 
  0x00000000, 0x40000000, // sub_xmm
};

static const uint32_t VR256SubClassMask[] = {
  0x00000000, 0x40000000, 
};

static const uint16_t SuperRegIdxSeqs[] = {
  /* 0 */ 1, 0,
  /* 2 */ 1, 2, 0,
  /* 5 */ 3, 0,
  /* 7 */ 4, 0,
  /* 9 */ 5, 0,
};

static const TargetRegisterClass *const GR8_NOREXSuperclasses[] = {
  &X86::GR8RegClass,
  NULL
};

static const TargetRegisterClass *const GR8_ABCD_HSuperclasses[] = {
  &X86::GR8RegClass,
  &X86::GR8_NOREXRegClass,
  NULL
};

static const TargetRegisterClass *const GR8_ABCD_LSuperclasses[] = {
  &X86::GR8RegClass,
  &X86::GR8_NOREXRegClass,
  NULL
};

static const TargetRegisterClass *const GR16_NOREXSuperclasses[] = {
  &X86::GR16RegClass,
  NULL
};

static const TargetRegisterClass *const GR16_ABCDSuperclasses[] = {
  &X86::GR16RegClass,
  &X86::GR16_NOREXRegClass,
  NULL
};

static const TargetRegisterClass *const GR32_NOAXSuperclasses[] = {
  &X86::GR32RegClass,
  NULL
};

static const TargetRegisterClass *const GR32_NOSPSuperclasses[] = {
  &X86::GR32RegClass,
  NULL
};

static const TargetRegisterClass *const GR32_NOAX_and_GR32_NOSPSuperclasses[] = {
  &X86::GR32RegClass,
  &X86::GR32_NOAXRegClass,
  &X86::GR32_NOSPRegClass,
  NULL
};

static const TargetRegisterClass *const GR32_NOREXSuperclasses[] = {
  &X86::GR32RegClass,
  NULL
};

static const TargetRegisterClass *const GR32_TC_64Superclasses[] = {
  &X86::GR32RegClass,
  &X86::GR32_NOSPRegClass,
  NULL
};

static const TargetRegisterClass *const GR32_NOAX_and_GR32_NOREXSuperclasses[] = {
  &X86::GR32RegClass,
  &X86::GR32_NOAXRegClass,
  &X86::GR32_NOREXRegClass,
  NULL
};

static const TargetRegisterClass *const GR32_NOAX_and_GR32_TC_64Superclasses[] = {
  &X86::GR32RegClass,
  &X86::GR32_NOAXRegClass,
  &X86::GR32_NOSPRegClass,
  &X86::GR32_NOAX_and_GR32_NOSPRegClass,
  &X86::GR32_TC_64RegClass,
  NULL
};

static const TargetRegisterClass *const GR32_NOREX_NOSPSuperclasses[] = {
  &X86::GR32RegClass,
  &X86::GR32_NOSPRegClass,
  &X86::GR32_NOREXRegClass,
  NULL
};

static const TargetRegisterClass *const GR32_NOAX_and_GR32_NOREX_NOSPSuperclasses[] = {
  &X86::GR32RegClass,
  &X86::GR32_NOAXRegClass,
  &X86::GR32_NOSPRegClass,
  &X86::GR32_NOAX_and_GR32_NOSPRegClass,
  &X86::GR32_NOREXRegClass,
  &X86::GR32_NOAX_and_GR32_NOREXRegClass,
  &X86::GR32_NOREX_NOSPRegClass,
  NULL
};

static const TargetRegisterClass *const GR32_NOREX_and_GR32_TC_64Superclasses[] = {
  &X86::GR32RegClass,
  &X86::GR32_NOSPRegClass,
  &X86::GR32_NOREXRegClass,
  &X86::GR32_TC_64RegClass,
  &X86::GR32_NOREX_NOSPRegClass,
  NULL
};

static const TargetRegisterClass *const GR32_ABCDSuperclasses[] = {
  &X86::GR32RegClass,
  &X86::GR32_NOSPRegClass,
  &X86::GR32_NOREXRegClass,
  &X86::GR32_NOREX_NOSPRegClass,
  NULL
};

static const TargetRegisterClass *const GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64Superclasses[] = {
  &X86::GR32RegClass,
  &X86::GR32_NOAXRegClass,
  &X86::GR32_NOSPRegClass,
  &X86::GR32_NOAX_and_GR32_NOSPRegClass,
  &X86::GR32_NOREXRegClass,
  &X86::GR32_TC_64RegClass,
  &X86::GR32_NOAX_and_GR32_NOREXRegClass,
  &X86::GR32_NOAX_and_GR32_TC_64RegClass,
  &X86::GR32_NOREX_NOSPRegClass,
  &X86::GR32_NOAX_and_GR32_NOREX_NOSPRegClass,
  &X86::GR32_NOREX_and_GR32_TC_64RegClass,
  NULL
};

static const TargetRegisterClass *const GR32_ABCD_and_GR32_NOAXSuperclasses[] = {
  &X86::GR32RegClass,
  &X86::GR32_NOAXRegClass,
  &X86::GR32_NOSPRegClass,
  &X86::GR32_NOAX_and_GR32_NOSPRegClass,
  &X86::GR32_NOREXRegClass,
  &X86::GR32_NOAX_and_GR32_NOREXRegClass,
  &X86::GR32_NOREX_NOSPRegClass,
  &X86::GR32_NOAX_and_GR32_NOREX_NOSPRegClass,
  &X86::GR32_ABCDRegClass,
  NULL
};

static const TargetRegisterClass *const GR32_TCSuperclasses[] = {
  &X86::GR32RegClass,
  &X86::GR32_NOSPRegClass,
  &X86::GR32_NOREXRegClass,
  &X86::GR32_TC_64RegClass,
  &X86::GR32_NOREX_NOSPRegClass,
  &X86::GR32_NOREX_and_GR32_TC_64RegClass,
  &X86::GR32_ABCDRegClass,
  NULL
};

static const TargetRegisterClass *const GR32_ADSuperclasses[] = {
  &X86::GR32RegClass,
  &X86::GR32_NOSPRegClass,
  &X86::GR32_NOREXRegClass,
  &X86::GR32_TC_64RegClass,
  &X86::GR32_NOREX_NOSPRegClass,
  &X86::GR32_NOREX_and_GR32_TC_64RegClass,
  &X86::GR32_ABCDRegClass,
  &X86::GR32_TCRegClass,
  NULL
};

static const TargetRegisterClass *const GR32_NOAX_and_GR32_TCSuperclasses[] = {
  &X86::GR32RegClass,
  &X86::GR32_NOAXRegClass,
  &X86::GR32_NOSPRegClass,
  &X86::GR32_NOAX_and_GR32_NOSPRegClass,
  &X86::GR32_NOREXRegClass,
  &X86::GR32_TC_64RegClass,
  &X86::GR32_NOAX_and_GR32_NOREXRegClass,
  &X86::GR32_NOAX_and_GR32_TC_64RegClass,
  &X86::GR32_NOREX_NOSPRegClass,
  &X86::GR32_NOAX_and_GR32_NOREX_NOSPRegClass,
  &X86::GR32_NOREX_and_GR32_TC_64RegClass,
  &X86::GR32_ABCDRegClass,
  &X86::GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64RegClass,
  &X86::GR32_ABCD_and_GR32_NOAXRegClass,
  &X86::GR32_TCRegClass,
  NULL
};

static const TargetRegisterClass *const GR32_AD_and_GR32_NOAXSuperclasses[] = {
  &X86::GR32RegClass,
  &X86::GR32_NOAXRegClass,
  &X86::GR32_NOSPRegClass,
  &X86::GR32_NOAX_and_GR32_NOSPRegClass,
  &X86::GR32_NOREXRegClass,
  &X86::GR32_TC_64RegClass,
  &X86::GR32_NOAX_and_GR32_NOREXRegClass,
  &X86::GR32_NOAX_and_GR32_TC_64RegClass,
  &X86::GR32_NOREX_NOSPRegClass,
  &X86::GR32_NOAX_and_GR32_NOREX_NOSPRegClass,
  &X86::GR32_NOREX_and_GR32_TC_64RegClass,
  &X86::GR32_ABCDRegClass,
  &X86::GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64RegClass,
  &X86::GR32_ABCD_and_GR32_NOAXRegClass,
  &X86::GR32_TCRegClass,
  &X86::GR32_ADRegClass,
  &X86::GR32_NOAX_and_GR32_TCRegClass,
  NULL
};

static const TargetRegisterClass *const RFP64Superclasses[] = {
  &X86::RFP32RegClass,
  NULL
};

static const TargetRegisterClass *const FR64Superclasses[] = {
  &X86::FR32RegClass,
  NULL
};

static const TargetRegisterClass *const GR64_with_sub_8bitSuperclasses[] = {
  &X86::GR64RegClass,
  NULL
};

static const TargetRegisterClass *const GR64_NOSPSuperclasses[] = {
  &X86::GR64RegClass,
  &X86::GR64_with_sub_8bitRegClass,
  NULL
};

static const TargetRegisterClass *const GR64_with_sub_32bit_in_GR32_NOAXSuperclasses[] = {
  &X86::GR64RegClass,
  &X86::GR64_with_sub_8bitRegClass,
  NULL
};

static const TargetRegisterClass *const GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSPSuperclasses[] = {
  &X86::GR64RegClass,
  &X86::GR64_with_sub_8bitRegClass,
  &X86::GR64_NOSPRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAXRegClass,
  NULL
};

static const TargetRegisterClass *const GR64_NOREXSuperclasses[] = {
  &X86::GR64RegClass,
  NULL
};

static const TargetRegisterClass *const GR64_TCSuperclasses[] = {
  &X86::GR64RegClass,
  NULL
};

static const TargetRegisterClass *const GR64_with_sub_16bit_in_GR16_NOREXSuperclasses[] = {
  &X86::GR64RegClass,
  &X86::GR64_with_sub_8bitRegClass,
  &X86::GR64_NOREXRegClass,
  NULL
};

static const TargetRegisterClass *const GR64_with_sub_32bit_in_GR32_TC_64Superclasses[] = {
  &X86::GR64RegClass,
  &X86::GR64_with_sub_8bitRegClass,
  &X86::GR64_NOSPRegClass,
  &X86::GR64_TCRegClass,
  NULL
};

static const TargetRegisterClass *const GR64_NOREX_NOSPSuperclasses[] = {
  &X86::GR64RegClass,
  &X86::GR64_with_sub_8bitRegClass,
  &X86::GR64_NOSPRegClass,
  &X86::GR64_NOREXRegClass,
  &X86::GR64_with_sub_16bit_in_GR16_NOREXRegClass,
  NULL
};

static const TargetRegisterClass *const GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREXSuperclasses[] = {
  &X86::GR64RegClass,
  &X86::GR64_with_sub_8bitRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAXRegClass,
  &X86::GR64_NOREXRegClass,
  &X86::GR64_with_sub_16bit_in_GR16_NOREXRegClass,
  NULL
};

static const TargetRegisterClass *const GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64Superclasses[] = {
  &X86::GR64RegClass,
  &X86::GR64_with_sub_8bitRegClass,
  &X86::GR64_NOSPRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAXRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSPRegClass,
  &X86::GR64_TCRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_TC_64RegClass,
  NULL
};

static const TargetRegisterClass *const GR64_NOREX_and_GR64_TCSuperclasses[] = {
  &X86::GR64RegClass,
  &X86::GR64_NOREXRegClass,
  &X86::GR64_TCRegClass,
  NULL
};

static const TargetRegisterClass *const GR64_TCW64Superclasses[] = {
  &X86::GR64RegClass,
  &X86::GR64_with_sub_8bitRegClass,
  &X86::GR64_NOSPRegClass,
  &X86::GR64_TCRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_TC_64RegClass,
  NULL
};

static const TargetRegisterClass *const GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSPSuperclasses[] = {
  &X86::GR64RegClass,
  &X86::GR64_with_sub_8bitRegClass,
  &X86::GR64_NOSPRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAXRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSPRegClass,
  &X86::GR64_NOREXRegClass,
  &X86::GR64_with_sub_16bit_in_GR16_NOREXRegClass,
  &X86::GR64_NOREX_NOSPRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREXRegClass,
  NULL
};

static const TargetRegisterClass *const GR64_TCW64_and_GR64_with_sub_32bit_in_GR32_NOAXSuperclasses[] = {
  &X86::GR64RegClass,
  &X86::GR64_with_sub_8bitRegClass,
  &X86::GR64_NOSPRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAXRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSPRegClass,
  &X86::GR64_TCRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_TC_64RegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64RegClass,
  &X86::GR64_TCW64RegClass,
  NULL
};

static const TargetRegisterClass *const GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64Superclasses[] = {
  &X86::GR64RegClass,
  &X86::GR64_with_sub_8bitRegClass,
  &X86::GR64_NOSPRegClass,
  &X86::GR64_NOREXRegClass,
  &X86::GR64_TCRegClass,
  &X86::GR64_with_sub_16bit_in_GR16_NOREXRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_TC_64RegClass,
  &X86::GR64_NOREX_NOSPRegClass,
  &X86::GR64_NOREX_and_GR64_TCRegClass,
  NULL
};

static const TargetRegisterClass *const GR64_ABCDSuperclasses[] = {
  &X86::GR64RegClass,
  &X86::GR64_with_sub_8bitRegClass,
  &X86::GR64_NOSPRegClass,
  &X86::GR64_NOREXRegClass,
  &X86::GR64_with_sub_16bit_in_GR16_NOREXRegClass,
  &X86::GR64_NOREX_NOSPRegClass,
  NULL
};

static const TargetRegisterClass *const GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64Superclasses[] = {
  &X86::GR64RegClass,
  &X86::GR64_with_sub_8bitRegClass,
  &X86::GR64_NOSPRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAXRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSPRegClass,
  &X86::GR64_NOREXRegClass,
  &X86::GR64_TCRegClass,
  &X86::GR64_with_sub_16bit_in_GR16_NOREXRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_TC_64RegClass,
  &X86::GR64_NOREX_NOSPRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREXRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64RegClass,
  &X86::GR64_NOREX_and_GR64_TCRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSPRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64RegClass,
  NULL
};

static const TargetRegisterClass *const GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAXSuperclasses[] = {
  &X86::GR64RegClass,
  &X86::GR64_with_sub_8bitRegClass,
  &X86::GR64_NOSPRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAXRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSPRegClass,
  &X86::GR64_NOREXRegClass,
  &X86::GR64_with_sub_16bit_in_GR16_NOREXRegClass,
  &X86::GR64_NOREX_NOSPRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREXRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSPRegClass,
  &X86::GR64_ABCDRegClass,
  NULL
};

static const TargetRegisterClass *const GR64_with_sub_32bit_in_GR32_TCSuperclasses[] = {
  &X86::GR64RegClass,
  &X86::GR64_with_sub_8bitRegClass,
  &X86::GR64_NOSPRegClass,
  &X86::GR64_NOREXRegClass,
  &X86::GR64_TCRegClass,
  &X86::GR64_with_sub_16bit_in_GR16_NOREXRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_TC_64RegClass,
  &X86::GR64_NOREX_NOSPRegClass,
  &X86::GR64_NOREX_and_GR64_TCRegClass,
  &X86::GR64_TCW64RegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64RegClass,
  &X86::GR64_ABCDRegClass,
  NULL
};

static const TargetRegisterClass *const GR64_with_sub_32bit_in_GR32_ADSuperclasses[] = {
  &X86::GR64RegClass,
  &X86::GR64_with_sub_8bitRegClass,
  &X86::GR64_NOSPRegClass,
  &X86::GR64_NOREXRegClass,
  &X86::GR64_TCRegClass,
  &X86::GR64_with_sub_16bit_in_GR16_NOREXRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_TC_64RegClass,
  &X86::GR64_NOREX_NOSPRegClass,
  &X86::GR64_NOREX_and_GR64_TCRegClass,
  &X86::GR64_TCW64RegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64RegClass,
  &X86::GR64_ABCDRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_TCRegClass,
  NULL
};

static const TargetRegisterClass *const GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TCSuperclasses[] = {
  &X86::GR64RegClass,
  &X86::GR64_with_sub_8bitRegClass,
  &X86::GR64_NOSPRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAXRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSPRegClass,
  &X86::GR64_NOREXRegClass,
  &X86::GR64_TCRegClass,
  &X86::GR64_with_sub_16bit_in_GR16_NOREXRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_TC_64RegClass,
  &X86::GR64_NOREX_NOSPRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREXRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64RegClass,
  &X86::GR64_NOREX_and_GR64_TCRegClass,
  &X86::GR64_TCW64RegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSPRegClass,
  &X86::GR64_TCW64_and_GR64_with_sub_32bit_in_GR32_NOAXRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64RegClass,
  &X86::GR64_ABCDRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64RegClass,
  &X86::GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAXRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_TCRegClass,
  NULL
};

static const TargetRegisterClass *const GR64_with_sub_32bit_in_GR32_AD_and_GR32_NOAXSuperclasses[] = {
  &X86::GR64RegClass,
  &X86::GR64_with_sub_8bitRegClass,
  &X86::GR64_NOSPRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAXRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSPRegClass,
  &X86::GR64_NOREXRegClass,
  &X86::GR64_TCRegClass,
  &X86::GR64_with_sub_16bit_in_GR16_NOREXRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_TC_64RegClass,
  &X86::GR64_NOREX_NOSPRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREXRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64RegClass,
  &X86::GR64_NOREX_and_GR64_TCRegClass,
  &X86::GR64_TCW64RegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSPRegClass,
  &X86::GR64_TCW64_and_GR64_with_sub_32bit_in_GR32_NOAXRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64RegClass,
  &X86::GR64_ABCDRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64RegClass,
  &X86::GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAXRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_TCRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_ADRegClass,
  &X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TCRegClass,
  NULL
};

static const TargetRegisterClass *const RFP80Superclasses[] = {
  &X86::RFP32RegClass,
  &X86::RFP64RegClass,
  NULL
};

static const TargetRegisterClass *const VR128Superclasses[] = {
  &X86::FR32RegClass,
  &X86::FR64RegClass,
  NULL
};


static inline unsigned GR8AltOrderSelect(const MachineFunction &MF) {
    return MF.getTarget().getSubtarget<X86Subtarget>().is64Bit();
  }

static ArrayRef<MCPhysReg> GR8GetRawAllocationOrder(const MachineFunction &MF) {
  static const MCPhysReg AltOrder1[] = { X86::AL, X86::CL, X86::DL, X86::BL, X86::SIL, X86::DIL, X86::BPL, X86::SPL, X86::R8B, X86::R9B, X86::R10B, X86::R11B, X86::R14B, X86::R15B, X86::R12B, X86::R13B };
  const MCRegisterClass &MCR = X86MCRegisterClasses[X86::GR8RegClassID];
  const ArrayRef<MCPhysReg> Order[] = {
    makeArrayRef(MCR.begin(), MCR.getNumRegs()),
    makeArrayRef(AltOrder1)
  };
  const unsigned Select = GR8AltOrderSelect(MF);
  assert(Select < 2);
  return Order[Select];
}

static inline unsigned GR8_NOREXAltOrderSelect(const MachineFunction &MF) {
    return MF.getTarget().getSubtarget<X86Subtarget>().is64Bit();
  }

static ArrayRef<MCPhysReg> GR8_NOREXGetRawAllocationOrder(const MachineFunction &MF) {
  static const MCPhysReg AltOrder1[] = { X86::AL, X86::CL, X86::DL, X86::BL };
  const MCRegisterClass &MCR = X86MCRegisterClasses[X86::GR8_NOREXRegClassID];
  const ArrayRef<MCPhysReg> Order[] = {
    makeArrayRef(MCR.begin(), MCR.getNumRegs()),
    makeArrayRef(AltOrder1)
  };
  const unsigned Select = GR8_NOREXAltOrderSelect(MF);
  assert(Select < 2);
  return Order[Select];
}
namespace X86 {   // Register class instances
  extern const TargetRegisterClass GR8RegClass = {
    &X86MCRegisterClasses[GR8RegClassID],
    VTLists + 0,
    GR8SubClassMask,
    SuperRegIdxSeqs + 2,
    NullRegClasses,
    GR8GetRawAllocationOrder
  };

  extern const TargetRegisterClass GR8_NOREXRegClass = {
    &X86MCRegisterClasses[GR8_NOREXRegClassID],
    VTLists + 0,
    GR8_NOREXSubClassMask,
    SuperRegIdxSeqs + 2,
    GR8_NOREXSuperclasses,
    GR8_NOREXGetRawAllocationOrder
  };

  extern const TargetRegisterClass GR8_ABCD_HRegClass = {
    &X86MCRegisterClasses[GR8_ABCD_HRegClassID],
    VTLists + 0,
    GR8_ABCD_HSubClassMask,
    SuperRegIdxSeqs + 3,
    GR8_ABCD_HSuperclasses,
    0
  };

  extern const TargetRegisterClass GR8_ABCD_LRegClass = {
    &X86MCRegisterClasses[GR8_ABCD_LRegClassID],
    VTLists + 0,
    GR8_ABCD_LSubClassMask,
    SuperRegIdxSeqs + 0,
    GR8_ABCD_LSuperclasses,
    0
  };

  extern const TargetRegisterClass GR16RegClass = {
    &X86MCRegisterClasses[GR16RegClassID],
    VTLists + 2,
    GR16SubClassMask,
    SuperRegIdxSeqs + 5,
    NullRegClasses,
    0
  };

  extern const TargetRegisterClass GR16_NOREXRegClass = {
    &X86MCRegisterClasses[GR16_NOREXRegClassID],
    VTLists + 2,
    GR16_NOREXSubClassMask,
    SuperRegIdxSeqs + 5,
    GR16_NOREXSuperclasses,
    0
  };

  extern const TargetRegisterClass SEGMENT_REGRegClass = {
    &X86MCRegisterClasses[SEGMENT_REGRegClassID],
    VTLists + 2,
    SEGMENT_REGSubClassMask,
    SuperRegIdxSeqs + 1,
    NullRegClasses,
    0
  };

  extern const TargetRegisterClass GR16_ABCDRegClass = {
    &X86MCRegisterClasses[GR16_ABCDRegClassID],
    VTLists + 2,
    GR16_ABCDSubClassMask,
    SuperRegIdxSeqs + 5,
    GR16_ABCDSuperclasses,
    0
  };

  extern const TargetRegisterClass FPCCRRegClass = {
    &X86MCRegisterClasses[FPCCRRegClassID],
    VTLists + 2,
    FPCCRSubClassMask,
    SuperRegIdxSeqs + 1,
    NullRegClasses,
    0
  };

  extern const TargetRegisterClass FR32RegClass = {
    &X86MCRegisterClasses[FR32RegClassID],
    VTLists + 10,
    FR32SubClassMask,
    SuperRegIdxSeqs + 9,
    NullRegClasses,
    0
  };

  extern const TargetRegisterClass GR32RegClass = {
    &X86MCRegisterClasses[GR32RegClassID],
    VTLists + 4,
    GR32SubClassMask,
    SuperRegIdxSeqs + 7,
    NullRegClasses,
    0
  };

  extern const TargetRegisterClass GR32_NOAXRegClass = {
    &X86MCRegisterClasses[GR32_NOAXRegClassID],
    VTLists + 4,
    GR32_NOAXSubClassMask,
    SuperRegIdxSeqs + 7,
    GR32_NOAXSuperclasses,
    0
  };

  extern const TargetRegisterClass GR32_NOSPRegClass = {
    &X86MCRegisterClasses[GR32_NOSPRegClassID],
    VTLists + 4,
    GR32_NOSPSubClassMask,
    SuperRegIdxSeqs + 7,
    GR32_NOSPSuperclasses,
    0
  };

  extern const TargetRegisterClass GR32_NOAX_and_GR32_NOSPRegClass = {
    &X86MCRegisterClasses[GR32_NOAX_and_GR32_NOSPRegClassID],
    VTLists + 4,
    GR32_NOAX_and_GR32_NOSPSubClassMask,
    SuperRegIdxSeqs + 7,
    GR32_NOAX_and_GR32_NOSPSuperclasses,
    0
  };

  extern const TargetRegisterClass DEBUG_REGRegClass = {
    &X86MCRegisterClasses[DEBUG_REGRegClassID],
    VTLists + 4,
    DEBUG_REGSubClassMask,
    SuperRegIdxSeqs + 1,
    NullRegClasses,
    0
  };

  extern const TargetRegisterClass GR32_NOREXRegClass = {
    &X86MCRegisterClasses[GR32_NOREXRegClassID],
    VTLists + 4,
    GR32_NOREXSubClassMask,
    SuperRegIdxSeqs + 7,
    GR32_NOREXSuperclasses,
    0
  };

  extern const TargetRegisterClass GR32_TC_64RegClass = {
    &X86MCRegisterClasses[GR32_TC_64RegClassID],
    VTLists + 4,
    GR32_TC_64SubClassMask,
    SuperRegIdxSeqs + 7,
    GR32_TC_64Superclasses,
    0
  };

  extern const TargetRegisterClass GR32_NOAX_and_GR32_NOREXRegClass = {
    &X86MCRegisterClasses[GR32_NOAX_and_GR32_NOREXRegClassID],
    VTLists + 4,
    GR32_NOAX_and_GR32_NOREXSubClassMask,
    SuperRegIdxSeqs + 7,
    GR32_NOAX_and_GR32_NOREXSuperclasses,
    0
  };

  extern const TargetRegisterClass GR32_NOAX_and_GR32_TC_64RegClass = {
    &X86MCRegisterClasses[GR32_NOAX_and_GR32_TC_64RegClassID],
    VTLists + 4,
    GR32_NOAX_and_GR32_TC_64SubClassMask,
    SuperRegIdxSeqs + 7,
    GR32_NOAX_and_GR32_TC_64Superclasses,
    0
  };

  extern const TargetRegisterClass GR32_NOREX_NOSPRegClass = {
    &X86MCRegisterClasses[GR32_NOREX_NOSPRegClassID],
    VTLists + 4,
    GR32_NOREX_NOSPSubClassMask,
    SuperRegIdxSeqs + 7,
    GR32_NOREX_NOSPSuperclasses,
    0
  };

  extern const TargetRegisterClass RFP32RegClass = {
    &X86MCRegisterClasses[RFP32RegClassID],
    VTLists + 10,
    RFP32SubClassMask,
    SuperRegIdxSeqs + 1,
    NullRegClasses,
    0
  };

  extern const TargetRegisterClass GR32_NOAX_and_GR32_NOREX_NOSPRegClass = {
    &X86MCRegisterClasses[GR32_NOAX_and_GR32_NOREX_NOSPRegClassID],
    VTLists + 4,
    GR32_NOAX_and_GR32_NOREX_NOSPSubClassMask,
    SuperRegIdxSeqs + 7,
    GR32_NOAX_and_GR32_NOREX_NOSPSuperclasses,
    0
  };

  extern const TargetRegisterClass GR32_NOREX_and_GR32_TC_64RegClass = {
    &X86MCRegisterClasses[GR32_NOREX_and_GR32_TC_64RegClassID],
    VTLists + 4,
    GR32_NOREX_and_GR32_TC_64SubClassMask,
    SuperRegIdxSeqs + 7,
    GR32_NOREX_and_GR32_TC_64Superclasses,
    0
  };

  extern const TargetRegisterClass GR32_ABCDRegClass = {
    &X86MCRegisterClasses[GR32_ABCDRegClassID],
    VTLists + 4,
    GR32_ABCDSubClassMask,
    SuperRegIdxSeqs + 7,
    GR32_ABCDSuperclasses,
    0
  };

  extern const TargetRegisterClass GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64RegClass = {
    &X86MCRegisterClasses[GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64RegClassID],
    VTLists + 4,
    GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64SubClassMask,
    SuperRegIdxSeqs + 7,
    GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64Superclasses,
    0
  };

  extern const TargetRegisterClass GR32_ABCD_and_GR32_NOAXRegClass = {
    &X86MCRegisterClasses[GR32_ABCD_and_GR32_NOAXRegClassID],
    VTLists + 4,
    GR32_ABCD_and_GR32_NOAXSubClassMask,
    SuperRegIdxSeqs + 7,
    GR32_ABCD_and_GR32_NOAXSuperclasses,
    0
  };

  extern const TargetRegisterClass GR32_TCRegClass = {
    &X86MCRegisterClasses[GR32_TCRegClassID],
    VTLists + 4,
    GR32_TCSubClassMask,
    SuperRegIdxSeqs + 7,
    GR32_TCSuperclasses,
    0
  };

  extern const TargetRegisterClass GR32_ADRegClass = {
    &X86MCRegisterClasses[GR32_ADRegClassID],
    VTLists + 4,
    GR32_ADSubClassMask,
    SuperRegIdxSeqs + 7,
    GR32_ADSuperclasses,
    0
  };

  extern const TargetRegisterClass GR32_NOAX_and_GR32_TCRegClass = {
    &X86MCRegisterClasses[GR32_NOAX_and_GR32_TCRegClassID],
    VTLists + 4,
    GR32_NOAX_and_GR32_TCSubClassMask,
    SuperRegIdxSeqs + 7,
    GR32_NOAX_and_GR32_TCSuperclasses,
    0
  };

  extern const TargetRegisterClass CCRRegClass = {
    &X86MCRegisterClasses[CCRRegClassID],
    VTLists + 4,
    CCRSubClassMask,
    SuperRegIdxSeqs + 1,
    NullRegClasses,
    0
  };

  extern const TargetRegisterClass GR32_AD_and_GR32_NOAXRegClass = {
    &X86MCRegisterClasses[GR32_AD_and_GR32_NOAXRegClassID],
    VTLists + 4,
    GR32_AD_and_GR32_NOAXSubClassMask,
    SuperRegIdxSeqs + 7,
    GR32_AD_and_GR32_NOAXSuperclasses,
    0
  };

  extern const TargetRegisterClass RFP64RegClass = {
    &X86MCRegisterClasses[RFP64RegClassID],
    VTLists + 12,
    RFP64SubClassMask,
    SuperRegIdxSeqs + 1,
    RFP64Superclasses,
    0
  };

  extern const TargetRegisterClass GR64RegClass = {
    &X86MCRegisterClasses[GR64RegClassID],
    VTLists + 6,
    GR64SubClassMask,
    SuperRegIdxSeqs + 1,
    NullRegClasses,
    0
  };

  extern const TargetRegisterClass CONTROL_REGRegClass = {
    &X86MCRegisterClasses[CONTROL_REGRegClassID],
    VTLists + 6,
    CONTROL_REGSubClassMask,
    SuperRegIdxSeqs + 1,
    NullRegClasses,
    0
  };

  extern const TargetRegisterClass FR64RegClass = {
    &X86MCRegisterClasses[FR64RegClassID],
    VTLists + 12,
    FR64SubClassMask,
    SuperRegIdxSeqs + 9,
    FR64Superclasses,
    0
  };

  extern const TargetRegisterClass GR64_with_sub_8bitRegClass = {
    &X86MCRegisterClasses[GR64_with_sub_8bitRegClassID],
    VTLists + 6,
    GR64_with_sub_8bitSubClassMask,
    SuperRegIdxSeqs + 1,
    GR64_with_sub_8bitSuperclasses,
    0
  };

  extern const TargetRegisterClass GR64_NOSPRegClass = {
    &X86MCRegisterClasses[GR64_NOSPRegClassID],
    VTLists + 6,
    GR64_NOSPSubClassMask,
    SuperRegIdxSeqs + 1,
    GR64_NOSPSuperclasses,
    0
  };

  extern const TargetRegisterClass GR64_with_sub_32bit_in_GR32_NOAXRegClass = {
    &X86MCRegisterClasses[GR64_with_sub_32bit_in_GR32_NOAXRegClassID],
    VTLists + 6,
    GR64_with_sub_32bit_in_GR32_NOAXSubClassMask,
    SuperRegIdxSeqs + 1,
    GR64_with_sub_32bit_in_GR32_NOAXSuperclasses,
    0
  };

  extern const TargetRegisterClass GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSPRegClass = {
    &X86MCRegisterClasses[GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSPRegClassID],
    VTLists + 6,
    GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSPSubClassMask,
    SuperRegIdxSeqs + 1,
    GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSPSuperclasses,
    0
  };

  extern const TargetRegisterClass GR64_NOREXRegClass = {
    &X86MCRegisterClasses[GR64_NOREXRegClassID],
    VTLists + 6,
    GR64_NOREXSubClassMask,
    SuperRegIdxSeqs + 1,
    GR64_NOREXSuperclasses,
    0
  };

  extern const TargetRegisterClass GR64_TCRegClass = {
    &X86MCRegisterClasses[GR64_TCRegClassID],
    VTLists + 6,
    GR64_TCSubClassMask,
    SuperRegIdxSeqs + 1,
    GR64_TCSuperclasses,
    0
  };

  extern const TargetRegisterClass GR64_with_sub_16bit_in_GR16_NOREXRegClass = {
    &X86MCRegisterClasses[GR64_with_sub_16bit_in_GR16_NOREXRegClassID],
    VTLists + 6,
    GR64_with_sub_16bit_in_GR16_NOREXSubClassMask,
    SuperRegIdxSeqs + 1,
    GR64_with_sub_16bit_in_GR16_NOREXSuperclasses,
    0
  };

  extern const TargetRegisterClass GR64_with_sub_32bit_in_GR32_TC_64RegClass = {
    &X86MCRegisterClasses[GR64_with_sub_32bit_in_GR32_TC_64RegClassID],
    VTLists + 6,
    GR64_with_sub_32bit_in_GR32_TC_64SubClassMask,
    SuperRegIdxSeqs + 1,
    GR64_with_sub_32bit_in_GR32_TC_64Superclasses,
    0
  };

  extern const TargetRegisterClass VR64RegClass = {
    &X86MCRegisterClasses[VR64RegClassID],
    VTLists + 30,
    VR64SubClassMask,
    SuperRegIdxSeqs + 1,
    NullRegClasses,
    0
  };

  extern const TargetRegisterClass GR64_NOREX_NOSPRegClass = {
    &X86MCRegisterClasses[GR64_NOREX_NOSPRegClassID],
    VTLists + 6,
    GR64_NOREX_NOSPSubClassMask,
    SuperRegIdxSeqs + 1,
    GR64_NOREX_NOSPSuperclasses,
    0
  };

  extern const TargetRegisterClass GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREXRegClass = {
    &X86MCRegisterClasses[GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREXRegClassID],
    VTLists + 6,
    GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREXSubClassMask,
    SuperRegIdxSeqs + 1,
    GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREXSuperclasses,
    0
  };

  extern const TargetRegisterClass GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64RegClass = {
    &X86MCRegisterClasses[GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64RegClassID],
    VTLists + 6,
    GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64SubClassMask,
    SuperRegIdxSeqs + 1,
    GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64Superclasses,
    0
  };

  extern const TargetRegisterClass GR64_NOREX_and_GR64_TCRegClass = {
    &X86MCRegisterClasses[GR64_NOREX_and_GR64_TCRegClassID],
    VTLists + 6,
    GR64_NOREX_and_GR64_TCSubClassMask,
    SuperRegIdxSeqs + 1,
    GR64_NOREX_and_GR64_TCSuperclasses,
    0
  };

  extern const TargetRegisterClass GR64_TCW64RegClass = {
    &X86MCRegisterClasses[GR64_TCW64RegClassID],
    VTLists + 6,
    GR64_TCW64SubClassMask,
    SuperRegIdxSeqs + 1,
    GR64_TCW64Superclasses,
    0
  };

  extern const TargetRegisterClass GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSPRegClass = {
    &X86MCRegisterClasses[GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSPRegClassID],
    VTLists + 6,
    GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSPSubClassMask,
    SuperRegIdxSeqs + 1,
    GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSPSuperclasses,
    0
  };

  extern const TargetRegisterClass GR64_TCW64_and_GR64_with_sub_32bit_in_GR32_NOAXRegClass = {
    &X86MCRegisterClasses[GR64_TCW64_and_GR64_with_sub_32bit_in_GR32_NOAXRegClassID],
    VTLists + 6,
    GR64_TCW64_and_GR64_with_sub_32bit_in_GR32_NOAXSubClassMask,
    SuperRegIdxSeqs + 1,
    GR64_TCW64_and_GR64_with_sub_32bit_in_GR32_NOAXSuperclasses,
    0
  };

  extern const TargetRegisterClass GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64RegClass = {
    &X86MCRegisterClasses[GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64RegClassID],
    VTLists + 6,
    GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64SubClassMask,
    SuperRegIdxSeqs + 1,
    GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64Superclasses,
    0
  };

  extern const TargetRegisterClass GR64_ABCDRegClass = {
    &X86MCRegisterClasses[GR64_ABCDRegClassID],
    VTLists + 6,
    GR64_ABCDSubClassMask,
    SuperRegIdxSeqs + 1,
    GR64_ABCDSuperclasses,
    0
  };

  extern const TargetRegisterClass GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64RegClass = {
    &X86MCRegisterClasses[GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64RegClassID],
    VTLists + 6,
    GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64SubClassMask,
    SuperRegIdxSeqs + 1,
    GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64Superclasses,
    0
  };

  extern const TargetRegisterClass GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAXRegClass = {
    &X86MCRegisterClasses[GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAXRegClassID],
    VTLists + 6,
    GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAXSubClassMask,
    SuperRegIdxSeqs + 1,
    GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAXSuperclasses,
    0
  };

  extern const TargetRegisterClass GR64_with_sub_32bit_in_GR32_TCRegClass = {
    &X86MCRegisterClasses[GR64_with_sub_32bit_in_GR32_TCRegClassID],
    VTLists + 6,
    GR64_with_sub_32bit_in_GR32_TCSubClassMask,
    SuperRegIdxSeqs + 1,
    GR64_with_sub_32bit_in_GR32_TCSuperclasses,
    0
  };

  extern const TargetRegisterClass GR64_with_sub_32bit_in_GR32_ADRegClass = {
    &X86MCRegisterClasses[GR64_with_sub_32bit_in_GR32_ADRegClassID],
    VTLists + 6,
    GR64_with_sub_32bit_in_GR32_ADSubClassMask,
    SuperRegIdxSeqs + 1,
    GR64_with_sub_32bit_in_GR32_ADSuperclasses,
    0
  };

  extern const TargetRegisterClass GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TCRegClass = {
    &X86MCRegisterClasses[GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TCRegClassID],
    VTLists + 6,
    GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TCSubClassMask,
    SuperRegIdxSeqs + 1,
    GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TCSuperclasses,
    0
  };

  extern const TargetRegisterClass GR64_with_sub_32bit_in_GR32_AD_and_GR32_NOAXRegClass = {
    &X86MCRegisterClasses[GR64_with_sub_32bit_in_GR32_AD_and_GR32_NOAXRegClassID],
    VTLists + 6,
    GR64_with_sub_32bit_in_GR32_AD_and_GR32_NOAXSubClassMask,
    SuperRegIdxSeqs + 1,
    GR64_with_sub_32bit_in_GR32_AD_and_GR32_NOAXSuperclasses,
    0
  };

  extern const TargetRegisterClass RSTRegClass = {
    &X86MCRegisterClasses[RSTRegClassID],
    VTLists + 8,
    RSTSubClassMask,
    SuperRegIdxSeqs + 1,
    NullRegClasses,
    0
  };

  extern const TargetRegisterClass RFP80RegClass = {
    &X86MCRegisterClasses[RFP80RegClassID],
    VTLists + 14,
    RFP80SubClassMask,
    SuperRegIdxSeqs + 1,
    RFP80Superclasses,
    0
  };

  extern const TargetRegisterClass VR128RegClass = {
    &X86MCRegisterClasses[VR128RegClassID],
    VTLists + 16,
    VR128SubClassMask,
    SuperRegIdxSeqs + 9,
    VR128Superclasses,
    0
  };

  extern const TargetRegisterClass VR256RegClass = {
    &X86MCRegisterClasses[VR256RegClassID],
    VTLists + 23,
    VR256SubClassMask,
    SuperRegIdxSeqs + 1,
    NullRegClasses,
    0
  };

}

namespace {
  const TargetRegisterClass* const RegisterClasses[] = {
    &X86::GR8RegClass,
    &X86::GR8_NOREXRegClass,
    &X86::GR8_ABCD_HRegClass,
    &X86::GR8_ABCD_LRegClass,
    &X86::GR16RegClass,
    &X86::GR16_NOREXRegClass,
    &X86::SEGMENT_REGRegClass,
    &X86::GR16_ABCDRegClass,
    &X86::FPCCRRegClass,
    &X86::FR32RegClass,
    &X86::GR32RegClass,
    &X86::GR32_NOAXRegClass,
    &X86::GR32_NOSPRegClass,
    &X86::GR32_NOAX_and_GR32_NOSPRegClass,
    &X86::DEBUG_REGRegClass,
    &X86::GR32_NOREXRegClass,
    &X86::GR32_TC_64RegClass,
    &X86::GR32_NOAX_and_GR32_NOREXRegClass,
    &X86::GR32_NOAX_and_GR32_TC_64RegClass,
    &X86::GR32_NOREX_NOSPRegClass,
    &X86::RFP32RegClass,
    &X86::GR32_NOAX_and_GR32_NOREX_NOSPRegClass,
    &X86::GR32_NOREX_and_GR32_TC_64RegClass,
    &X86::GR32_ABCDRegClass,
    &X86::GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64RegClass,
    &X86::GR32_ABCD_and_GR32_NOAXRegClass,
    &X86::GR32_TCRegClass,
    &X86::GR32_ADRegClass,
    &X86::GR32_NOAX_and_GR32_TCRegClass,
    &X86::CCRRegClass,
    &X86::GR32_AD_and_GR32_NOAXRegClass,
    &X86::RFP64RegClass,
    &X86::GR64RegClass,
    &X86::CONTROL_REGRegClass,
    &X86::FR64RegClass,
    &X86::GR64_with_sub_8bitRegClass,
    &X86::GR64_NOSPRegClass,
    &X86::GR64_with_sub_32bit_in_GR32_NOAXRegClass,
    &X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSPRegClass,
    &X86::GR64_NOREXRegClass,
    &X86::GR64_TCRegClass,
    &X86::GR64_with_sub_16bit_in_GR16_NOREXRegClass,
    &X86::GR64_with_sub_32bit_in_GR32_TC_64RegClass,
    &X86::VR64RegClass,
    &X86::GR64_NOREX_NOSPRegClass,
    &X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREXRegClass,
    &X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64RegClass,
    &X86::GR64_NOREX_and_GR64_TCRegClass,
    &X86::GR64_TCW64RegClass,
    &X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSPRegClass,
    &X86::GR64_TCW64_and_GR64_with_sub_32bit_in_GR32_NOAXRegClass,
    &X86::GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64RegClass,
    &X86::GR64_ABCDRegClass,
    &X86::GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64RegClass,
    &X86::GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAXRegClass,
    &X86::GR64_with_sub_32bit_in_GR32_TCRegClass,
    &X86::GR64_with_sub_32bit_in_GR32_ADRegClass,
    &X86::GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TCRegClass,
    &X86::GR64_with_sub_32bit_in_GR32_AD_and_GR32_NOAXRegClass,
    &X86::RSTRegClass,
    &X86::RFP80RegClass,
    &X86::VR128RegClass,
    &X86::VR256RegClass,
  };
}

static const TargetRegisterInfoDesc X86RegInfoDesc[] = { // Extra Descriptors
  { 0, 0 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 1, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 1, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 0 },
  { 0, 1 },
  { 0, 1 },
  { 0, 0 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 0 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 1, 1 },
  { 0, 0 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 1, 1 },
  { 0, 1 },
  { 1, 1 },
  { 0, 1 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 1, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
};
unsigned X86GenRegisterInfo::composeSubRegIndicesImpl(unsigned IdxA, unsigned IdxB) const {
  static const uint8_t Rows[1][5] = {
    { 1, 2, 3, 0, 0, },
  };

  --IdxA; assert(IdxA < 5);
  --IdxB; assert(IdxB < 5);
  return Rows[0][IdxB];
}

const TargetRegisterClass *X86GenRegisterInfo::getSubClassWithSubReg(const TargetRegisterClass *RC, unsigned Idx) const {
  static const uint8_t Table[63][5] = {
    {	// GR8
      0,	// sub_8bit
      0,	// sub_8bit_hi
      0,	// sub_16bit
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// GR8_NOREX
      0,	// sub_8bit
      0,	// sub_8bit_hi
      0,	// sub_16bit
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// GR8_ABCD_H
      0,	// sub_8bit
      0,	// sub_8bit_hi
      0,	// sub_16bit
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// GR8_ABCD_L
      0,	// sub_8bit
      0,	// sub_8bit_hi
      0,	// sub_16bit
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// GR16
      5,	// sub_8bit -> GR16
      8,	// sub_8bit_hi -> GR16_ABCD
      0,	// sub_16bit
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// GR16_NOREX
      6,	// sub_8bit -> GR16_NOREX
      8,	// sub_8bit_hi -> GR16_ABCD
      0,	// sub_16bit
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// SEGMENT_REG
      0,	// sub_8bit
      0,	// sub_8bit_hi
      0,	// sub_16bit
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// GR16_ABCD
      8,	// sub_8bit -> GR16_ABCD
      8,	// sub_8bit_hi -> GR16_ABCD
      0,	// sub_16bit
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// FPCCR
      0,	// sub_8bit
      0,	// sub_8bit_hi
      0,	// sub_16bit
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// FR32
      0,	// sub_8bit
      0,	// sub_8bit_hi
      0,	// sub_16bit
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// GR32
      11,	// sub_8bit -> GR32
      24,	// sub_8bit_hi -> GR32_ABCD
      11,	// sub_16bit -> GR32
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// GR32_NOAX
      12,	// sub_8bit -> GR32_NOAX
      26,	// sub_8bit_hi -> GR32_ABCD_and_GR32_NOAX
      12,	// sub_16bit -> GR32_NOAX
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// GR32_NOSP
      13,	// sub_8bit -> GR32_NOSP
      24,	// sub_8bit_hi -> GR32_ABCD
      13,	// sub_16bit -> GR32_NOSP
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// GR32_NOAX_and_GR32_NOSP
      14,	// sub_8bit -> GR32_NOAX_and_GR32_NOSP
      26,	// sub_8bit_hi -> GR32_ABCD_and_GR32_NOAX
      14,	// sub_16bit -> GR32_NOAX_and_GR32_NOSP
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// DEBUG_REG
      0,	// sub_8bit
      0,	// sub_8bit_hi
      0,	// sub_16bit
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// GR32_NOREX
      16,	// sub_8bit -> GR32_NOREX
      24,	// sub_8bit_hi -> GR32_ABCD
      16,	// sub_16bit -> GR32_NOREX
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// GR32_TC_64
      17,	// sub_8bit -> GR32_TC_64
      27,	// sub_8bit_hi -> GR32_TC
      17,	// sub_16bit -> GR32_TC_64
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// GR32_NOAX_and_GR32_NOREX
      18,	// sub_8bit -> GR32_NOAX_and_GR32_NOREX
      26,	// sub_8bit_hi -> GR32_ABCD_and_GR32_NOAX
      18,	// sub_16bit -> GR32_NOAX_and_GR32_NOREX
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// GR32_NOAX_and_GR32_TC_64
      19,	// sub_8bit -> GR32_NOAX_and_GR32_TC_64
      29,	// sub_8bit_hi -> GR32_NOAX_and_GR32_TC
      19,	// sub_16bit -> GR32_NOAX_and_GR32_TC_64
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// GR32_NOREX_NOSP
      20,	// sub_8bit -> GR32_NOREX_NOSP
      24,	// sub_8bit_hi -> GR32_ABCD
      20,	// sub_16bit -> GR32_NOREX_NOSP
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// RFP32
      0,	// sub_8bit
      0,	// sub_8bit_hi
      0,	// sub_16bit
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// GR32_NOAX_and_GR32_NOREX_NOSP
      22,	// sub_8bit -> GR32_NOAX_and_GR32_NOREX_NOSP
      26,	// sub_8bit_hi -> GR32_ABCD_and_GR32_NOAX
      22,	// sub_16bit -> GR32_NOAX_and_GR32_NOREX_NOSP
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// GR32_NOREX_and_GR32_TC_64
      23,	// sub_8bit -> GR32_NOREX_and_GR32_TC_64
      27,	// sub_8bit_hi -> GR32_TC
      23,	// sub_16bit -> GR32_NOREX_and_GR32_TC_64
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// GR32_ABCD
      24,	// sub_8bit -> GR32_ABCD
      24,	// sub_8bit_hi -> GR32_ABCD
      24,	// sub_16bit -> GR32_ABCD
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64
      25,	// sub_8bit -> GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64
      29,	// sub_8bit_hi -> GR32_NOAX_and_GR32_TC
      25,	// sub_16bit -> GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// GR32_ABCD_and_GR32_NOAX
      26,	// sub_8bit -> GR32_ABCD_and_GR32_NOAX
      26,	// sub_8bit_hi -> GR32_ABCD_and_GR32_NOAX
      26,	// sub_16bit -> GR32_ABCD_and_GR32_NOAX
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// GR32_TC
      27,	// sub_8bit -> GR32_TC
      27,	// sub_8bit_hi -> GR32_TC
      27,	// sub_16bit -> GR32_TC
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// GR32_AD
      28,	// sub_8bit -> GR32_AD
      28,	// sub_8bit_hi -> GR32_AD
      28,	// sub_16bit -> GR32_AD
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// GR32_NOAX_and_GR32_TC
      29,	// sub_8bit -> GR32_NOAX_and_GR32_TC
      29,	// sub_8bit_hi -> GR32_NOAX_and_GR32_TC
      29,	// sub_16bit -> GR32_NOAX_and_GR32_TC
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// CCR
      0,	// sub_8bit
      0,	// sub_8bit_hi
      0,	// sub_16bit
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// GR32_AD_and_GR32_NOAX
      31,	// sub_8bit -> GR32_AD_and_GR32_NOAX
      31,	// sub_8bit_hi -> GR32_AD_and_GR32_NOAX
      31,	// sub_16bit -> GR32_AD_and_GR32_NOAX
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// RFP64
      0,	// sub_8bit
      0,	// sub_8bit_hi
      0,	// sub_16bit
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// GR64
      36,	// sub_8bit -> GR64_with_sub_8bit
      53,	// sub_8bit_hi -> GR64_ABCD
      33,	// sub_16bit -> GR64
      33,	// sub_32bit -> GR64
      0,	// sub_xmm
    },
    {	// CONTROL_REG
      0,	// sub_8bit
      0,	// sub_8bit_hi
      0,	// sub_16bit
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// FR64
      0,	// sub_8bit
      0,	// sub_8bit_hi
      0,	// sub_16bit
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// GR64_with_sub_8bit
      36,	// sub_8bit -> GR64_with_sub_8bit
      53,	// sub_8bit_hi -> GR64_ABCD
      36,	// sub_16bit -> GR64_with_sub_8bit
      36,	// sub_32bit -> GR64_with_sub_8bit
      0,	// sub_xmm
    },
    {	// GR64_NOSP
      37,	// sub_8bit -> GR64_NOSP
      53,	// sub_8bit_hi -> GR64_ABCD
      37,	// sub_16bit -> GR64_NOSP
      37,	// sub_32bit -> GR64_NOSP
      0,	// sub_xmm
    },
    {	// GR64_with_sub_32bit_in_GR32_NOAX
      38,	// sub_8bit -> GR64_with_sub_32bit_in_GR32_NOAX
      55,	// sub_8bit_hi -> GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAX
      38,	// sub_16bit -> GR64_with_sub_32bit_in_GR32_NOAX
      38,	// sub_32bit -> GR64_with_sub_32bit_in_GR32_NOAX
      0,	// sub_xmm
    },
    {	// GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSP
      39,	// sub_8bit -> GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSP
      55,	// sub_8bit_hi -> GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAX
      39,	// sub_16bit -> GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSP
      39,	// sub_32bit -> GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSP
      0,	// sub_xmm
    },
    {	// GR64_NOREX
      42,	// sub_8bit -> GR64_with_sub_16bit_in_GR16_NOREX
      53,	// sub_8bit_hi -> GR64_ABCD
      40,	// sub_16bit -> GR64_NOREX
      40,	// sub_32bit -> GR64_NOREX
      0,	// sub_xmm
    },
    {	// GR64_TC
      43,	// sub_8bit -> GR64_with_sub_32bit_in_GR32_TC_64
      56,	// sub_8bit_hi -> GR64_with_sub_32bit_in_GR32_TC
      41,	// sub_16bit -> GR64_TC
      41,	// sub_32bit -> GR64_TC
      0,	// sub_xmm
    },
    {	// GR64_with_sub_16bit_in_GR16_NOREX
      42,	// sub_8bit -> GR64_with_sub_16bit_in_GR16_NOREX
      53,	// sub_8bit_hi -> GR64_ABCD
      42,	// sub_16bit -> GR64_with_sub_16bit_in_GR16_NOREX
      42,	// sub_32bit -> GR64_with_sub_16bit_in_GR16_NOREX
      0,	// sub_xmm
    },
    {	// GR64_with_sub_32bit_in_GR32_TC_64
      43,	// sub_8bit -> GR64_with_sub_32bit_in_GR32_TC_64
      56,	// sub_8bit_hi -> GR64_with_sub_32bit_in_GR32_TC
      43,	// sub_16bit -> GR64_with_sub_32bit_in_GR32_TC_64
      43,	// sub_32bit -> GR64_with_sub_32bit_in_GR32_TC_64
      0,	// sub_xmm
    },
    {	// VR64
      0,	// sub_8bit
      0,	// sub_8bit_hi
      0,	// sub_16bit
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// GR64_NOREX_NOSP
      45,	// sub_8bit -> GR64_NOREX_NOSP
      53,	// sub_8bit_hi -> GR64_ABCD
      45,	// sub_16bit -> GR64_NOREX_NOSP
      45,	// sub_32bit -> GR64_NOREX_NOSP
      0,	// sub_xmm
    },
    {	// GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX
      46,	// sub_8bit -> GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX
      55,	// sub_8bit_hi -> GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAX
      46,	// sub_16bit -> GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX
      46,	// sub_32bit -> GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX
      0,	// sub_xmm
    },
    {	// GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64
      47,	// sub_8bit -> GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64
      58,	// sub_8bit_hi -> GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC
      47,	// sub_16bit -> GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64
      47,	// sub_32bit -> GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64
      0,	// sub_xmm
    },
    {	// GR64_NOREX_and_GR64_TC
      52,	// sub_8bit -> GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64
      56,	// sub_8bit_hi -> GR64_with_sub_32bit_in_GR32_TC
      48,	// sub_16bit -> GR64_NOREX_and_GR64_TC
      48,	// sub_32bit -> GR64_NOREX_and_GR64_TC
      0,	// sub_xmm
    },
    {	// GR64_TCW64
      49,	// sub_8bit -> GR64_TCW64
      56,	// sub_8bit_hi -> GR64_with_sub_32bit_in_GR32_TC
      49,	// sub_16bit -> GR64_TCW64
      49,	// sub_32bit -> GR64_TCW64
      0,	// sub_xmm
    },
    {	// GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSP
      50,	// sub_8bit -> GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSP
      55,	// sub_8bit_hi -> GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAX
      50,	// sub_16bit -> GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSP
      50,	// sub_32bit -> GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSP
      0,	// sub_xmm
    },
    {	// GR64_TCW64_and_GR64_with_sub_32bit_in_GR32_NOAX
      51,	// sub_8bit -> GR64_TCW64_and_GR64_with_sub_32bit_in_GR32_NOAX
      58,	// sub_8bit_hi -> GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC
      51,	// sub_16bit -> GR64_TCW64_and_GR64_with_sub_32bit_in_GR32_NOAX
      51,	// sub_32bit -> GR64_TCW64_and_GR64_with_sub_32bit_in_GR32_NOAX
      0,	// sub_xmm
    },
    {	// GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64
      52,	// sub_8bit -> GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64
      56,	// sub_8bit_hi -> GR64_with_sub_32bit_in_GR32_TC
      52,	// sub_16bit -> GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64
      52,	// sub_32bit -> GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64
      0,	// sub_xmm
    },
    {	// GR64_ABCD
      53,	// sub_8bit -> GR64_ABCD
      53,	// sub_8bit_hi -> GR64_ABCD
      53,	// sub_16bit -> GR64_ABCD
      53,	// sub_32bit -> GR64_ABCD
      0,	// sub_xmm
    },
    {	// GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64
      54,	// sub_8bit -> GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64
      58,	// sub_8bit_hi -> GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC
      54,	// sub_16bit -> GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64
      54,	// sub_32bit -> GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64
      0,	// sub_xmm
    },
    {	// GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAX
      55,	// sub_8bit -> GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAX
      55,	// sub_8bit_hi -> GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAX
      55,	// sub_16bit -> GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAX
      55,	// sub_32bit -> GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAX
      0,	// sub_xmm
    },
    {	// GR64_with_sub_32bit_in_GR32_TC
      56,	// sub_8bit -> GR64_with_sub_32bit_in_GR32_TC
      56,	// sub_8bit_hi -> GR64_with_sub_32bit_in_GR32_TC
      56,	// sub_16bit -> GR64_with_sub_32bit_in_GR32_TC
      56,	// sub_32bit -> GR64_with_sub_32bit_in_GR32_TC
      0,	// sub_xmm
    },
    {	// GR64_with_sub_32bit_in_GR32_AD
      57,	// sub_8bit -> GR64_with_sub_32bit_in_GR32_AD
      57,	// sub_8bit_hi -> GR64_with_sub_32bit_in_GR32_AD
      57,	// sub_16bit -> GR64_with_sub_32bit_in_GR32_AD
      57,	// sub_32bit -> GR64_with_sub_32bit_in_GR32_AD
      0,	// sub_xmm
    },
    {	// GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC
      58,	// sub_8bit -> GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC
      58,	// sub_8bit_hi -> GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC
      58,	// sub_16bit -> GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC
      58,	// sub_32bit -> GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC
      0,	// sub_xmm
    },
    {	// GR64_with_sub_32bit_in_GR32_AD_and_GR32_NOAX
      59,	// sub_8bit -> GR64_with_sub_32bit_in_GR32_AD_and_GR32_NOAX
      59,	// sub_8bit_hi -> GR64_with_sub_32bit_in_GR32_AD_and_GR32_NOAX
      59,	// sub_16bit -> GR64_with_sub_32bit_in_GR32_AD_and_GR32_NOAX
      59,	// sub_32bit -> GR64_with_sub_32bit_in_GR32_AD_and_GR32_NOAX
      0,	// sub_xmm
    },
    {	// RST
      0,	// sub_8bit
      0,	// sub_8bit_hi
      0,	// sub_16bit
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// RFP80
      0,	// sub_8bit
      0,	// sub_8bit_hi
      0,	// sub_16bit
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// VR128
      0,	// sub_8bit
      0,	// sub_8bit_hi
      0,	// sub_16bit
      0,	// sub_32bit
      0,	// sub_xmm
    },
    {	// VR256
      0,	// sub_8bit
      0,	// sub_8bit_hi
      0,	// sub_16bit
      0,	// sub_32bit
      63,	// sub_xmm -> VR256
    },
  };
  assert(RC && "Missing regclass");
  if (!Idx) return RC;
  --Idx;
  assert(Idx < 5 && "Bad subreg");
  unsigned TV = Table[RC->getID()][Idx];
  return TV ? getRegClass(TV - 1) : 0;
}

/// Get the weight in units of pressure for this register class.
const RegClassWeight &X86GenRegisterInfo::
getRegClassWeight(const TargetRegisterClass *RC) const {
  static const RegClassWeight RCWeightTable[] = {
    {1, 20},  	// GR8
    {1, 8},  	// GR8_NOREX
    {1, 4},  	// GR8_ABCD_H
    {1, 4},  	// GR8_ABCD_L
    {2, 32},  	// GR16
    {2, 16},  	// GR16_NOREX
    {1, 6},  	// SEGMENT_REG
    {2, 8},  	// GR16_ABCD
    {0, 0},  	// FPCCR
    {1, 16},  	// FR32
    {2, 32},  	// GR32
    {2, 30},  	// GR32_NOAX
    {2, 30},  	// GR32_NOSP
    {2, 28},  	// GR32_NOAX_and_GR32_NOSP
    {1, 8},  	// DEBUG_REG
    {2, 16},  	// GR32_NOREX
    {2, 16},  	// GR32_TC_64
    {2, 14},  	// GR32_NOAX_and_GR32_NOREX
    {2, 14},  	// GR32_NOAX_and_GR32_TC_64
    {2, 14},  	// GR32_NOREX_NOSP
    {1, 7},  	// RFP32
    {2, 12},  	// GR32_NOAX_and_GR32_NOREX_NOSP
    {2, 10},  	// GR32_NOREX_and_GR32_TC_64
    {2, 8},  	// GR32_ABCD
    {2, 8},  	// GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64
    {2, 6},  	// GR32_ABCD_and_GR32_NOAX
    {2, 6},  	// GR32_TC
    {2, 4},  	// GR32_AD
    {2, 4},  	// GR32_NOAX_and_GR32_TC
    {0, 0},  	// CCR
    {2, 2},  	// GR32_AD_and_GR32_NOAX
    {1, 7},  	// RFP64
    {2, 34},  	// GR64
    {1, 16},  	// CONTROL_REG
    {1, 16},  	// FR64
    {2, 32},  	// GR64_with_sub_8bit
    {2, 30},  	// GR64_NOSP
    {2, 30},  	// GR64_with_sub_32bit_in_GR32_NOAX
    {2, 28},  	// GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSP
    {2, 18},  	// GR64_NOREX
    {2, 18},  	// GR64_TC
    {2, 16},  	// GR64_with_sub_16bit_in_GR16_NOREX
    {2, 16},  	// GR64_with_sub_32bit_in_GR32_TC_64
    {1, 8},  	// VR64
    {2, 14},  	// GR64_NOREX_NOSP
    {2, 14},  	// GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX
    {2, 14},  	// GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64
    {2, 12},  	// GR64_NOREX_and_GR64_TC
    {2, 12},  	// GR64_TCW64
    {2, 12},  	// GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSP
    {2, 10},  	// GR64_TCW64_and_GR64_with_sub_32bit_in_GR32_NOAX
    {2, 10},  	// GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64
    {2, 8},  	// GR64_ABCD
    {2, 8},  	// GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64
    {2, 6},  	// GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAX
    {2, 6},  	// GR64_with_sub_32bit_in_GR32_TC
    {2, 4},  	// GR64_with_sub_32bit_in_GR32_AD
    {2, 4},  	// GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC
    {2, 2},  	// GR64_with_sub_32bit_in_GR32_AD_and_GR32_NOAX
    {0, 7},  	// RST
    {1, 7},  	// RFP80
    {1, 16},  	// VR128
    {1, 16},  	// VR256
    {0, 0} };
  return RCWeightTable[RC->getID()];
}

/// Get the weight in units of pressure for this register unit.
unsigned X86GenRegisterInfo::
getRegUnitWeight(unsigned RegUnit) const {
  assert(RegUnit < 88 && "invalid register unit");
  // All register units have unit weight.
  return 1;
}


// Get the number of dimensions of register pressure.
unsigned X86GenRegisterInfo::getNumRegPressureSets() const {
  return 19;
}

// Get the name of this register unit pressure set.
const char *X86GenRegisterInfo::
getRegPressureSetName(unsigned Idx) const {
  static const char *PressureNameTable[] = {
    "GR8",
    "GR8_NOREX",
    "GR8_ABCD_H",
    "GR8_ABCD_L",
    "SEGMENT_REG",
    "FR32",
    "DEBUG_REG",
    "RFP32",
    "GR64",
    "CONTROL_REG",
    "GR64_NOREX",
    "VR64",
    "GR8+GR64_NOREX",
    "GR8+GR64_TC",
    "GR8+GR64_TCW64",
    "GR8_NOREX+GR64_TC",
    "GR8_NOREX+GR64_NOREX_and_GR64_TC",
    "GR8_NOREX+GR64_TCW64",
    "GR64_NOREX+GR64_TC",
    0 };
  return PressureNameTable[Idx];
}

// Get the register unit pressure limit for this dimension.
// This limit must be adjusted dynamically for reserved registers.
unsigned X86GenRegisterInfo::
getRegPressureSetLimit(unsigned Idx) const {
  static const unsigned PressureLimitTable[] = {
    20,  	// 0: GR8
    8,  	// 1: GR8_NOREX
    4,  	// 2: GR8_ABCD_H
    4,  	// 3: GR8_ABCD_L
    6,  	// 4: SEGMENT_REG
    16,  	// 5: FR32
    8,  	// 6: DEBUG_REG
    7,  	// 7: RFP32
    34,  	// 8: GR64
    16,  	// 9: CONTROL_REG
    18,  	// 10: GR64_NOREX
    8,  	// 11: VR64
    26,  	// 12: GR8+GR64_NOREX
    27,  	// 13: GR8+GR64_TC
    23,  	// 14: GR8+GR64_TCW64
    20,  	// 15: GR8_NOREX+GR64_TC
    14,  	// 16: GR8_NOREX+GR64_NOREX_and_GR64_TC
    14,  	// 17: GR8_NOREX+GR64_TCW64
    24,  	// 18: GR64_NOREX+GR64_TC
    0 };
  return PressureLimitTable[Idx];
}

/// Table of pressure sets per register class or unit.
static const int RCSetsTable[] = {
    0,  8,  12,  13,  14,  -1,  	// #0 GR8
    0,  1,  8,  10,  12,  13,  14,  15,  16,  17,  18,  -1,  	// #6 GR8_NOREX
    0,  1,  2,  8,  10,  12,  13,  14,  15,  16,  17,  18,  -1,  	// #18 GR8_ABCD_H
    0,  1,  3,  8,  10,  12,  13,  14,  15,  16,  17,  18,  -1,  	// #31 GR8_ABCD_L
    8,  -1,  	// #44 GR16
    8,  10,  12,  18,  -1,  	// #46 GR16_NOREX
    4,  -1,  	// #51 SEGMENT_REG
    0,  1,  8,  10,  12,  13,  14,  15,  16,  17,  18,  -1,  	// #53 GR16_ABCD
    -1,  	// #65 FPCCR
    5,  -1,  	// #66 FR32
    8,  -1,  	// #68 GR32
    8,  -1,  	// #70 GR32_NOAX
    8,  -1,  	// #72 GR32_NOSP
    8,  -1,  	// #74 GR32_NOAX_and_GR32_NOSP
    6,  -1,  	// #76 DEBUG_REG
    8,  10,  12,  18,  -1,  	// #78 GR32_NOREX
    8,  13,  15,  18,  -1,  	// #83 GR32_TC_64
    8,  10,  12,  18,  -1,  	// #88 GR32_NOAX_and_GR32_NOREX
    8,  13,  15,  18,  -1,  	// #93 GR32_NOAX_and_GR32_TC_64
    8,  10,  12,  18,  -1,  	// #98 GR32_NOREX_NOSP
    7,  -1,  	// #103 RFP32
    8,  10,  12,  18,  -1,  	// #105 GR32_NOAX_and_GR32_NOREX_NOSP
    8,  10,  12,  13,  15,  16,  18,  -1,  	// #110 GR32_NOREX_and_GR32_TC_64
    0,  1,  8,  10,  12,  13,  14,  15,  16,  17,  18,  -1,  	// #118 GR32_ABCD
    8,  10,  12,  13,  15,  16,  18,  -1,  	// #130 GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64
    0,  1,  8,  10,  12,  13,  14,  15,  16,  17,  18,  -1,  	// #138 GR32_ABCD_and_GR32_NOAX
    0,  1,  8,  10,  12,  13,  14,  15,  16,  17,  18,  -1,  	// #150 GR32_TC
    0,  1,  8,  10,  12,  13,  14,  15,  16,  17,  18,  -1,  	// #162 GR32_AD
    0,  1,  8,  10,  12,  13,  14,  15,  16,  17,  18,  -1,  	// #174 GR32_NOAX_and_GR32_TC
    -1,  	// #186 CCR
    0,  1,  8,  10,  12,  13,  14,  15,  16,  17,  18,  -1,  	// #187 GR32_AD_and_GR32_NOAX
    7,  -1,  	// #199 RFP64
    8,  -1,  	// #201 GR64
    9,  -1,  	// #203 CONTROL_REG
    5,  -1,  	// #205 FR64
    8,  -1,  	// #207 GR64_with_sub_8bit
    8,  -1,  	// #209 GR64_NOSP
    8,  -1,  	// #211 GR64_with_sub_32bit_in_GR32_NOAX
    8,  -1,  	// #213 GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOSP
    8,  10,  12,  18,  -1,  	// #215 GR64_NOREX
    8,  13,  15,  18,  -1,  	// #220 GR64_TC
    8,  10,  12,  18,  -1,  	// #225 GR64_with_sub_16bit_in_GR16_NOREX
    8,  13,  15,  18,  -1,  	// #230 GR64_with_sub_32bit_in_GR32_TC_64
    11,  -1,  	// #235 VR64
    8,  10,  12,  18,  -1,  	// #237 GR64_NOREX_NOSP
    8,  10,  12,  18,  -1,  	// #242 GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX
    8,  13,  15,  18,  -1,  	// #247 GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC_64
    8,  10,  12,  13,  15,  16,  18,  -1,  	// #252 GR64_NOREX_and_GR64_TC
    8,  13,  14,  15,  17,  18,  -1,  	// #260 GR64_TCW64
    8,  10,  12,  18,  -1,  	// #267 GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_NOREX_NOSP
    8,  13,  14,  15,  17,  18,  -1,  	// #272 GR64_TCW64_and_GR64_with_sub_32bit_in_GR32_NOAX
    8,  10,  12,  13,  15,  16,  18,  -1,  	// #279 GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_TC_64
    0,  1,  8,  10,  12,  13,  14,  15,  16,  17,  18,  -1,  	// #287 GR64_ABCD
    8,  10,  12,  13,  15,  16,  18,  -1,  	// #299 GR64_with_sub_32bit_in_GR32_NOREX_and_GR32_NOAX_and_GR32_TC_64
    0,  1,  8,  10,  12,  13,  14,  15,  16,  17,  18,  -1,  	// #307 GR64_with_sub_32bit_in_GR32_ABCD_and_GR32_NOAX
    0,  1,  8,  10,  12,  13,  14,  15,  16,  17,  18,  -1,  	// #319 GR64_with_sub_32bit_in_GR32_TC
    0,  1,  8,  10,  12,  13,  14,  15,  16,  17,  18,  -1,  	// #331 GR64_with_sub_32bit_in_GR32_AD
    0,  1,  8,  10,  12,  13,  14,  15,  16,  17,  18,  -1,  	// #343 GR64_with_sub_32bit_in_GR32_NOAX_and_GR32_TC
    0,  1,  8,  10,  12,  13,  14,  15,  16,  17,  18,  -1,  	// #355 GR64_with_sub_32bit_in_GR32_AD_and_GR32_NOAX
    -1,  	// #367 RST
    7,  -1,  	// #368 RFP80
    5,  -1,  	// #370 VR128
    5,  -1,  	// #372 VR256
    0,  8,  10,  12,  13,  14,  18,  -1,  	// #374 inferred~GR8~GR64~GR64_NOREX~GR8+GR64_NOREX~GR8+GR64_TC~GR8+GR64_TCW64~GR64_NOREX+GR64_TC
    0,  8,  10,  12,  13,  14,  15,  16,  18,  -1,  	// #382 inferred~GR8~GR64~GR64_NOREX~GR8+GR64_NOREX~GR8+GR64_TC~GR8+GR64_TCW64~GR8_NOREX+GR64_TC~GR8_NOREX+GR64_NOREX_and_GR64_TC~GR64_NOREX+GR64_TC
    0,  8,  12,  13,  14,  15,  17,  18,  -1,  	// #392 inferred~GR8~GR64~GR8+GR64_NOREX~GR8+GR64_TC~GR8+GR64_TCW64~GR8_NOREX+GR64_TC~GR8_NOREX+GR64_TCW64~GR64_NOREX+GR64_TC
    -1 };

/// Get the dimensions of register pressure impacted by this register class.
/// Returns a -1 terminated array of pressure set IDs
const int* X86GenRegisterInfo::
getRegClassPressureSets(const TargetRegisterClass *RC) const {
  static const unsigned RCSetStartTable[] = {
    0,6,18,31,44,46,51,53,65,66,68,70,72,74,76,78,83,88,93,98,103,105,110,118,130,138,150,162,174,186,187,199,201,203,205,207,209,211,213,215,220,225,230,235,237,242,247,252,260,267,272,279,287,299,307,319,331,343,355,367,368,370,372,0 };
  unsigned SetListStart = RCSetStartTable[RC->getID()];
  return &RCSetsTable[SetListStart];
}

/// Get the dimensions of register pressure impacted by this register unit.
/// Returns a -1 terminated array of pressure set IDs
const int* X86GenRegisterInfo::
getRegUnitPressureSets(unsigned RegUnit) const {
  assert(RegUnit < 88 && "invalid register unit");
  static const unsigned RUSetStartTable[] = {
    18,31,18,31,374,18,31,203,203,203,203,203,203,203,203,203,203,203,203,203,203,203,203,51,18,382,31,76,76,76,76,76,76,76,76,51,65,110,65,51,382,374,103,103,103,103,103,103,103,65,51,51,235,235,235,235,235,235,235,235,65,392,392,0,392,0,0,0,0,65,51,65,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,0 };
  unsigned SetListStart = RUSetStartTable[RegUnit];
  return &RCSetsTable[SetListStart];
}

extern const MCRegisterDesc X86RegDesc[];
extern const MCPhysReg X86RegDiffLists[];
extern const char X86RegStrings[];
extern const uint16_t X86RegUnitRoots[][2];
extern const uint16_t X86SubRegIdxLists[];
extern const uint16_t X86RegEncodingTable[];
// X86 Dwarf<->LLVM register mappings.
extern const MCRegisterInfo::DwarfLLVMRegPair X86DwarfFlavour0Dwarf2L[];
extern const unsigned X86DwarfFlavour0Dwarf2LSize;

extern const MCRegisterInfo::DwarfLLVMRegPair X86DwarfFlavour1Dwarf2L[];
extern const unsigned X86DwarfFlavour1Dwarf2LSize;

extern const MCRegisterInfo::DwarfLLVMRegPair X86DwarfFlavour2Dwarf2L[];
extern const unsigned X86DwarfFlavour2Dwarf2LSize;

extern const MCRegisterInfo::DwarfLLVMRegPair X86EHFlavour0Dwarf2L[];
extern const unsigned X86EHFlavour0Dwarf2LSize;

extern const MCRegisterInfo::DwarfLLVMRegPair X86EHFlavour1Dwarf2L[];
extern const unsigned X86EHFlavour1Dwarf2LSize;

extern const MCRegisterInfo::DwarfLLVMRegPair X86EHFlavour2Dwarf2L[];
extern const unsigned X86EHFlavour2Dwarf2LSize;

extern const MCRegisterInfo::DwarfLLVMRegPair X86DwarfFlavour0L2Dwarf[];
extern const unsigned X86DwarfFlavour0L2DwarfSize;

extern const MCRegisterInfo::DwarfLLVMRegPair X86DwarfFlavour1L2Dwarf[];
extern const unsigned X86DwarfFlavour1L2DwarfSize;

extern const MCRegisterInfo::DwarfLLVMRegPair X86DwarfFlavour2L2Dwarf[];
extern const unsigned X86DwarfFlavour2L2DwarfSize;

extern const MCRegisterInfo::DwarfLLVMRegPair X86EHFlavour0L2Dwarf[];
extern const unsigned X86EHFlavour0L2DwarfSize;

extern const MCRegisterInfo::DwarfLLVMRegPair X86EHFlavour1L2Dwarf[];
extern const unsigned X86EHFlavour1L2DwarfSize;

extern const MCRegisterInfo::DwarfLLVMRegPair X86EHFlavour2L2Dwarf[];
extern const unsigned X86EHFlavour2L2DwarfSize;

X86GenRegisterInfo::
X86GenRegisterInfo(unsigned RA, unsigned DwarfFlavour, unsigned EHFlavour, unsigned PC)
  : TargetRegisterInfo(X86RegInfoDesc, RegisterClasses, RegisterClasses+63,
             SubRegIndexNameTable, SubRegIndexLaneMaskTable) {
  InitMCRegisterInfo(X86RegDesc, 162, RA, PC,
                     X86MCRegisterClasses, 63,
                     X86RegUnitRoots,
                     88,
                     X86RegDiffLists,
                     X86RegStrings,
                     X86SubRegIdxLists,
                     6,
                     X86RegEncodingTable);

  switch (DwarfFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    mapDwarfRegsToLLVMRegs(X86DwarfFlavour0Dwarf2L, X86DwarfFlavour0Dwarf2LSize, false);
    break;
  case 1:
    mapDwarfRegsToLLVMRegs(X86DwarfFlavour1Dwarf2L, X86DwarfFlavour1Dwarf2LSize, false);
    break;
  case 2:
    mapDwarfRegsToLLVMRegs(X86DwarfFlavour2Dwarf2L, X86DwarfFlavour2Dwarf2LSize, false);
    break;
  }
  switch (EHFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    mapDwarfRegsToLLVMRegs(X86EHFlavour0Dwarf2L, X86EHFlavour0Dwarf2LSize, true);
    break;
  case 1:
    mapDwarfRegsToLLVMRegs(X86EHFlavour1Dwarf2L, X86EHFlavour1Dwarf2LSize, true);
    break;
  case 2:
    mapDwarfRegsToLLVMRegs(X86EHFlavour2Dwarf2L, X86EHFlavour2Dwarf2LSize, true);
    break;
  }
  switch (DwarfFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    mapLLVMRegsToDwarfRegs(X86DwarfFlavour0L2Dwarf, X86DwarfFlavour0L2DwarfSize, false);
    break;
  case 1:
    mapLLVMRegsToDwarfRegs(X86DwarfFlavour1L2Dwarf, X86DwarfFlavour1L2DwarfSize, false);
    break;
  case 2:
    mapLLVMRegsToDwarfRegs(X86DwarfFlavour2L2Dwarf, X86DwarfFlavour2L2DwarfSize, false);
    break;
  }
  switch (EHFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    mapLLVMRegsToDwarfRegs(X86EHFlavour0L2Dwarf, X86EHFlavour0L2DwarfSize, true);
    break;
  case 1:
    mapLLVMRegsToDwarfRegs(X86EHFlavour1L2Dwarf, X86EHFlavour1L2DwarfSize, true);
    break;
  case 2:
    mapLLVMRegsToDwarfRegs(X86EHFlavour2L2Dwarf, X86EHFlavour2L2DwarfSize, true);
    break;
  }
}

static const MCPhysReg CSR_32_SaveList[] = { X86::ESI, X86::EDI, X86::EBX, X86::EBP, 0 };
static const uint32_t CSR_32_RegMask[] = { 0xc00001f0, 0x0020b000, 0x00000000, 0x00600000, 0x00000000, 0x00000000, };
static const MCPhysReg CSR_32EHRet_SaveList[] = { X86::EAX, X86::EDX, X86::ESI, X86::EDI, X86::EBX, X86::EBP, 0 };
static const uint32_t CSR_32EHRet_RegMask[] = { 0xe00001fe, 0x0021bc01, 0x00000000, 0x00600000, 0x00000000, 0x00000000, };
static const MCPhysReg CSR_64_SaveList[] = { X86::RBX, X86::R12, X86::R13, X86::R14, X86::R15, X86::RBP, 0 };
static const uint32_t CSR_64_RegMask[] = { 0x000001f0, 0x00003000, 0xf8000000, 0x000037ff, 0x00000000, 0x00000000, };
static const MCPhysReg CSR_64EHRet_SaveList[] = { X86::RAX, X86::RDX, X86::RBX, X86::R12, X86::R13, X86::R14, X86::R15, X86::RBP, 0 };
static const uint32_t CSR_64EHRet_RegMask[] = { 0x200001fe, 0x00013c01, 0xf8000000, 0x00013fff, 0x00000000, 0x00000000, };
static const MCPhysReg CSR_64_Intel_OCL_BI_SaveList[] = { X86::RBX, X86::R12, X86::R13, X86::R14, X86::R15, X86::RBP, X86::XMM8, X86::XMM9, X86::XMM10, X86::XMM11, X86::XMM12, X86::XMM13, X86::XMM14, X86::XMM15, 0 };
static const uint32_t CSR_64_Intel_OCL_BI_RegMask[] = { 0x000001f0, 0x00003000, 0xf8000000, 0x000037ff, 0x0003fc00, 0x00000000, };
static const MCPhysReg CSR_64_Intel_OCL_BI_AVX_SaveList[] = { X86::RBX, X86::R12, X86::R13, X86::R14, X86::R15, X86::RBP, X86::YMM8, X86::YMM9, X86::YMM10, X86::YMM11, X86::YMM12, X86::YMM13, X86::YMM14, X86::YMM15, 0 };
static const uint32_t CSR_64_Intel_OCL_BI_AVX_RegMask[] = { 0x000001f0, 0x00003000, 0xf8000000, 0x000037ff, 0xfc03fc00, 0x00000003, };
static const MCPhysReg CSR_MostRegs_64_SaveList[] = { X86::RBX, X86::RCX, X86::RDX, X86::RSI, X86::RDI, X86::R8, X86::R9, X86::R10, X86::R11, X86::R12, X86::R13, X86::R14, X86::R15, X86::RBP, X86::XMM0, X86::XMM1, X86::XMM2, X86::XMM3, X86::XMM4, X86::XMM5, X86::XMM6, X86::XMM7, X86::XMM8, X86::XMM9, X86::XMM10, X86::XMM11, X86::XMM12, X86::XMM13, X86::XMM14, X86::XMM15, 0 };
static const uint32_t CSR_MostRegs_64_RegMask[] = { 0xf00007f0, 0x0021f401, 0xfffff800, 0x0069f7ff, 0x0003fffc, 0x00000000, };
static const MCPhysReg CSR_NaCl64_SaveList[] = { X86::RBX, X86::R12, X86::R13, X86::R14, X86::RBP, 0 };
static const uint32_t CSR_NaCl64_RegMask[] = { 0x000001f0, 0x00003000, 0xf8000000, 0x0000307f, 0x00000000, 0x00000000, };
static const MCPhysReg CSR_NaCl64EHRet_SaveList[] = { X86::RAX, X86::RDX, X86::RBX, X86::R12, X86::R13, X86::R14, X86::RBP, 0 };
static const uint32_t CSR_NaCl64EHRet_RegMask[] = { 0x200001fe, 0x00013c01, 0xf8000000, 0x0001387f, 0x00000000, 0x00000000, };
static const MCPhysReg CSR_NoRegs_SaveList[] = { 0 };
static const uint32_t CSR_NoRegs_RegMask[] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, };
static const MCPhysReg CSR_Win64_SaveList[] = { X86::RBX, X86::RBP, X86::RDI, X86::RSI, X86::R12, X86::R13, X86::R14, X86::R15, X86::XMM6, X86::XMM7, X86::XMM8, X86::XMM9, X86::XMM10, X86::XMM11, X86::XMM12, X86::XMM13, X86::XMM14, X86::XMM15, 0 };
static const uint32_t CSR_Win64_RegMask[] = { 0xc00001f0, 0x0020b000, 0xf8000000, 0x0068b7ff, 0x0003ff00, 0x00000000, };
static const MCPhysReg CSR_Win64_Intel_OCL_BI_AVX_SaveList[] = { X86::RBX, X86::RBP, X86::RDI, X86::RSI, X86::R12, X86::R13, X86::R14, X86::R15, X86::YMM6, X86::YMM7, X86::YMM8, X86::YMM9, X86::YMM10, X86::YMM11, X86::YMM12, X86::YMM13, X86::YMM14, X86::YMM15, 0 };
static const uint32_t CSR_Win64_Intel_OCL_BI_AVX_RegMask[] = { 0xc00001f0, 0x0020b000, 0xf8000000, 0x0068b7ff, 0xff03ff00, 0x00000003, };


} // End llvm namespace 
#endif // GET_REGINFO_TARGET_DESC

