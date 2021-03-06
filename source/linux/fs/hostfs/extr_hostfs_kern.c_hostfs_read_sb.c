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
struct file_system_type {int dummy; } ;
struct dentry {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  hostfs_fill_sb_common ; 
 struct dentry* mount_nodev (struct file_system_type*,int,void*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static struct dentry *hostfs_read_sb(struct file_system_type *type,
			  int flags, const char *dev_name,
			  void *data)
{
	return mount_nodev(type, flags, data, hostfs_fill_sb_common);
}