//===- NaClBitCodes.h - Enum values for the bitcode format ------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This header Bitcode enum values.
//
// The enum values defined in this file should be considered permanent.  If
// new features are added, they should have values added at the end of the
// respective lists.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_BITCODE_NACL_NACLBITCODES_H
#define LLVM_BITCODE_NACL_NACLBITCODES_H

#include "llvm/ADT/SmallVector.h"
#include "llvm/Support/DataTypes.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/MathExtras.h"
#include <cassert>

namespace llvm {
namespace naclbitc {
  enum StandardWidths {
    BlockIDWidth   = 8,  // We use VBR-8 for block IDs.
    CodeLenWidth   = 4,  // Codelen are VBR-4.
    BlockSizeWidth = 32  // BlockSize up to 2^32 32-bit words = 16GB per block.
  };

  // The standard abbrev namespace always has a way to exit a block, enter a
  // nested block, define abbrevs, and define an unabbreviated record.
  enum FixedAbbrevIDs {
    END_BLOCK = 0,  // Must be zero to guarantee termination for broken bitcode.
    ENTER_SUBBLOCK = 1,

    /// DEFINE_ABBREV - Defines an abbrev for the current block.  It consists
    /// of a vbr5 for # operand infos.  Each operand info is emitted with a
    /// single bit to indicate if it is a literal encoding.  If so, the value is
    /// emitted with a vbr8.  If not, the encoding is emitted as 3 bits followed
    /// by the info value as a vbr5 if needed.
    DEFINE_ABBREV = 2,

    // UNABBREV_RECORDs are emitted with a vbr6 for the record code, followed by
    // a vbr6 for the # operands, followed by vbr6's for each operand.
    UNABBREV_RECORD = 3,

    // This is not a code, this is a marker for the first abbrev assignment.
    // In addition, we assume up to two additional enumerated constants are
    // added for each extension. These constants are:
    //
    //   PREFIX_MAX_FIXED_ABBREV
    //   PREFIX_MAX_ABBREV
    //
    // PREFIX_MAX_ABBREV defines the maximal enumeration value used for
    // the code selector of a block. If Both PREFIX_MAX_FIXED_ABBREV
    // and PREFIX_MAX_ABBREV is defined, then PREFIX_MAX_FIXED_ABBREV
    // defines the last code selector of the block that must be read using
    // a single read (i.e. a FIXED read, or the first chunk of a VBR read.
    FIRST_APPLICATION_ABBREV = 4,
    // Defines default values for code length, if no additional selectors
    // are added.
    DEFAULT_MAX_ABBREV = FIRST_APPLICATION_ABBREV-1
  };

  /// StandardBlockIDs - All bitcode files can optionally include a BLOCKINFO
  /// block, which contains metadata about other blocks in the file.
  enum StandardBlockIDs {
    /// BLOCKINFO_BLOCK is used to define metadata about blocks, for example,
    /// standard abbrevs that should be available to all blocks of a specified
    /// ID.
    BLOCKINFO_BLOCK_ID = 0,

    // Block IDs 1-7 are reserved for future expansion.
    FIRST_APPLICATION_BLOCKID = 8
  };

  /// BlockInfoCodes - The blockinfo block contains metadata about user-defined
  /// blocks.
  enum BlockInfoCodes {
    // DEFINE_ABBREV has magic semantics here, applying to the current SETBID'd
    // block, instead of the BlockInfo block.

    BLOCKINFO_CODE_SETBID        = 1, // SETBID: [blockid#]
    BLOCKINFO_CODE_BLOCKNAME     = 2, // BLOCKNAME: [name]
    BLOCKINFO_CODE_SETRECORDNAME = 3  // BLOCKINFO_CODE_SETRECORDNAME:
                                      //                             [id, name]
  };

} // End naclbitc namespace

/// NaClBitCodeAbbrevOp - This describes one or more operands in an abbreviation.
/// This is actually a union of two different things:
///   1. It could be a literal integer value ("the operand is always 17").
///   2. It could be an encoding specification ("this operand encoded like so").
///
class NaClBitCodeAbbrevOp {
  uint64_t Val;           // A literal value or data for an encoding.
  bool IsLiteral : 1;     // Indicate whether this is a literal value or not.
  unsigned Enc   : 3;     // The encoding to use.
public:
  enum Encoding {
    Fixed = 1,  // A fixed width field, Val specifies number of bits.
    VBR   = 2,  // A VBR field where Val specifies the width of each chunk.
    Array = 3,  // A sequence of fields, next field species elt encoding.
    Char6 = 4,  // A 6-bit fixed field which maps to [a-zA-Z0-9._].
    Blob  = 5   // 32-bit aligned array of 8-bit characters.
  };

