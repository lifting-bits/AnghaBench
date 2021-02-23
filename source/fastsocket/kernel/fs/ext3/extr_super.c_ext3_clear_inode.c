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
struct ext3_block_alloc_info {int dummy; } ;
struct TYPE_2__ {struct ext3_block_alloc_info* i_block_alloc_info; } ;

/* Variables and functions */
 TYPE_1__* EXT3_I (struct inode*) ; 
 int /*<<< orphan*/  ext3_discard_reservation (struct inode*) ; 
 int /*<<< orphan*/  kfree (struct ext3_block_alloc_info*) ; 
 scalar_t__ unlikely (struct ext3_block_alloc_info*) ; 

__attribute__((used)) static void ext3_clear_inode(struct inode *inode)
{
	struct ext3_block_alloc_info *rsv = EXT3_I(inode)->i_block_alloc_info;
	ext3_discard_reservation(inode);
	EXT3_I(inode)->i_block_alloc_info = NULL;
	if (unlikely(rsv))
		kfree(rsv);
}