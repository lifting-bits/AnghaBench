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
struct TYPE_3__ {int num_bufs; int /*<<< orphan*/  lock; int /*<<< orphan*/ * refcnt; } ;
typedef  TYPE_1__ Pool ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 

void pool_acquire(Pool *s, int idx) {
  pthread_mutex_lock(&s->lock);

  assert(idx >= 0 && idx < s->num_bufs);

  s->refcnt[idx]++;

  pthread_mutex_unlock(&s->lock);
}