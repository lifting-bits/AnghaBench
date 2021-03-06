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
struct fscache_cookie {int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  FSCACHE_COOKIE_INVALIDATING ; 
 int /*<<< orphan*/  TASK_UNINTERRUPTIBLE ; 
 int /*<<< orphan*/  _enter (char*,struct fscache_cookie*) ; 
 int /*<<< orphan*/  _leave (char*) ; 
 int /*<<< orphan*/  fscache_wait_bit_interruptible ; 
 int /*<<< orphan*/  wait_on_bit (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void __fscache_wait_on_invalidate(struct fscache_cookie *cookie)
{
	_enter("%p", cookie);

	wait_on_bit(&cookie->flags, FSCACHE_COOKIE_INVALIDATING,
		    fscache_wait_bit_interruptible,
		    TASK_UNINTERRUPTIBLE);

	_leave("");
}