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
struct posix_acl {int dummy; } ;
struct inode {int /*<<< orphan*/  i_mode; } ;
struct generic_acl_operations {int /*<<< orphan*/  (* setacl ) (struct inode*,int /*<<< orphan*/ ,struct posix_acl*) ;struct posix_acl* (* getacl ) (struct inode*,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  ACL_TYPE_ACCESS ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ S_ISLNK (int /*<<< orphan*/ ) ; 
 int posix_acl_chmod_masq (struct posix_acl*,int /*<<< orphan*/ ) ; 
 struct posix_acl* posix_acl_clone (struct posix_acl*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  posix_acl_release (struct posix_acl*) ; 
 struct posix_acl* stub1 (struct inode*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (struct inode*,int /*<<< orphan*/ ,struct posix_acl*) ; 

int
generic_acl_chmod(struct inode *inode, struct generic_acl_operations *ops)
{
	struct posix_acl *acl, *clone;
	int error = 0;

	if (S_ISLNK(inode->i_mode))
		return -EOPNOTSUPP;
	acl = ops->getacl(inode, ACL_TYPE_ACCESS);
	if (acl) {
		clone = posix_acl_clone(acl, GFP_KERNEL);
		posix_acl_release(acl);
		if (!clone)
			return -ENOMEM;
		error = posix_acl_chmod_masq(clone, inode->i_mode);
		if (!error)
			ops->setacl(inode, ACL_TYPE_ACCESS, clone);
		posix_acl_release(clone);
	}
	return error;
}