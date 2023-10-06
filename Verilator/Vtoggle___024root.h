// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtoggle.h for the primary calling header

#ifndef VERILATED_VTOGGLE___024ROOT_H_
#define VERILATED_VTOGGLE___024ROOT_H_  // guard

#include "verilated.h"

class Vtoggle__Syms;

class Vtoggle___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clock,0,0);
    VL_OUT8(switch_,0,0);
    CData/*0:0*/ Switch_Control__DOT__toggle;
    CData/*0:0*/ __Vclklast__TOP__clock;

    // INTERNAL VARIABLES
    Vtoggle__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtoggle___024root(Vtoggle__Syms* symsp, const char* name);
    ~Vtoggle___024root();
    VL_UNCOPYABLE(Vtoggle___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
