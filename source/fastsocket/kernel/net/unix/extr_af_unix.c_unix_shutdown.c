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
struct socket {struct sock* sk; } ;
struct sock {int sk_shutdown; scalar_t__ sk_type; int /*<<< orphan*/  sk_callback_lock; int /*<<< orphan*/  (* sk_state_change ) (struct sock*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  POLL_HUP ; 
 int /*<<< orphan*/  POLL_IN ; 
 int RCV_SHUTDOWN ; 
 int SEND_SHUTDOWN ; 
 int SHUTDOWN_MASK ; 
 scalar_t__ SOCK_SEQPACKET ; 
 scalar_t__ SOCK_STREAM ; 
 int /*<<< orphan*/  SOCK_WAKE_WAITD ; 
 int /*<<< orphan*/  read_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  read_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sk_wake_async (struct sock*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sock_hold (struct sock*) ; 
 int /*<<< orphan*/  sock_put (struct sock*) ; 
 int /*<<< orphan*/  stub1 (struct sock*) ; 
 int /*<<< orphan*/  stub2 (struct sock*) ; 
 struct sock* unix_peer (struct sock*) ; 
 int /*<<< orphan*/  unix_state_lock (struct sock*) ; 
 int /*<<< orphan*/  unix_state_unlock (struct sock*) ; 

__attribute__((used)) static int unix_shutdown(struct socket *sock, int mode)
{
	struct sock *sk = sock->sk;
	struct sock *other;

	mode = (mode+1)&(RCV_SHUTDOWN|SEND_SHUTDOWN);

	if (mode) {
		unix_state_lock(sk);
		sk->sk_shutdown |= mode;
		other = unix_peer(sk);
		if (other)
			sock_hold(other);
		unix_state_unlock(sk);
		sk->sk_state_change(sk);

		if (other &&
			(sk->sk_type == SOCK_STREAM || sk->sk_type == SOCK_SEQPACKET)) {

			int peer_mode = 0;

			if (mode&RCV_SHUTDOWN)
				peer_mode |= SEND_SHUTDOWN;
			if (mode&SEND_SHUTDOWN)
				peer_mode |= RCV_SHUTDOWN;
			unix_state_lock(other);
			other->sk_shutdown |= peer_mode;
			unix_state_unlock(other);
			other->sk_state_change(other);
			read_lock(&other->sk_callback_lock);
			if (peer_mode == SHUTDOWN_MASK)
				sk_wake_async(other, SOCK_WAKE_WAITD, POLL_HUP);
			else if (peer_mode & RCV_SHUTDOWN)
				sk_wake_async(other, SOCK_WAKE_WAITD, POLL_IN);
			read_unlock(&other->sk_callback_lock);
		}
		if (other)
			sock_put(other);
	}
	return 0;
}