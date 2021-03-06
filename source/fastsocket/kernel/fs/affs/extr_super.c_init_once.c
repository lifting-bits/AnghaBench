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
struct affs_inode_info {int /*<<< orphan*/  vfs_inode; int /*<<< orphan*/  i_ext_lock; int /*<<< orphan*/  i_link_lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  init_MUTEX (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  inode_init_once (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void init_once(void *foo)
{
	struct affs_inode_info *ei = (struct affs_inode_info *) foo;

	init_MUTEX(&ei->i_link_lock);
	init_MUTEX(&ei->i_ext_lock);
	inode_init_once(&ei->vfs_inode);
}