#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {scalar_t__ uesp; } ;
typedef  TYPE_1__ x86_saved_state32_t ;
typedef  int /*<<< orphan*/  user_addr_t ;
typedef  scalar_t__ uint32_t ;
struct TYPE_6__ {int* ftp_argmap; int /*<<< orphan*/  ftp_nargs; } ;
typedef  TYPE_2__ fasttrap_probe_t ;

/* Variables and functions */
 int MIN (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fasttrap_fuword32_noerr (int /*<<< orphan*/ ,scalar_t__*) ; 

__attribute__((used)) static void
fasttrap_usdt_args32(fasttrap_probe_t *probe, x86_saved_state32_t *regs32, int argc,
    uint32_t *argv)
{
	int i, x, cap = MIN(argc, probe->ftp_nargs);
	uint32_t *stack = (uint32_t *)(uintptr_t)(regs32->uesp);

	for (i = 0; i < cap; i++) {
		x = probe->ftp_argmap[i];

		fasttrap_fuword32_noerr((user_addr_t)(unsigned long)&stack[x], &argv[i]);
	}

	for (; i < argc; i++) {
		argv[i] = 0;
	}
}