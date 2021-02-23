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
 int /*<<< orphan*/  consistent_sync (void*,size_t,int) ; 
 void* page_address (struct page*) ; 

void consistent_sync_page(struct page *page, unsigned long offset,
			  size_t size, int direction)
{
	void *start;

	start = page_address(page) + offset;
	consistent_sync(start, size, direction);
}