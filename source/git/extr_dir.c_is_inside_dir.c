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
 scalar_t__ dir_inside_of (char*,char const*) ; 
 int /*<<< orphan*/  free (char*) ; 
 char* xgetcwd () ; 

int is_inside_dir(const char *dir)
{
	char *cwd;
	int rc;

	if (!dir)
		return 0;

	cwd = xgetcwd();
	rc = (dir_inside_of(cwd, dir) >= 0);
	free(cwd);
	return rc;
}