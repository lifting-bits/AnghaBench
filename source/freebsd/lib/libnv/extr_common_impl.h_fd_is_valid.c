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

/* Variables and functions */
 scalar_t__ EBADF ; 
 int /*<<< orphan*/  F_GETFD ; 
 scalar_t__ errno ; 
 int fcntl (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline bool
fd_is_valid(int fd)
{

	return (fcntl(fd, F_GETFD) != -1 || errno != EBADF);
}