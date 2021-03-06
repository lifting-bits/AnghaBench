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
struct thread {int td_flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  MPASS (int) ; 
 int TDF_SINTR ; 
 struct thread* curthread ; 
 int sleepq_check_timeout () ; 
 int /*<<< orphan*/  sleepq_switch (void*,int) ; 
 int /*<<< orphan*/  thread_lock (struct thread*) ; 
 int /*<<< orphan*/  thread_unlock (struct thread*) ; 

int
sleepq_timedwait(void *wchan, int pri)
{
	struct thread *td;
	int rval;

	td = curthread;
	MPASS(!(td->td_flags & TDF_SINTR));
	thread_lock(td);
	sleepq_switch(wchan, pri);
	rval = sleepq_check_timeout();
	thread_unlock(td);

	return (rval);
}