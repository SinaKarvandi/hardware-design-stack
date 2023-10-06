// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
// Tool Version Limit: 2019.12
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XEXAMPLE_H
#define XEXAMPLE_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xexample_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
    u16 DeviceId;
    u64 Bus_a_BaseAddress;
} XExample_Config;
#endif

typedef struct {
    u64 Bus_a_BaseAddress;
    u32 IsReady;
} XExample;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XExample_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XExample_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XExample_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XExample_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XExample_Initialize(XExample *InstancePtr, u16 DeviceId);
XExample_Config* XExample_LookupConfig(u16 DeviceId);
int XExample_CfgInitialize(XExample *InstancePtr, XExample_Config *ConfigPtr);
#else
int XExample_Initialize(XExample *InstancePtr, const char* InstanceName);
int XExample_Release(XExample *InstancePtr);
#endif

void XExample_Start(XExample *InstancePtr);
u32 XExample_IsDone(XExample *InstancePtr);
u32 XExample_IsIdle(XExample *InstancePtr);
u32 XExample_IsReady(XExample *InstancePtr);
void XExample_Continue(XExample *InstancePtr);
void XExample_EnableAutoRestart(XExample *InstancePtr);
void XExample_DisableAutoRestart(XExample *InstancePtr);

void XExample_Set_a(XExample *InstancePtr, u32 Data);
u32 XExample_Get_a(XExample *InstancePtr);
void XExample_Set_b(XExample *InstancePtr, u32 Data);
u32 XExample_Get_b(XExample *InstancePtr);
void XExample_Set_c_i(XExample *InstancePtr, u32 Data);
u32 XExample_Get_c_i(XExample *InstancePtr);
u32 XExample_Get_c_o(XExample *InstancePtr);

void XExample_InterruptGlobalEnable(XExample *InstancePtr);
void XExample_InterruptGlobalDisable(XExample *InstancePtr);
void XExample_InterruptEnable(XExample *InstancePtr, u32 Mask);
void XExample_InterruptDisable(XExample *InstancePtr, u32 Mask);
void XExample_InterruptClear(XExample *InstancePtr, u32 Mask);
u32 XExample_InterruptGetEnabled(XExample *InstancePtr);
u32 XExample_InterruptGetStatus(XExample *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
