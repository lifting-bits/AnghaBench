#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct multicall_space {int /*<<< orphan*/  mc; struct mmuext_op* args; } ;
struct TYPE_2__ {unsigned long linear_addr; } ;
struct mmuext_op {TYPE_1__ arg1; int /*<<< orphan*/  cmd; } ;

/* Variables and functions */
 int /*<<< orphan*/  DOMID_SELF ; 
 int /*<<< orphan*/  MMUEXT_INVLPG_LOCAL ; 
 int /*<<< orphan*/  MULTI_mmuext_op (int /*<<< orphan*/ ,struct mmuext_op*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 unsigned long PAGE_MASK ; 
 int /*<<< orphan*/  PARAVIRT_LAZY_MMU ; 
 int /*<<< orphan*/  preempt_disable () ; 
 int /*<<< orphan*/  preempt_enable () ; 
 struct multicall_space xen_mc_entry (int) ; 
 int /*<<< orphan*/  xen_mc_issue (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void xen_flush_tlb_single(unsigned long addr)
{
	struct mmuext_op *op;
	struct multicall_space mcs;

	preempt_disable();

	mcs = xen_mc_entry(sizeof(*op));
	op = mcs.args;
	op->cmd = MMUEXT_INVLPG_LOCAL;
	op->arg1.linear_addr = addr & PAGE_MASK;
	MULTI_mmuext_op(mcs.mc, op, 1, NULL, DOMID_SELF);

	xen_mc_issue(PARAVIRT_LAZY_MMU);

	preempt_enable();
}