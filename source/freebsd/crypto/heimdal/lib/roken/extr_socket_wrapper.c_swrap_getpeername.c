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
struct socket_info {int /*<<< orphan*/  peername_len; int /*<<< orphan*/  peername; } ;
struct sockaddr {int dummy; } ;
typedef  int /*<<< orphan*/  socklen_t ;

/* Variables and functions */
 int /*<<< orphan*/  ENOTCONN ; 
 int /*<<< orphan*/  errno ; 
 struct socket_info* find_socket_info (int) ; 
 int /*<<< orphan*/  memcpy (struct sockaddr*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int real_getpeername (int,struct sockaddr*,int /*<<< orphan*/ *) ; 

int swrap_getpeername(int s, struct sockaddr *name, socklen_t *addrlen)
{
	struct socket_info *si = find_socket_info(s);

	if (!si) {
		return real_getpeername(s, name, addrlen);
	}

	if (!si->peername)
	{
		errno = ENOTCONN;
		return -1;
	}

	memcpy(name, si->peername, si->peername_len);
	*addrlen = si->peername_len;

	return 0;
}