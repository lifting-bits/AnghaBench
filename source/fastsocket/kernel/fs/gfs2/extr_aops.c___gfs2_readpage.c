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
struct page {TYPE_1__* mapping; } ;
struct gfs2_sbd {int /*<<< orphan*/  sd_flags; } ;
struct gfs2_inode {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  host; } ;

/* Variables and functions */
 int EIO ; 
 struct gfs2_inode* GFS2_I (int /*<<< orphan*/ ) ; 
 struct gfs2_sbd* GFS2_SB (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SDF_SHUTDOWN ; 
 int /*<<< orphan*/  gfs2_block_map ; 
 scalar_t__ gfs2_is_stuffed (struct gfs2_inode*) ; 
 int mpage_readpage (struct page*,int /*<<< orphan*/ ) ; 
 int stuffed_readpage (struct gfs2_inode*,struct page*) ; 
 int /*<<< orphan*/  test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ unlikely (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  unlock_page (struct page*) ; 

__attribute__((used)) static int __gfs2_readpage(void *file, struct page *page)
{
	struct gfs2_inode *ip = GFS2_I(page->mapping->host);
	struct gfs2_sbd *sdp = GFS2_SB(page->mapping->host);
	int error;

	if (gfs2_is_stuffed(ip)) {
		error = stuffed_readpage(ip, page);
		unlock_page(page);
	} else {
		error = mpage_readpage(page, gfs2_block_map);
	}

	if (unlikely(test_bit(SDF_SHUTDOWN, &sdp->sd_flags)))
		return -EIO;

	return error;
}