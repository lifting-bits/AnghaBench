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
struct vop_symlink_args {int /*<<< orphan*/  a_dvp; } ;

/* Variables and functions */
 int /*<<< orphan*/  NOTE_WRITE ; 
 int /*<<< orphan*/  VFS_KNOTE_LOCKED (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
vop_symlink_post(void *ap, int rc)
{
	struct vop_symlink_args *a = ap;

	if (!rc)
		VFS_KNOTE_LOCKED(a->a_dvp, NOTE_WRITE);
}