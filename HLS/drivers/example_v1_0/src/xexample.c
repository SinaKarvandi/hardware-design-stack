// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
// Tool Version Limit: 2019.12
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xexample.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XExample_CfgInitialize(XExample *InstancePtr, XExample_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Bus_a_BaseAddress = ConfigPtr->Bus_a_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XExample_Start(XExample *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XExample_ReadReg(InstancePtr->Bus_a_BaseAddress, XEXAMPLE_BUS_A_ADDR_AP_CTRL) & 0x80;
    XExample_WriteReg(InstancePtr->Bus_a_BaseAddress, XEXAMPLE_BUS_A_ADDR_AP_CTRL, Data | 0x01);
}

u32 XExample_IsDone(XExample *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XExample_ReadReg(InstancePtr->Bus_a_BaseAddress, XEXAMPLE_BUS_A_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XExample_IsIdle(XExample *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XExample_ReadReg(InstancePtr->Bus_a_BaseAddress, XEXAMPLE_BUS_A_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XExample_IsReady(XExample *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XExample_ReadReg(InstancePtr->Bus_a_BaseAddress, XEXAMPLE_BUS_A_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XExample_Continue(XExample *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XExample_ReadReg(InstancePtr->Bus_a_BaseAddress, XEXAMPLE_BUS_A_ADDR_AP_CTRL) & 0x80;
    XExample_WriteReg(InstancePtr->Bus_a_BaseAddress, XEXAMPLE_BUS_A_ADDR_AP_CTRL, Data | 0x10);
}

void XExample_EnableAutoRestart(XExample *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XExample_WriteReg(InstancePtr->Bus_a_BaseAddress, XEXAMPLE_BUS_A_ADDR_AP_CTRL, 0x80);
}

void XExample_DisableAutoRestart(XExample *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XExample_WriteReg(InstancePtr->Bus_a_BaseAddress, XEXAMPLE_BUS_A_ADDR_AP_CTRL, 0);
}

void XExample_Set_a(XExample *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XExample_WriteReg(InstancePtr->Bus_a_BaseAddress, XEXAMPLE_BUS_A_ADDR_A_DATA, Data);
}

u32 XExample_Get_a(XExample *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XExample_ReadReg(InstancePtr->Bus_a_BaseAddress, XEXAMPLE_BUS_A_ADDR_A_DATA);
    return Data;
}

void XExample_Set_b(XExample *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XExample_WriteReg(InstancePtr->Bus_a_BaseAddress, XEXAMPLE_BUS_A_ADDR_B_DATA, Data);
}

u32 XExample_Get_b(XExample *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XExample_ReadReg(InstancePtr->Bus_a_BaseAddress, XEXAMPLE_BUS_A_ADDR_B_DATA);
    return Data;
}

void XExample_Set_c_i(XExample *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XExample_WriteReg(InstancePtr->Bus_a_BaseAddress, XEXAMPLE_BUS_A_ADDR_C_I_DATA, Data);
}

u32 XExample_Get_c_i(XExample *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XExample_ReadReg(InstancePtr->Bus_a_BaseAddress, XEXAMPLE_BUS_A_ADDR_C_I_DATA);
    return Data;
}

u32 XExample_Get_c_o(XExample *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XExample_ReadReg(InstancePtr->Bus_a_BaseAddress, XEXAMPLE_BUS_A_ADDR_C_O_DATA);
    return Data;
}

void XExample_InterruptGlobalEnable(XExample *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XExample_WriteReg(InstancePtr->Bus_a_BaseAddress, XEXAMPLE_BUS_A_ADDR_GIE, 1);
}

void XExample_InterruptGlobalDisable(XExample *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XExample_WriteReg(InstancePtr->Bus_a_BaseAddress, XEXAMPLE_BUS_A_ADDR_GIE, 0);
}

void XExample_InterruptEnable(XExample *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XExample_ReadReg(InstancePtr->Bus_a_BaseAddress, XEXAMPLE_BUS_A_ADDR_IER);
    XExample_WriteReg(InstancePtr->Bus_a_BaseAddress, XEXAMPLE_BUS_A_ADDR_IER, Register | Mask);
}

void XExample_InterruptDisable(XExample *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XExample_ReadReg(InstancePtr->Bus_a_BaseAddress, XEXAMPLE_BUS_A_ADDR_IER);
    XExample_WriteReg(InstancePtr->Bus_a_BaseAddress, XEXAMPLE_BUS_A_ADDR_IER, Register & (~Mask));
}

void XExample_InterruptClear(XExample *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XExample_WriteReg(InstancePtr->Bus_a_BaseAddress, XEXAMPLE_BUS_A_ADDR_ISR, Mask);
}

u32 XExample_InterruptGetEnabled(XExample *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XExample_ReadReg(InstancePtr->Bus_a_BaseAddress, XEXAMPLE_BUS_A_ADDR_IER);
}

u32 XExample_InterruptGetStatus(XExample *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XExample_ReadReg(InstancePtr->Bus_a_BaseAddress, XEXAMPLE_BUS_A_ADDR_ISR);
}

