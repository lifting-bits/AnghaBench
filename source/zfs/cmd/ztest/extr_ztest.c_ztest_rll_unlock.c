#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {scalar_t__ rll_readers; int /*<<< orphan*/  rll_lock; int /*<<< orphan*/  rll_cv; int /*<<< orphan*/ * rll_writer; } ;
typedef  TYPE_1__ rll_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  cv_broadcast (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_enter (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_exit (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
ztest_rll_unlock(rll_t *rll)
{
	mutex_enter(&rll->rll_lock);

	if (rll->rll_writer) {
		ASSERT(rll->rll_readers == 0);
		rll->rll_writer = NULL;
	} else {
		ASSERT(rll->rll_readers != 0);
		ASSERT(rll->rll_writer == NULL);
		rll->rll_readers--;
	}

	if (rll->rll_writer == NULL && rll->rll_readers == 0)
		cv_broadcast(&rll->rll_cv);

	mutex_exit(&rll->rll_lock);
}