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
struct inode {struct address_space* i_mapping; } ;
struct address_space {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  EIO ; 
 struct page* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IS_ERR (struct page*) ; 
 int /*<<< orphan*/  PageChecked (struct page*) ; 
 scalar_t__ PageError (struct page*) ; 
 int /*<<< orphan*/  kmap (struct page*) ; 
 struct page* read_mapping_page (struct address_space*,unsigned long,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ufs_check_page (struct page*) ; 
 int /*<<< orphan*/  ufs_put_page (struct page*) ; 

__attribute__((used)) static struct page *ufs_get_page(struct inode *dir, unsigned long n)
{
	struct address_space *mapping = dir->i_mapping;
	struct page *page = read_mapping_page(mapping, n, NULL);
	if (!IS_ERR(page)) {
		kmap(page);
		if (!PageChecked(page))
			ufs_check_page(page);
		if (PageError(page))
			goto fail;
	}
	return page;

fail:
	ufs_put_page(page);
	return ERR_PTR(-EIO);
}