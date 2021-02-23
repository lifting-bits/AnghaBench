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
struct spinlock_extra {int /*<<< orphan*/  lock; } ;
struct TYPE_3__ {struct spinlock_extra* thr_extra; } ;
typedef  TYPE_1__ spinlock_t ;

/* Variables and functions */
 int /*<<< orphan*/  THR_UMUTEX_UNLOCK (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  _get_curthread () ; 

void
__thr_spinunlock(spinlock_t *lck)
{
	struct spinlock_extra	*_extra;

	_extra = lck->thr_extra;
	THR_UMUTEX_UNLOCK(_get_curthread(), &_extra->lock);
}