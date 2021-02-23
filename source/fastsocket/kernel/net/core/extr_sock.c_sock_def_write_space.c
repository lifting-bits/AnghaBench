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
struct sock {int sk_sndbuf; int /*<<< orphan*/  sk_callback_lock; int /*<<< orphan*/  sk_sleep; int /*<<< orphan*/  sk_wmem_alloc; } ;

/* Variables and functions */
 int POLLOUT ; 
 int POLLWRBAND ; 
 int POLLWRNORM ; 
 int /*<<< orphan*/  POLL_OUT ; 
 int /*<<< orphan*/  SOCK_WAKE_SPACE ; 
 int atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  read_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  read_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ sk_has_sleeper (struct sock*) ; 
 int /*<<< orphan*/  sk_wake_async (struct sock*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ sock_writeable (struct sock*) ; 
 int /*<<< orphan*/  wake_up_interruptible_sync_poll (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void sock_def_write_space(struct sock *sk)
{
	read_lock(&sk->sk_callback_lock);

	/* Do not wake up a writer until he can make "significant"
	 * progress.  --DaveM
	 */
	if ((atomic_read(&sk->sk_wmem_alloc) << 1) <= sk->sk_sndbuf) {
		if (sk_has_sleeper(sk))
			wake_up_interruptible_sync_poll(sk->sk_sleep, POLLOUT |
						POLLWRNORM | POLLWRBAND);

		/* Should agree with poll, otherwise some programs break */
		if (sock_writeable(sk))
			sk_wake_async(sk, SOCK_WAKE_SPACE, POLL_OUT);
	}

	read_unlock(&sk->sk_callback_lock);
}