#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint64_t ;
typedef  TYPE_1__* pmap_t ;
struct TYPE_4__ {int /*<<< orphan*/  pm_cookie; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASID_TO_OPERAND (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  COOKIE_TO_ASID (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dsb (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  isb () ; 
 int /*<<< orphan*/  ish ; 
 int /*<<< orphan*/  ishst ; 
 TYPE_1__* kernel_pmap ; 
 int /*<<< orphan*/  sched_pin () ; 
 int /*<<< orphan*/  sched_unpin () ; 

__attribute__((used)) static __inline void
pmap_invalidate_all(pmap_t pmap)
{
	uint64_t r;

	sched_pin();
	dsb(ishst);
	if (pmap == kernel_pmap) {
		__asm __volatile("tlbi vmalle1is");
	} else {
		r = ASID_TO_OPERAND(COOKIE_TO_ASID(pmap->pm_cookie));
		__asm __volatile("tlbi aside1is, %0" : : "r" (r));
	}
	dsb(ish);
	isb();
	sched_unpin();
}