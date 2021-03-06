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
typedef  int /*<<< orphan*/  rll_t ;
struct TYPE_4__ {int /*<<< orphan*/ * rl_lock; } ;
typedef  TYPE_1__ rl_t ;

/* Variables and functions */
 int /*<<< orphan*/  umem_free (TYPE_1__*,int) ; 
 int /*<<< orphan*/  ztest_rll_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
ztest_range_unlock(rl_t *rl)
{
	rll_t *rll = rl->rl_lock;

	ztest_rll_unlock(rll);

	umem_free(rl, sizeof (*rl));
}