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
 int /*<<< orphan*/  LHCALL_FLUSH_ASYNC ; 
 int /*<<< orphan*/  kvm_hypercall0 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  paravirt_leave_lazy_mmu () ; 

__attribute__((used)) static void lguest_leave_lazy_mmu_mode(void)
{
	kvm_hypercall0(LHCALL_FLUSH_ASYNC);
	paravirt_leave_lazy_mmu();
}