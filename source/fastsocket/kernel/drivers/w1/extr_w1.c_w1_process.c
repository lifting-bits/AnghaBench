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
struct w1_master {int /*<<< orphan*/  refcnt; scalar_t__ search_count; int /*<<< orphan*/  mutex; } ;

/* Variables and functions */
 int /*<<< orphan*/  TASK_INTERRUPTIBLE ; 
 int /*<<< orphan*/  W1_SEARCH ; 
 int /*<<< orphan*/  __set_current_state (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  atomic_dec (int /*<<< orphan*/ *) ; 
 scalar_t__ kthread_should_stop () ; 
 unsigned long msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  schedule () ; 
 int /*<<< orphan*/  schedule_timeout (unsigned long const) ; 
 int /*<<< orphan*/  try_to_freeze () ; 
 int /*<<< orphan*/  w1_search_process (struct w1_master*,int /*<<< orphan*/ ) ; 
 int w1_timeout ; 

int w1_process(void *data)
{
	struct w1_master *dev = (struct w1_master *) data;
	/* As long as w1_timeout is only set by a module parameter the sleep
	 * time can be calculated in jiffies once.
	 */
	const unsigned long jtime = msecs_to_jiffies(w1_timeout * 1000);

	while (!kthread_should_stop()) {
		if (dev->search_count) {
			mutex_lock(&dev->mutex);
			w1_search_process(dev, W1_SEARCH);
			mutex_unlock(&dev->mutex);
		}

		try_to_freeze();
		__set_current_state(TASK_INTERRUPTIBLE);

		if (kthread_should_stop())
			break;

		/* Only sleep when the search is active. */
		if (dev->search_count)
			schedule_timeout(jtime);
		else
			schedule();
	}

	atomic_dec(&dev->refcnt);

	return 0;
}