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
struct socket {int dummy; } ;
struct msghdr {int /*<<< orphan*/  msg_iter; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  READ ; 
 int /*<<< orphan*/  iov_iter_discard (int /*<<< orphan*/ *,int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  sock_recvmsg (struct socket*,struct msghdr*,int) ; 

__attribute__((used)) static ssize_t
xs_read_discard(struct socket *sock, struct msghdr *msg, int flags,
		size_t count)
{
	iov_iter_discard(&msg->msg_iter, READ, count);
	return sock_recvmsg(sock, msg, flags);
}