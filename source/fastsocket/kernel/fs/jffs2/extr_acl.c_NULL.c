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
struct inode {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACL_TYPE_ACCESS ; 
 int EAGAIN ; 
 scalar_t__ IS_ERR (struct posix_acl*) ; 
 int PTR_ERR (struct posix_acl*) ; 
 struct posix_acl* jffs2_get_acl (struct inode*,int /*<<< orphan*/ ) ; 
 int posix_acl_permission (struct inode*,struct posix_acl*,int) ; 
 int /*<<< orphan*/  posix_acl_release (struct posix_acl*) ; 

int jffs2_check_acl(struct inode *inode, int mask)
{
	struct posix_acl *acl;
	int rc;

	acl = jffs2_get_acl(inode, ACL_TYPE_ACCESS);
	if (IS_ERR(acl))
		return PTR_ERR(acl);
	if (acl) {
		rc = posix_acl_permission(inode, acl, mask);
		posix_acl_release(acl);
		return rc;
	}
	return -EAGAIN;
}