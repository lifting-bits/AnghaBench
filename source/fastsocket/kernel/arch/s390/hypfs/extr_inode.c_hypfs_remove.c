#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct dentry {TYPE_1__* d_inode; struct dentry* d_parent; } ;
struct TYPE_3__ {int /*<<< orphan*/  i_mutex; int /*<<< orphan*/  i_mode; } ;

/* Variables and functions */
 scalar_t__ S_ISDIR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  d_delete (struct dentry*) ; 
 int /*<<< orphan*/  dput (struct dentry*) ; 
 scalar_t__ hypfs_positive (struct dentry*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  simple_rmdir (TYPE_1__*,struct dentry*) ; 
 int /*<<< orphan*/  simple_unlink (TYPE_1__*,struct dentry*) ; 

__attribute__((used)) static void hypfs_remove(struct dentry *dentry)
{
	struct dentry *parent;

	parent = dentry->d_parent;
	if (!parent || !parent->d_inode)
		return;
	mutex_lock(&parent->d_inode->i_mutex);
	if (hypfs_positive(dentry)) {
		if (S_ISDIR(dentry->d_inode->i_mode))
			simple_rmdir(parent->d_inode, dentry);
		else
			simple_unlink(parent->d_inode, dentry);
	}
	d_delete(dentry);
	dput(dentry);
	mutex_unlock(&parent->d_inode->i_mutex);
}