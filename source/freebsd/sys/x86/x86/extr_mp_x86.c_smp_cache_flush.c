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
 int /*<<< orphan*/  IPI_INVLCACHE ; 
 int /*<<< orphan*/  all_cpus ; 
 scalar_t__ smp_started ; 
 int /*<<< orphan*/  smp_targeted_tlb_shootdown (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
smp_cache_flush(void)
{

	if (smp_started) {
		smp_targeted_tlb_shootdown(all_cpus, IPI_INVLCACHE, NULL,
		    0, 0);
	}
}