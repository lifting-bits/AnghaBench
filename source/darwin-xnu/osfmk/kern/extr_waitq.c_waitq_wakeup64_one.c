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
typedef  int /*<<< orphan*/  wait_result_t ;
typedef  int /*<<< orphan*/  uint64_t ;
struct waitq {int dummy; } ;
typedef  int /*<<< orphan*/  spl_t ;
typedef  int /*<<< orphan*/  kern_return_t ;
typedef  int /*<<< orphan*/  event64_t ;

/* Variables and functions */
 int /*<<< orphan*/  WAITQ_KEEP_LOCKED ; 
 int /*<<< orphan*/  WAITQ_UNLOCK ; 
 int /*<<< orphan*/  panic (char*,struct waitq*) ; 
 int /*<<< orphan*/  splsched () ; 
 int /*<<< orphan*/  splx (int /*<<< orphan*/ ) ; 
 scalar_t__ waitq_irq_safe (struct waitq*) ; 
 int /*<<< orphan*/  waitq_lock (struct waitq*) ; 
 int /*<<< orphan*/  waitq_prepost_release_reserve (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  waitq_prepost_reserve (struct waitq*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  waitq_valid (struct waitq*) ; 
 int /*<<< orphan*/  waitq_wakeup64_one_locked (struct waitq*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 

kern_return_t waitq_wakeup64_one(struct waitq *waitq, event64_t wake_event,
				 wait_result_t result, int priority)
{
	kern_return_t kr;
	uint64_t reserved_preposts = 0;
	spl_t spl;

	if (!waitq_valid(waitq))
		panic("Invalid waitq: %p", waitq);

	if (!waitq_irq_safe(waitq)) {
		/* reserve preposts in addition to locking the waitq */
		reserved_preposts = waitq_prepost_reserve(waitq, 0, WAITQ_KEEP_LOCKED);
	} else {
		spl = splsched();
		waitq_lock(waitq);
	}

	/* waitq is locked upon return */
	kr = waitq_wakeup64_one_locked(waitq, wake_event, result,
				       &reserved_preposts, priority, WAITQ_UNLOCK);

	if (waitq_irq_safe(waitq))
		splx(spl);

	/* release any left-over prepost object (won't block/lock anything) */
	waitq_prepost_release_reserve(reserved_preposts);

	return kr;
}