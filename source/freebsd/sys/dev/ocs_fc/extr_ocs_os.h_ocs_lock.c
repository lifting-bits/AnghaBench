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
struct TYPE_3__ {int /*<<< orphan*/  lock; } ;
typedef  TYPE_1__ ocs_lock_t ;

/* Variables and functions */
 int /*<<< orphan*/  MA_NOTOWNED ; 
 int /*<<< orphan*/  mtx_assert (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ mtx_initialized (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mtx_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  panic (char*) ; 

__attribute__((used)) static inline void
ocs_lock(ocs_lock_t *lock)
{

	if (mtx_initialized(&(lock)->lock)) {
		mtx_assert(&(lock)->lock, MA_NOTOWNED);
		mtx_lock(&(lock)->lock);
	} else {
		panic("XXX trying to lock with un-initialized mtx!?!?\n");
	}
}