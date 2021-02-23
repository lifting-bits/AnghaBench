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
typedef  int /*<<< orphan*/  fd_set ;

/* Variables and functions */
 int /*<<< orphan*/  FD_SET (int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int
fd_add(int fd, fd_set *fdset, int nfds)
{

	/*
	 * Skip sockets which we failed to bind.
	 */
	if (fd <= 0)
		return (nfds);

	FD_SET(fd, fdset);
	if (fd > nfds)
		nfds = fd;
	return (nfds);
}