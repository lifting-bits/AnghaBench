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
struct address_space {int dummy; } ;
typedef  unsigned int loff_t ;

/* Variables and functions */
 int block_write_begin (int /*<<< orphan*/ *,struct address_space*,unsigned int,unsigned int,int /*<<< orphan*/ ,struct page**,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nilfs_get_block ; 
 unsigned int page_offset (struct page*) ; 

__attribute__((used)) static int nilfs_prepare_chunk(struct page *page,
			       struct address_space *mapping,
			       unsigned from, unsigned to)
{
	loff_t pos = page_offset(page) + from;
	return block_write_begin(NULL, mapping, pos, to - from, 0, &page,
				 NULL, nilfs_get_block);
}