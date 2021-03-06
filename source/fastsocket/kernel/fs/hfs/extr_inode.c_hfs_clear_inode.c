#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct inode {int dummy; } ;
struct TYPE_2__ {struct inode* rsrc_inode; } ;

/* Variables and functions */
 TYPE_1__* HFS_I (struct inode*) ; 
 scalar_t__ HFS_IS_RSRC (struct inode*) ; 
 int /*<<< orphan*/  iput (struct inode*) ; 

void hfs_clear_inode(struct inode *inode)
{
	if (HFS_IS_RSRC(inode) && HFS_I(inode)->rsrc_inode) {
		HFS_I(HFS_I(inode)->rsrc_inode)->rsrc_inode = NULL;
		iput(HFS_I(inode)->rsrc_inode);
	}
}