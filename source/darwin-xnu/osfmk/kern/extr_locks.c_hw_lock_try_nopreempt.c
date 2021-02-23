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
typedef  int /*<<< orphan*/  thread_t ;
typedef  int /*<<< orphan*/  hw_lock_t ;

/* Variables and functions */
 scalar_t__ __improbable (int) ; 
 int /*<<< orphan*/  current_thread () ; 
 unsigned int hw_lock_try_internal (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  panic (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  preemption_disabled_for_thread (int /*<<< orphan*/ ) ; 

unsigned int
hw_lock_try_nopreempt(hw_lock_t lock)
{
	thread_t thread = current_thread();
	if (__improbable(!preemption_disabled_for_thread(thread)))
		panic("Attempt to test no-preempt spinlock %p in preemptible context", lock);
	return hw_lock_try_internal(lock, thread);
}