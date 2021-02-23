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
struct inode {int /*<<< orphan*/  i_ctime; int /*<<< orphan*/  i_ino; } ;
struct dentry {int /*<<< orphan*/  d_name; struct inode* d_inode; } ;

/* Variables and functions */
 int /*<<< orphan*/  CURRENT_TIME_SEC ; 
 int /*<<< orphan*/  drop_nlink (struct inode*) ; 
 int hfs_cat_delete (int /*<<< orphan*/ ,struct inode*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  hfs_delete_inode (struct inode*) ; 
 int /*<<< orphan*/  mark_inode_dirty (struct inode*) ; 

__attribute__((used)) static int hfs_unlink(struct inode *dir, struct dentry *dentry)
{
	struct inode *inode;
	int res;

	inode = dentry->d_inode;
	res = hfs_cat_delete(inode->i_ino, dir, &dentry->d_name);
	if (res)
		return res;

	drop_nlink(inode);
	hfs_delete_inode(inode);
	inode->i_ctime = CURRENT_TIME_SEC;
	mark_inode_dirty(inode);

	return res;
}