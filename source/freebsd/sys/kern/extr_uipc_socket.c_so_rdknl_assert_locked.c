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
struct socket {int /*<<< orphan*/  so_rcv; } ;

/* Variables and functions */
 int /*<<< orphan*/  SOCKBUF_LOCK_ASSERT (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SOCK_LOCK_ASSERT (struct socket*) ; 
 scalar_t__ SOLISTENING (struct socket*) ; 

__attribute__((used)) static void
so_rdknl_assert_locked(void *arg)
{
	struct socket *so = arg;

	if (SOLISTENING(so))
		SOCK_LOCK_ASSERT(so);
	else
		SOCKBUF_LOCK_ASSERT(&so->so_rcv);
}