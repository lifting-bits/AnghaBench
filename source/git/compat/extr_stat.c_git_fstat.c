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
struct stat {int /*<<< orphan*/  st_mode; } ;

/* Variables and functions */
 int fstat (int,struct stat*) ; 
 int /*<<< orphan*/  mode_native_to_git (int /*<<< orphan*/ ) ; 

int git_fstat(int fd, struct stat *buf)
{
	int rc = fstat(fd, buf);
	if (rc == 0)
		buf->st_mode = mode_native_to_git(buf->st_mode);
	return rc;
}