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
struct sg_table {int dummy; } ;
struct page {int dummy; } ;

/* Variables and functions */
 int ENOMEM ; 
 struct sg_table* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned int PAGE_SHIFT ; 
 int /*<<< orphan*/  kfree (struct sg_table*) ; 
 struct sg_table* kmalloc (int,int /*<<< orphan*/ ) ; 
 int sg_alloc_table_from_pages (struct sg_table*,struct page**,unsigned int,int /*<<< orphan*/ ,unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static struct sg_table *
dmabuf_pages_to_sgt(struct page **pages, unsigned int nr_pages)
{
	struct sg_table *sgt;
	int ret;

	sgt = kmalloc(sizeof(*sgt), GFP_KERNEL);
	if (!sgt) {
		ret = -ENOMEM;
		goto out;
	}

	ret = sg_alloc_table_from_pages(sgt, pages, nr_pages, 0,
					nr_pages << PAGE_SHIFT,
					GFP_KERNEL);
	if (ret)
		goto out;

	return sgt;

out:
	kfree(sgt);
	return ERR_PTR(ret);
}