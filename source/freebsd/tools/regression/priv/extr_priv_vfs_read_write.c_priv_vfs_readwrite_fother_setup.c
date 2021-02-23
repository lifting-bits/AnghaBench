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
struct test {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  GID_OTHER ; 
 int /*<<< orphan*/  UID_OTHER ; 
 int /*<<< orphan*/  fpath_none ; 
 int fpath_none_initialized ; 
 int /*<<< orphan*/  fpath_read ; 
 int fpath_read_initialized ; 
 int /*<<< orphan*/  fpath_readwrite ; 
 int fpath_readwrite_initialized ; 
 int /*<<< orphan*/  fpath_write ; 
 int fpath_write_initialized ; 
 int /*<<< orphan*/  setup_file (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

int
priv_vfs_readwrite_fother_setup(int asroot, int injail, struct test *test)
{

	setup_file("priv_vfs_readwrite_fother_setup: fpath_none", fpath_none,
	    UID_OTHER, GID_OTHER, 0000);
	fpath_none_initialized = 1;
	setup_file("priv_vfs_readwrite_fother_setup: fpath_read", fpath_read,
	    UID_OTHER, GID_OTHER, 0004);
	fpath_read_initialized = 1;
	setup_file("priv_vfs_readwrite_fother_setup: fpath_write",
	    fpath_write, UID_OTHER, GID_OTHER, 0002);
	fpath_write_initialized = 1;
	setup_file("priv_vfs_readwrite_fother_setup: fpath_readwrite",
	    fpath_readwrite, UID_OTHER, GID_OTHER, 0006);
	fpath_readwrite_initialized = 1;
	return (0);
}