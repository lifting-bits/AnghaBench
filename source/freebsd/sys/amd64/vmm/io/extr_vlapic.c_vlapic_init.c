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
struct vlapic {scalar_t__ vcpuid; int msr_apicbase; int /*<<< orphan*/  callout; int /*<<< orphan*/  timer_mtx; int /*<<< orphan*/ * apic_page; int /*<<< orphan*/ * vm; } ;

/* Variables and functions */
 int APICBASE_BSP ; 
 int APICBASE_ENABLED ; 
 int DEFAULT_APIC_BASE ; 
 int /*<<< orphan*/  KASSERT (int,char*) ; 
 int /*<<< orphan*/  MTX_SPIN ; 
 int /*<<< orphan*/  callout_init (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  mtx_init (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vlapic_reset (struct vlapic*) ; 
 scalar_t__ vm_get_maxcpus (int /*<<< orphan*/ *) ; 

void
vlapic_init(struct vlapic *vlapic)
{
	KASSERT(vlapic->vm != NULL, ("vlapic_init: vm is not initialized"));
	KASSERT(vlapic->vcpuid >= 0 &&
	    vlapic->vcpuid < vm_get_maxcpus(vlapic->vm),
	    ("vlapic_init: vcpuid is not initialized"));
	KASSERT(vlapic->apic_page != NULL, ("vlapic_init: apic_page is not "
	    "initialized"));

	/*
	 * If the vlapic is configured in x2apic mode then it will be
	 * accessed in the critical section via the MSR emulation code.
	 *
	 * Therefore the timer mutex must be a spinlock because blockable
	 * mutexes cannot be acquired in a critical section.
	 */
	mtx_init(&vlapic->timer_mtx, "vlapic timer mtx", NULL, MTX_SPIN);
	callout_init(&vlapic->callout, 1);

	vlapic->msr_apicbase = DEFAULT_APIC_BASE | APICBASE_ENABLED;

	if (vlapic->vcpuid == 0)
		vlapic->msr_apicbase |= APICBASE_BSP;

	vlapic_reset(vlapic);
}