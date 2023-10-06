// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtoggle.h for the primary calling header

#include "verilated.h"

#include "Vtoggle__Syms.h"
#include "Vtoggle___024root.h"

void Vtoggle___024root___ctor_var_reset(Vtoggle___024root* vlSelf);

Vtoggle___024root::Vtoggle___024root(Vtoggle__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtoggle___024root___ctor_var_reset(this);
}

void Vtoggle___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtoggle___024root::~Vtoggle___024root() {
}
