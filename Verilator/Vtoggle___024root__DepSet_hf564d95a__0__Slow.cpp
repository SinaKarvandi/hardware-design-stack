// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtoggle.h for the primary calling header

#include "verilated.h"

#include "Vtoggle___024root.h"

VL_ATTR_COLD void Vtoggle___024root___initial__TOP__0(Vtoggle___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoggle__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoggle___024root___initial__TOP__0\n"); );
    // Body
    vlSelf->switch_ = 0U;
    vlSelf->Switch_Control__DOT__toggle = 0U;
}

VL_ATTR_COLD void Vtoggle___024root___settle__TOP__0(Vtoggle___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoggle__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoggle___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->switch_ = vlSelf->Switch_Control__DOT__toggle;
}

VL_ATTR_COLD void Vtoggle___024root___eval_initial(Vtoggle___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoggle__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoggle___024root___eval_initial\n"); );
    // Body
    Vtoggle___024root___initial__TOP__0(vlSelf);
    vlSelf->__Vclklast__TOP__clock = vlSelf->clock;
}

VL_ATTR_COLD void Vtoggle___024root___eval_settle(Vtoggle___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoggle__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoggle___024root___eval_settle\n"); );
    // Body
    Vtoggle___024root___settle__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vtoggle___024root___final(Vtoggle___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoggle__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoggle___024root___final\n"); );
}

VL_ATTR_COLD void Vtoggle___024root___ctor_var_reset(Vtoggle___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoggle__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoggle___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->switch_ = VL_RAND_RESET_I(1);
    vlSelf->Switch_Control__DOT__toggle = VL_RAND_RESET_I(1);
}
