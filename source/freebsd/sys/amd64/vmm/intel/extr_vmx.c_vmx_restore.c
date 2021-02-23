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

/* Variables and functions */
 size_t curcpu ; 
 int /*<<< orphan*/  vmxon (int /*<<< orphan*/ ) ; 
 scalar_t__* vmxon_enabled ; 
 int /*<<< orphan*/ * vmxon_region ; 

__attribute__((used)) static void
vmx_restore(void)
{

	if (vmxon_enabled[curcpu])
		vmxon(vmxon_region[curcpu]);
}