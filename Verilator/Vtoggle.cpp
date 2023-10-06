// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtoggle.h"
#include "Vtoggle__Syms.h"

//============================================================
// Constructors

Vtoggle::Vtoggle(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtoggle__Syms(contextp(), _vcname__, this)}
    , clock{vlSymsp->TOP.clock}
    , switch_{vlSymsp->TOP.switch_}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtoggle::Vtoggle(const char* _vcname__)
    : Vtoggle(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtoggle::~Vtoggle() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vtoggle___024root___eval_initial(Vtoggle___024root* vlSelf);
void Vtoggle___024root___eval_settle(Vtoggle___024root* vlSelf);
void Vtoggle___024root___eval(Vtoggle___024root* vlSelf);
#ifdef VL_DEBUG
void Vtoggle___024root___eval_debug_assertions(Vtoggle___024root* vlSelf);
#endif  // VL_DEBUG
void Vtoggle___024root___final(Vtoggle___024root* vlSelf);

static void _eval_initial_loop(Vtoggle__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vtoggle___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vtoggle___024root___eval_settle(&(vlSymsp->TOP));
        Vtoggle___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vtoggle::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtoggle::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtoggle___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vtoggle___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vtoggle::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vtoggle::final() {
    Vtoggle___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtoggle::hierName() const { return vlSymsp->name(); }
const char* Vtoggle::modelName() const { return "Vtoggle"; }
unsigned Vtoggle::threads() const { return 1; }
