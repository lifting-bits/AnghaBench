#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/ * PVOID ;
typedef  int /*<<< orphan*/  PCSTR ;
typedef  int /*<<< orphan*/  HMODULE ;

/* Variables and functions */
 int /*<<< orphan*/  GetModuleHandleW (char*) ; 
 int /*<<< orphan*/ * GetProcAddress (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static
PVOID
GetProc(
    PCSTR FunctionName)
{
    HMODULE ModuleHandle;

    ModuleHandle = GetModuleHandleW(L"ws2_32");
    if (!ModuleHandle)
        return NULL;
    return GetProcAddress(ModuleHandle, FunctionName);
}