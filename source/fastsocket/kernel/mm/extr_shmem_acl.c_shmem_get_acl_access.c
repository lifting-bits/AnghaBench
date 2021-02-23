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
struct inode {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACL_TYPE_ACCESS ; 
 int EINVAL ; 
 int generic_acl_get (struct inode*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,void*,size_t) ; 
 int /*<<< orphan*/  shmem_acl_ops ; 
 scalar_t__ strcmp (char const*,char*) ; 

__attribute__((used)) static int
shmem_get_acl_access(struct inode *inode, const char *name, void *buffer,
		     size_t size)
{
	if (strcmp(name, "") != 0)
		return -EINVAL;
	return generic_acl_get(inode, &shmem_acl_ops, ACL_TYPE_ACCESS, buffer,
			       size);
}