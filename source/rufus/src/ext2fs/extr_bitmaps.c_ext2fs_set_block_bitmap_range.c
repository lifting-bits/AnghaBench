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
typedef  int /*<<< orphan*/  ext2fs_block_bitmap ;
typedef  int /*<<< orphan*/  errcode_t ;
typedef  int /*<<< orphan*/  blk_t ;

/* Variables and functions */
 int /*<<< orphan*/  EXT2_ET_MAGIC_BLOCK_BITMAP ; 
 int /*<<< orphan*/  ext2fs_set_generic_bitmap_range (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,void*) ; 

errcode_t ext2fs_set_block_bitmap_range(ext2fs_block_bitmap bmap,
					blk_t start, unsigned int num,
					void *in)
{
	return (ext2fs_set_generic_bitmap_range(bmap,
						EXT2_ET_MAGIC_BLOCK_BITMAP,
						start, num, in));
}