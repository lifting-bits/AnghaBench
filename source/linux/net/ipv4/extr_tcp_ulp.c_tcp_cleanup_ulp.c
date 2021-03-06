#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct sock {int dummy; } ;
struct inet_connection_sock {TYPE_1__* icsk_ulp_ops; } ;
struct TYPE_2__ {int /*<<< orphan*/  owner; int /*<<< orphan*/  (* release ) (struct sock*) ;} ;

/* Variables and functions */
 struct inet_connection_sock* inet_csk (struct sock*) ; 
 int /*<<< orphan*/  module_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct sock*) ; 

void tcp_cleanup_ulp(struct sock *sk)
{
	struct inet_connection_sock *icsk = inet_csk(sk);

	/* No sock_owned_by_me() check here as at the time the
	 * stack calls this function, the socket is dead and
	 * about to be destroyed.
	 */
	if (!icsk->icsk_ulp_ops)
		return;

	if (icsk->icsk_ulp_ops->release)
		icsk->icsk_ulp_ops->release(sk);
	module_put(icsk->icsk_ulp_ops->owner);

	icsk->icsk_ulp_ops = NULL;
}