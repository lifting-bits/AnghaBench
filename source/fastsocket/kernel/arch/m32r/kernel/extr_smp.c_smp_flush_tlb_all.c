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
 int /*<<< orphan*/  __flush_tlb_all () ; 
 int /*<<< orphan*/  flush_tlb_all_ipi ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  preempt_disable () ; 
 int /*<<< orphan*/  preempt_enable () ; 
 int /*<<< orphan*/  smp_call_function (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 

void smp_flush_tlb_all(void)
{
	unsigned long flags;

	preempt_disable();
	local_irq_save(flags);
	__flush_tlb_all();
	local_irq_restore(flags);
	smp_call_function(flush_tlb_all_ipi, NULL, 1);
	preempt_enable();
}