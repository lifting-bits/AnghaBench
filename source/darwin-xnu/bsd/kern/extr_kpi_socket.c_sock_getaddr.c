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
struct sockaddr {int dummy; } ;
typedef  int /*<<< orphan*/ * socket_t ;
typedef  int errno_t ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  socket_lock (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  socket_unlock (int /*<<< orphan*/ *,int) ; 
 int sogetaddr_locked (int /*<<< orphan*/ *,struct sockaddr**,int) ; 

errno_t
sock_getaddr(socket_t sock, struct sockaddr **psa, int peer)
{
	int error;

	if (sock == NULL || psa == NULL)
		return (EINVAL);

	socket_lock(sock, 1);
	error = sogetaddr_locked(sock, psa, peer);
	socket_unlock(sock, 1);

	return (error);
}