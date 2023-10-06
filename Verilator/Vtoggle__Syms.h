// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOGGLE__SYMS_H_
#define VERILATED_VTOGGLE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtoggle.h"

// INCLUDE MODULE CLASSES
#include "Vtoggle___024root.h"

// SYMS CLASS (contains all model state)
class Vtoggle__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtoggle* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtoggle___024root              TOP;

    // CONSTRUCTORS
    Vtoggle__Syms(VerilatedContext* contextp, const char* namep, Vtoggle* modelp);
    ~Vtoggle__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
