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
struct page {int /*<<< orphan*/  index; } ;
struct TYPE_2__ {unsigned long chunkshift; } ;
struct bitmap {scalar_t__ allclean; int /*<<< orphan*/  flags; int /*<<< orphan*/  storage; TYPE_1__ counts; } ;
typedef  unsigned long sector_t ;

/* Variables and functions */
 int /*<<< orphan*/  BITMAP_HOSTENDIAN ; 
 int /*<<< orphan*/  BITMAP_PAGE_NEEDWRITE ; 
 int /*<<< orphan*/  BITMAP_PAGE_PENDING ; 
 int /*<<< orphan*/  KM_USER0 ; 
 int /*<<< orphan*/  clear_bit (unsigned long,void*) ; 
 int /*<<< orphan*/  clear_bit_le (unsigned long,void*) ; 
 unsigned long file_page_offset (int /*<<< orphan*/ *,unsigned long) ; 
 struct page* filemap_get_page (int /*<<< orphan*/ *,unsigned long) ; 
 void* kmap_atomic (struct page*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kunmap_atomic (void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_page_attr (struct bitmap*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  test_page_attr (struct bitmap*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void bitmap_file_clear_bit(struct bitmap *bitmap, sector_t block)
{
	unsigned long bit;
	struct page *page;
	void *paddr;
	unsigned long chunk = block >> bitmap->counts.chunkshift;

	page = filemap_get_page(&bitmap->storage, chunk);
	if (!page)
		return;
	bit = file_page_offset(&bitmap->storage, chunk);
	paddr = kmap_atomic(page, KM_USER0);
	if (test_bit(BITMAP_HOSTENDIAN, &bitmap->flags))
		clear_bit(bit, paddr);
	else
		clear_bit_le(bit, paddr);
	kunmap_atomic(paddr, KM_USER0);
	if (!test_page_attr(bitmap, page->index, BITMAP_PAGE_NEEDWRITE)) {
		set_page_attr(bitmap, page->index, BITMAP_PAGE_PENDING);
		bitmap->allclean = 0;
	}
}