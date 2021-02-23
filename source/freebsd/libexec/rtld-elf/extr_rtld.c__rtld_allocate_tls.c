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
typedef  int /*<<< orphan*/  RtldLockState ;

/* Variables and functions */
 int /*<<< orphan*/  TAILQ_FIRST (int /*<<< orphan*/ *) ; 
 void* allocate_tls (int /*<<< orphan*/ ,void*,size_t,size_t) ; 
 int /*<<< orphan*/  globallist_curr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lock_release (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  obj_list ; 
 int /*<<< orphan*/  rtld_bind_lock ; 
 int /*<<< orphan*/  wlock_acquire (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

void *
_rtld_allocate_tls(void *oldtls, size_t tcbsize, size_t tcbalign)
{
    void *ret;
    RtldLockState lockstate;

    wlock_acquire(rtld_bind_lock, &lockstate);
    ret = allocate_tls(globallist_curr(TAILQ_FIRST(&obj_list)), oldtls,
      tcbsize, tcbalign);
    lock_release(rtld_bind_lock, &lockstate);
    return (ret);
}