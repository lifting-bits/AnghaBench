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
 int /*<<< orphan*/  hw_lock_lock_internal (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  panic (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  preemption_disabled_for_thread (int /*<<< orphan*/ ) ; 

void
hw_lock_lock_nopreempt(hw_lock_t lock)
{
	thread_t thread = current_thread();
	if (__improbable(!preemption_disabled_for_thread(thread)))
		panic("Attempt to take no-preempt spinlock %p in preemptible context", lock);
	hw_lock_lock_internal(lock, thread);
}