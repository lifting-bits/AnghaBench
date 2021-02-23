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
struct rpc_xprt {int /*<<< orphan*/  sending; int /*<<< orphan*/  state; } ;

/* Variables and functions */
 int /*<<< orphan*/  XPRT_LOCKED ; 
 int /*<<< orphan*/  __xprt_lock_write_func ; 
 scalar_t__ rpc_wake_up_first (int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct rpc_xprt*) ; 
 scalar_t__ test_and_set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xprt_clear_locked (struct rpc_xprt*) ; 

__attribute__((used)) static void __xprt_lock_write_next(struct rpc_xprt *xprt)
{
	if (test_and_set_bit(XPRT_LOCKED, &xprt->state))
		return;

	if (rpc_wake_up_first(&xprt->sending, __xprt_lock_write_func, xprt))
		return;
	xprt_clear_locked(xprt);
}