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
 scalar_t__ forbidden_pages_map ; 
 int /*<<< orphan*/  memory_bm_clear_bit (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  page_to_pfn (struct page*) ; 

__attribute__((used)) static void swsusp_unset_page_forbidden(struct page *page)
{
	if (forbidden_pages_map)
		memory_bm_clear_bit(forbidden_pages_map, page_to_pfn(page));
}