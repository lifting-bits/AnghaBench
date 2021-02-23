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
 int /*<<< orphan*/  _ (char*) ; 
 int access (char const*,int) ; 
 int /*<<< orphan*/  access_error_is_ok (int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  die_errno (int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  errno ; 

int access_or_die(const char *path, int mode, unsigned flag)
{
	int ret = access(path, mode);
	if (ret && !access_error_is_ok(errno, flag))
		die_errno(_("unable to access '%s'"), path);
	return ret;
}