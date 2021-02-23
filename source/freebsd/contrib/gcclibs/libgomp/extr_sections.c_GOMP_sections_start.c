#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {TYPE_2__* work_share; } ;
struct gomp_thread {TYPE_1__ ts; } ;
struct TYPE_4__ {int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 scalar_t__ gomp_iter_dynamic_next_locked (long*,long*) ; 
 int /*<<< orphan*/  gomp_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gomp_sections_init (TYPE_2__*,unsigned int) ; 
 struct gomp_thread* gomp_thread () ; 
 scalar_t__ gomp_work_share_start (int) ; 

unsigned
GOMP_sections_start (unsigned count)
{
  struct gomp_thread *thr = gomp_thread ();
  long s, e, ret;

  if (gomp_work_share_start (false))
    gomp_sections_init (thr->ts.work_share, count);

  if (gomp_iter_dynamic_next_locked (&s, &e))
    ret = s;
  else
    ret = 0;

  gomp_mutex_unlock (&thr->ts.work_share->lock);

  return ret;
}