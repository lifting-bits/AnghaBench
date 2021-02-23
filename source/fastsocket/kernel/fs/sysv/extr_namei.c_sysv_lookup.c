#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct nameidata {int dummy; } ;
struct inode {TYPE_3__* i_sb; } ;
struct TYPE_5__ {scalar_t__ len; } ;
struct dentry {TYPE_2__ d_name; int /*<<< orphan*/  d_op; } ;
typedef  scalar_t__ ino_t ;
struct TYPE_6__ {TYPE_1__* s_root; } ;
struct TYPE_4__ {int /*<<< orphan*/  d_op; } ;

/* Variables and functions */
 int /*<<< orphan*/  ENAMETOOLONG ; 
 struct dentry* ERR_CAST (struct inode*) ; 
 struct dentry* ERR_PTR (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_ERR (struct inode*) ; 
 scalar_t__ SYSV_NAMELEN ; 
 int /*<<< orphan*/  d_add (struct dentry*,struct inode*) ; 
 struct inode* sysv_iget (TYPE_3__*,scalar_t__) ; 
 scalar_t__ sysv_inode_by_name (struct dentry*) ; 

__attribute__((used)) static struct dentry *sysv_lookup(struct inode * dir, struct dentry * dentry, struct nameidata *nd)
{
	struct inode * inode = NULL;
	ino_t ino;

	dentry->d_op = dir->i_sb->s_root->d_op;
	if (dentry->d_name.len > SYSV_NAMELEN)
		return ERR_PTR(-ENAMETOOLONG);
	ino = sysv_inode_by_name(dentry);

	if (ino) {
		inode = sysv_iget(dir->i_sb, ino);
		if (IS_ERR(inode))
			return ERR_CAST(inode);
	}
	d_add(dentry, inode);
	return NULL;
}