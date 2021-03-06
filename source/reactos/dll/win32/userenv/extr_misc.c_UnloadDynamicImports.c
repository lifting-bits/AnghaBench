#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  VOID ;
struct TYPE_3__ {scalar_t__ hModule; } ;
typedef  TYPE_1__* PDYN_FUNCS ;
typedef  scalar_t__ HMODULE ;

/* Variables and functions */
 int /*<<< orphan*/  FreeLibrary (scalar_t__) ; 

VOID
UnloadDynamicImports(PDYN_FUNCS DynFuncs)
{
    if (DynFuncs->hModule)
    {
        FreeLibrary(DynFuncs->hModule);
        DynFuncs->hModule = (HMODULE)0;
    }
}