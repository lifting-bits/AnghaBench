#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct inode {int dummy; } ;
struct TYPE_6__ {int /*<<< orphan*/  dentry; } ;
struct file {int f_mode; TYPE_2__ f_path; } ;
struct TYPE_5__ {int /*<<< orphan*/  owner; int /*<<< orphan*/  default_hard; } ;
struct TYPE_8__ {TYPE_1__ mach; int /*<<< orphan*/  hard; } ;
struct TYPE_7__ {scalar_t__ busy; } ;

/* Variables and functions */
 int FMODE_WRITE ; 
 TYPE_4__ dmasound ; 
 int /*<<< orphan*/  lock_kernel () ; 
 int /*<<< orphan*/  module_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  read_sq_wake_up (struct file*) ; 
 int shared_resource_owner ; 
 scalar_t__ shared_resources_initialised ; 
 int sq_fsync (struct file*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sq_reset_output () ; 
 int /*<<< orphan*/  unlock_kernel () ; 
 TYPE_3__ write_sq ; 
 int /*<<< orphan*/  write_sq_release_buffers () ; 
 int /*<<< orphan*/  write_sq_wake_up (struct file*) ; 

__attribute__((used)) static int sq_release(struct inode *inode, struct file *file)
{
	int rc = 0;

	lock_kernel();

	if (file->f_mode & FMODE_WRITE) {
		if (write_sq.busy)
			rc = sq_fsync(file, file->f_path.dentry);

		sq_reset_output() ; /* make sure dma is stopped and all is quiet */
		write_sq_release_buffers();
		write_sq.busy = 0;
	}

	if (file->f_mode & shared_resource_owner) { /* it's us that has them */
		shared_resource_owner = 0 ;
		shared_resources_initialised = 0 ;
		dmasound.hard = dmasound.mach.default_hard ;
	}

	module_put(dmasound.mach.owner);

#if 0 /* blocking open() */
	/* Wake up a process waiting for the queue being released.
	 * Note: There may be several processes waiting for a call
	 * to open() returning. */

	/* Iain: hmm I don't understand this next comment ... */
	/* There is probably a DOS atack here. They change the mode flag. */
	/* XXX add check here,*/
	read_sq_wake_up(file); /* checks f_mode */
	write_sq_wake_up(file); /* checks f_mode */
#endif /* blocking open() */

	unlock_kernel();

	return rc;
}