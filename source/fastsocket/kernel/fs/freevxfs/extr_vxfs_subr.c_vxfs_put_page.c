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

/* Variables and functions */
 int /*<<< orphan*/  kunmap (struct page*) ; 
 int /*<<< orphan*/  page_cache_release (struct page*) ; 

inline void
vxfs_put_page(struct page *pp)
{
	kunmap(pp);
	page_cache_release(pp);
}