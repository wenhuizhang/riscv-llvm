//===-- RISCVMCFixups.h - RISCV-specific fixup entries ----------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_RISCV_RISCVMCFIXUPS_H
#define LLVM_LIB_TARGET_RISCV_RISCVMCFIXUPS_H

#include "llvm/MC/MCFixup.h"

namespace llvm {
namespace RISCV {
  enum FixupKind {
    // These correspond directly to RISCV relocations.
    fixup_riscv_brlo = FirstTargetFixupKind,
    fixup_riscv_brhi,
    fixup_riscv_jal,
    fixup_riscv_call,
    fixup_riscv_call_plt,

    // fixups for %*(sym) opertions
    fixup_riscv_lo12,
    fixup_riscv_hi20,
    fixup_riscv_pcrel_lo12,
    fixup_riscv_pcrel_hi20,
    fixup_riscv_tprel_lo12,
    fixup_riscv_tprel_hi20,

    // Marker
    LastTargetFixupKind,
    NumTargetFixupKinds = LastTargetFixupKind - FirstTargetFixupKind
  };
}
} // end namespace llvm

#endif
