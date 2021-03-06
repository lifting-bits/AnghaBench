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
typedef  int /*<<< orphan*/  uint64_t ;
struct mt_cpu {int dummy; } ;

/* Variables and functions */
 scalar_t__ FALSE ; 
 int /*<<< orphan*/  assert (int) ; 
 scalar_t__ ml_get_interrupts_enabled () ; 
 struct mt_cpu* mt_cur_cpu () ; 
 int /*<<< orphan*/  mt_mtc_update_fixed_counts (struct mt_cpu*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
mt_fixed_counts_internal(uint64_t *counts, uint64_t *counts_since)
{
	assert(ml_get_interrupts_enabled() == FALSE);

	struct mt_cpu *mtc = mt_cur_cpu();
	assert(mtc != NULL);

	mt_mtc_update_fixed_counts(mtc, counts, counts_since);
}