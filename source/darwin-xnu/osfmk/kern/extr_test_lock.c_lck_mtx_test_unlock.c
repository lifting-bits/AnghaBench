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

/* Variables and functions */
 int /*<<< orphan*/  TEST_MTX_UNLOCK_MTX_STATS ; 
 int /*<<< orphan*/  lck_mtx_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mach_absolute_time () ; 
 int /*<<< orphan*/  test_mtx ; 
 int /*<<< orphan*/  update_test_mtx_stats (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
lck_mtx_test_unlock(void)
{
	uint64_t start;

	start = mach_absolute_time();

	lck_mtx_unlock(&test_mtx);

	update_test_mtx_stats(start, mach_absolute_time(), TEST_MTX_UNLOCK_MTX_STATS);
}