  explicit NaClBitCodeAbbrevOp(uint64_t V) :  Val(V), IsLiteral(true) {}
  explicit NaClBitCodeAbbrevOp(Encoding E, uint64_t Data = 0)
    : Val(Data), IsLiteral(false), Enc(E) {}

  bool isLiteral() const  { return IsLiteral; }
  bool isEncoding() const { return !IsLiteral; }

  // Accessors for literals.
  uint64_t getLiteralValue() const { assert(isLiteral()); return Val; }

  // Accessors for encoding info.
  Encoding getEncoding() const { assert(isEncoding()); return (Encoding)Enc; }
  uint64_t getEncodingData() const {
    assert(isEncoding() && hasEncodingData());
    return Val;
  }

  bool hasEncodingData() const { return hasEncodingData(getEncoding()); }
  static bool hasEncodingData(Encoding E) {
    switch (E) {
    case Fixed:
    case VBR:
      return true;
    case Array:
    case Char6:
    case Blob:
      return false;
    }
    llvm_unreachable("Invalid encoding");
  }

  /// isChar6 - Return true if this character is legal in the Char6 encoding.
  static bool isChar6(char C) {
    if (C >= 'a' && C <= 'z') return true;
    if (C >= 'A' && C <= 'Z') return true;
    if (C >= '0' && C <= '9') return true;
    if (C == '.' || C == '_') return true;
    return false;
  }
  static unsigned EncodeChar6(char C) {
    if (C >= 'a' && C <= 'z') return C-'a';
    if (C >= 'A' && C <= 'Z') return C-'A'+26;
    if (C >= '0' && C <= '9') return C-'0'+26+26;
    if (C == '.')             return 62;
    if (C == '_')             return 63;
    llvm_unreachable("Not a value Char6 character!");
  }

  static char DecodeChar6(unsigned V) {
    assert((V & ~63) == 0 && "Not a Char6 encoded character!");
    if (V < 26)       return V+'a';
    if (V < 26+26)    return V-26+'A';
    if (V < 26+26+10) return V-26-26+'0';
    if (V == 62)      return '.';
    if (V == 63)      return '_';
    llvm_unreachable("Not a value Char6 character!");
  }

  /// \brief Compares this to Op. Returns <0 if this is less than Op,
  /// Returns 0 if they are equal, and >0 if this is greater than Op.
  int Compare(const NaClBitCodeAbbrevOp &Op) const {
    // Assume literals are smallest in comparisons.
    if (IsLiteral) {
      if (!Op.IsLiteral)
        return -1;
      return ValCompare(Op);
    } else if (Op.IsLiteral)
      return 1;

    // Neither is a literal, so now order on encoding.
    int EncodingDiff = static_cast<int>(Enc) - static_cast<int>(Op.Enc);
    if (EncodingDiff != 0) return EncodingDiff;

    // Encodings don't differ, so now base on data associated with the
    // encoding.
    return ValCompare(Op);
  }

private:
  int ValCompare(const NaClBitCodeAbbrevOp &Op) const {
    if (Val < Op.Val)
      return -1;
    else if (Val > Op.Val)
      return 1;
    else
      return 0;
  }
};

template <> struct isPodLike<NaClBitCodeAbbrevOp> {
  static const bool value=true;
};

static inline bool operator<(const NaClBitCodeAbbrevOp &Op1,
                             const NaClBitCodeAbbrevOp &Op2) {
  return Op1.Compare(Op2) < 0;
}

static inline bool operator<=(const NaClBitCodeAbbrevOp &Op1,
                              const NaClBitCodeAbbrevOp &Op2) {
  return Op1.Compare(Op2) <= 0;
}

static inline bool operator==(const NaClBitCodeAbbrevOp &Op1,
                              const NaClBitCodeAbbrevOp &Op2) {
  return Op1.Compare(Op2) == 0;
}

static inline bool operator!=(const NaClBitCodeAbbrevOp &Op1,
                              const NaClBitCodeAbbrevOp &Op2) {
  return Op1.Compare(Op2) != 0;
}

static inline bool operator>=(const NaClBitCodeAbbrevOp &Op1,
                              const NaClBitCodeAbbrevOp &Op2) {
  return Op1.Compare(Op2) >= 0;
}

static inline bool operator>(const NaClBitCodeAbbrevOp &Op1,
                             const NaClBitCodeAbbrevOp &Op2) {
  return Op1.Compare(Op2) > 0;
}

/// NaClBitCodeAbbrev - This class represents an abbreviation record.  An
/// abbreviation allows a complex record that has redundancy to be stored in a
/// specialized format instead of the fully-general, fully-vbr, format.
class NaClBitCodeAbbrev {
  SmallVector<NaClBitCodeAbbrevOp, 32> OperandList;
  unsigned char RefCount; // Number of things using this.
  ~NaClBitCodeAbbrev() {}
public:
  NaClBitCodeAbbrev() : RefCount(1) {}

