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
struct null_args {int /*<<< orphan*/  nulla_target; } ;
typedef  int /*<<< orphan*/  nargs ;

/* Variables and functions */
 int /*<<< orphan*/  MOUNT_NULL ; 
 int /*<<< orphan*/  __UNCONST (char const*) ; 
 int /*<<< orphan*/  atf_tc_fail_errno (char*) ; 
 int /*<<< orphan*/  memset (struct null_args*,int /*<<< orphan*/ ,int) ; 
 int rump_sys_mount (int /*<<< orphan*/ ,char const*,int,struct null_args*,int) ; 

__attribute__((used)) static void
mountnull(const char *what, const char *mp, int flags)
{
	struct null_args nargs;

	memset(&nargs, 0, sizeof(nargs));
	nargs.nulla_target = __UNCONST(what);
	if (rump_sys_mount(MOUNT_NULL, mp, flags, &nargs, sizeof(nargs)) == -1)
		atf_tc_fail_errno("could not mount nullfs");

}