//==- RISCVMachineFuctionInfo.h - RISCV machine function info -*- C++ -*-=//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef RISCVMACHINEFUNCTIONINFO_H
#define RISCVMACHINEFUNCTIONINFO_H

#include "llvm/CodeGen/MachineFunction.h"

namespace llvm {

class RISCVMachineFunctionInfo : public MachineFunctionInfo {
  unsigned SavedGPRFrameSize;
  unsigned LowSavedGPR;
  unsigned HighSavedGPR;
  unsigned VarArgsFirstGPR;
  unsigned VarArgsFirstFPR;
  unsigned VarArgsFrameIndex;
  unsigned RegSaveFrameIndex;
  bool ManipulatesSP;

public:
  explicit RISCVMachineFunctionInfo(MachineFunction &MF)
    : SavedGPRFrameSize(0), LowSavedGPR(0), HighSavedGPR(0), VarArgsFirstGPR(0),
      VarArgsFirstFPR(0), VarArgsFrameIndex(0), RegSaveFrameIndex(0),
      ManipulatesSP(false) {}

  // Get and set the number of bytes allocated by generic code to store
  // call-saved GPRs.
  unsigned getSavedGPRFrameSize() const { return SavedGPRFrameSize; }
  void setSavedGPRFrameSize(unsigned bytes) { SavedGPRFrameSize = bytes; }

  // Get and set the first call-saved GPR that should be saved and restored
  // by this function.  This is 0 if no GPRs need to be saved or restored.
  unsigned getLowSavedGPR() const { return LowSavedGPR; }
  void setLowSavedGPR(unsigned Reg) { LowSavedGPR = Reg; }

  // Get and set the last call-saved GPR that should be saved and restored
  // by this function.
  unsigned getHighSavedGPR() const { return HighSavedGPR; }
  void setHighSavedGPR(unsigned Reg) { HighSavedGPR = Reg; }

  // Get and set the number of fixed (as opposed to variable) arguments
  // that are passed in GPRs to this function.
  unsigned getVarArgsFirstGPR() const { return VarArgsFirstGPR; }
  void setVarArgsFirstGPR(unsigned GPR) { VarArgsFirstGPR = GPR; }

  // Likewise FPRs.
  unsigned getVarArgsFirstFPR() const { return VarArgsFirstFPR; }
  void setVarArgsFirstFPR(unsigned FPR) { VarArgsFirstFPR = FPR; }

  // Get and set the frame index of the first stack vararg.
  unsigned getVarArgsFrameIndex() const { return VarArgsFrameIndex; }
  void setVarArgsFrameIndex(unsigned FI) { VarArgsFrameIndex = FI; }

  // Get and set the frame index of the register save area
  // (i.e. the incoming stack pointer).
  unsigned getRegSaveFrameIndex() const { return RegSaveFrameIndex; }
  void setRegSaveFrameIndex(unsigned FI) { RegSaveFrameIndex = FI; }

  // Get and set whether the function directly manipulates the stack pointer,
  // e.g. through STACKSAVE or STACKRESTORE.
  bool getManipulatesSP() const { return ManipulatesSP; }
  void setManipulatesSP(bool MSP) { ManipulatesSP = MSP; }
};

} // end llvm namespace

#endif
