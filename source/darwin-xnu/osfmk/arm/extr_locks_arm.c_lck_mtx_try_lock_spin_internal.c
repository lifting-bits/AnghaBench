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
typedef  int /*<<< orphan*/  lck_mtx_t ;
typedef  scalar_t__ boolean_t ;

/* Variables and functions */
 uintptr_t ARM_LCK_WAITERS ; 
 scalar_t__ FALSE ; 
 uintptr_t LCK_ILOCK ; 
 uintptr_t LCK_MTX_SPIN_TAG ; 
 scalar_t__ LCK_MTX_STATE_TO_THREAD (uintptr_t) ; 
 int /*<<< orphan*/  LOCKSTAT_RECORD (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LS_LCK_MTX_TRY_SPIN_LOCK_ACQUIRE ; 
 scalar_t__ TRUE ; 
 int /*<<< orphan*/  interlock_try (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  interlock_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  load_memory_barrier () ; 
 uintptr_t ordered_load_mtx (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ordered_store_mtx (int /*<<< orphan*/ *,uintptr_t) ; 
 int /*<<< orphan*/  panic (char*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline boolean_t
lck_mtx_try_lock_spin_internal(lck_mtx_t *lock, boolean_t allow_held_as_mutex)
{
	uintptr_t	state;

	if (!interlock_try(lock))
		return FALSE;
	state = ordered_load_mtx(lock);
	if(LCK_MTX_STATE_TO_THREAD(state)) {
		// Lock is held as mutex
		if (allow_held_as_mutex)
			interlock_unlock(lock);
		else
			// "Always" variants can never block. If the lock is held as a normal mutex
			// then someone is mixing always and non-always calls on the same lock, which is
			// forbidden.
			panic("Spin-mutex held as full mutex %p", lock);
		return FALSE;
	}
	state &= ARM_LCK_WAITERS;						// Preserve waiters bit
	state |= (LCK_MTX_SPIN_TAG | LCK_ILOCK);	// Add spin tag and maintain interlock
	ordered_store_mtx(lock, state);
	load_memory_barrier();

#if	CONFIG_DTRACE
	LOCKSTAT_RECORD(LS_LCK_MTX_TRY_SPIN_LOCK_ACQUIRE, lock, 0);
#endif /* CONFIG_DTRACE */
	return TRUE;
}