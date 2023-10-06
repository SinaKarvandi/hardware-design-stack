// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtoggle.h for the primary calling header

#include "verilated.h"

#include "Vtoggle___024root.h"

VL_INLINE_OPT void Vtoggle___024root___sequent__TOP__0(Vtoggle___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoggle__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoggle___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->Switch_Control__DOT__toggle = (1U & (~ (IData)(vlSelf->Switch_Control__DOT__toggle)));
    vlSelf->switch_ = vlSelf->Switch_Control__DOT__toggle;
}

void Vtoggle___024root___eval(Vtoggle___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoggle__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoggle___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clock) & (~ (IData)(vlSelf->__Vclklast__TOP__clock)))) {
        Vtoggle___024root___sequent__TOP__0(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clock = vlSelf->clock;
}

#ifdef VL_DEBUG
void Vtoggle___024root___eval_debug_assertions(Vtoggle___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoggle__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoggle___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
}
#endif  // VL_DEBUG
