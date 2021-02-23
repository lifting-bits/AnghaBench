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
struct page {int dummy; } ;
struct inode {int dummy; } ;
struct buffer_head {int /*<<< orphan*/  b_blocknr; int /*<<< orphan*/  b_bdev; struct page* b_page; } ;
typedef  int /*<<< orphan*/  sector_t ;
typedef  int /*<<< orphan*/  handle_t ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  EXT4_GET_BLOCKS_CREATE ; 
 scalar_t__ PageUptodate (struct page*) ; 
 scalar_t__ buffer_new (struct buffer_head*) ; 
 int /*<<< orphan*/  clear_buffer_new (struct buffer_head*) ; 
 int ext4_get_blocks (int /*<<< orphan*/ *,struct inode*,int /*<<< orphan*/ ,int,struct buffer_head*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * ext4_journal_current_handle () ; 
 int ext4_journal_get_write_access (int /*<<< orphan*/ *,struct buffer_head*) ; 
 int jbd2_journal_dirty_metadata (int /*<<< orphan*/ *,struct buffer_head*) ; 
 int /*<<< orphan*/  set_buffer_uptodate (struct buffer_head*) ; 
 int /*<<< orphan*/  unmap_underlying_metadata (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ext4_journalled_get_block(struct inode *inode, sector_t iblock,
				     struct buffer_head *bh, int create)
{
	handle_t *handle = ext4_journal_current_handle();
	int ret;

	/* This function should ever be used only for real buffers */
	BUG_ON(!bh->b_page);

	ret = ext4_get_blocks(handle, inode, iblock, 1, bh,
			      create ? EXT4_GET_BLOCKS_CREATE : 0);
	if (ret > 0) {
		if (buffer_new(bh)) {
			struct page *page = bh->b_page;

			/*
			 * This is a terrible hack to avoid block_prepare_write
			 * marking our buffer as dirty
			 */
			if (PageUptodate(page)) {
				ret = ext4_journal_get_write_access(handle, bh);
				if (ret < 0)
					return ret;
				unmap_underlying_metadata(bh->b_bdev,
							  bh->b_blocknr);
				clear_buffer_new(bh);
				set_buffer_uptodate(bh);
				ret = jbd2_journal_dirty_metadata(handle, bh);
				if (ret < 0)
					return ret;
			}
		}
		ret = 0;
	}
	return ret;
}