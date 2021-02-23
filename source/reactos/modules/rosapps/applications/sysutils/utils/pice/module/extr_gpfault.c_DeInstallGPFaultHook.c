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
typedef  int /*<<< orphan*/  ULONG ;

/* Variables and functions */
 int /*<<< orphan*/  ENTER_FUNC () ; 
 int /*<<< orphan*/  LEAVE_FUNC () ; 
 int /*<<< orphan*/  MaskIrqs () ; 
 scalar_t__ OldGPFaultHandler ; 
 int /*<<< orphan*/  RemoveAllSWBreakpoints (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetGlobalInt (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  UnmaskIrqs () ; 

void DeInstallGPFaultHook(void)
{
	ENTER_FUNC();

	MaskIrqs();
	if(OldGPFaultHandler)
	{
        RemoveAllSWBreakpoints(TRUE);
		SetGlobalInt(0x0D,(ULONG)OldGPFaultHandler);
        OldGPFaultHandler=0;
	}
	UnmaskIrqs();

    LEAVE_FUNC();
}