  void addRef() { ++RefCount; }
  void dropRef() { if (--RefCount == 0) delete this; }

  unsigned getNumOperandInfos() const {
    return static_cast<unsigned>(OperandList.size());
  }
  const NaClBitCodeAbbrevOp &getOperandInfo(unsigned N) const {
    return OperandList[N];
  }

  void Add(const NaClBitCodeAbbrevOp &OpInfo) {
    OperandList.push_back(OpInfo);
  }

  int Compare(const NaClBitCodeAbbrev &Abbrev) const {
    // First order based on number of operands.
    size_t OperandListSize = OperandList.size();
    size_t AbbrevOperandListSize = Abbrev.OperandList.size();
    if (OperandListSize < AbbrevOperandListSize)
      return -1;
    else if (OperandListSize > AbbrevOperandListSize)
      return 1;
    else
      return 0;

    // Same number of operands, so compare element by element.
    for (size_t I = 0; I < OperandListSize; ++I) {
      if (int Diff = OperandList[I].Compare(Abbrev.OperandList[I]))
        return Diff;
    }
    return 0;
  }
};

static inline bool operator<(const NaClBitCodeAbbrev &A1,
                             const NaClBitCodeAbbrev &A2) {
  return A1.Compare(A2) < 0;
}

static inline bool operator<=(const NaClBitCodeAbbrev &A1,
                              const NaClBitCodeAbbrev &A2) {
  return A1.Compare(A2) <= 0;
}
static inline bool operator==(const NaClBitCodeAbbrev &A1,
                              const NaClBitCodeAbbrev &A2) {
  return A1.Compare(A2) == 0;
}

static inline bool operator!=(const NaClBitCodeAbbrev &A1,
                              const NaClBitCodeAbbrev &A2) {
  return A1.Compare(A2) != 0;
}
static inline bool operator>=(const NaClBitCodeAbbrev &A1,
                              const NaClBitCodeAbbrev &A2) {
  return A1.Compare(A2) >= 0;
}

static inline bool operator>(const NaClBitCodeAbbrev &A1,
                             const NaClBitCodeAbbrev &A2) {
  return A1.Compare(A2) > 0;
}

/// \brief Returns number of bits needed to encode
/// value for dense FIXED encoding.
inline unsigned NaClBitsNeededForValue(unsigned Value) {
  // Note: Need to handle case where Value=0xFFFFFFFF as special case,
  // since we can't add 1 to it.
  if (Value >= 0x80000000) return 32;
  return Log2_32_Ceil(Value+1);
}

/// \brief Encode a signed value by moving the sign to the LSB for dense
/// VBR encoding.
inline uint64_t NaClEncodeSignRotatedValue(int64_t V) {
  return (V >= 0) ? (V << 1) : ((-V << 1) | 1);
}

/// \brief Decode a signed value stored with the sign bit in
/// the LSB for dense VBR encoding.
inline uint64_t NaClDecodeSignRotatedValue(uint64_t V) {
  if ((V & 1) == 0)
    return V >> 1;
  if (V != 1)
    return -(V >> 1);
  // There is no such thing as -0 with integers.  "-0" really means MININT.
  return 1ULL << 63;
}

/// \brief This class determines whether a FIXED or VBR
/// abbreviation should be used for the selector, and the number of bits
/// needed to capture such selectors.
class NaClBitcodeSelectorAbbrev {

public:
  // If true, use a FIXED abbreviation. Otherwise, use a VBR abbreviation.
  bool IsFixed;
  // Number of bits needed for selector.
  unsigned NumBits;

  // Creates a selector range for the given values.
  NaClBitcodeSelectorAbbrev(bool IF, unsigned NB)
      : IsFixed(IF), NumBits(NB) {}

  // Creates a selector range when no abbreviations are defined.
  NaClBitcodeSelectorAbbrev()
      : IsFixed(true),
        NumBits(NaClBitsNeededForValue(naclbitc::DEFAULT_MAX_ABBREV)) {}

  // Creates a selector range to handle fixed abbrevations up to
  // the specified value.
  explicit NaClBitcodeSelectorAbbrev(unsigned MaxAbbrev)
      : IsFixed(true),
        NumBits(NaClBitsNeededForValue(MaxAbbrev)) {}
};
} // End llvm namespace

#endif
