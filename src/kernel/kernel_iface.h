//
// Kernel Interface
//
#pragma once
#ifdef __INTELLISENSE__
#ifndef _ARCH_
#define _ARCH_ x86_64
#define __amd64__ 1
#define _BOARD_ pc
#define __attribute__(x)
#define _HAS_CXX17 1
#endif
#endif

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
#include <stddef.h>
#ifndef __cplusplus
#include <stdbool.h>
#endif

struct BootParameters;

void Kernel_Main(const struct BootParameters* pParams);
bool Kernel_IncrementTick();
void Kernel_SwitchThreadContext();

extern uintptr_t g_CurrentThreadContext;

#ifdef __cplusplus
}
#endif

#ifndef MAKEPATH

#define IDENT(x) x
#define XSTR(x) #x
#define STR(x) XSTR(x)
#define MAKEPATH(x,y) STR(IDENT(x)IDENT(y))
#define MAKEPATH3(x,y,z) STR(IDENT(x)IDENT(y)IDENT(z))

#endif
