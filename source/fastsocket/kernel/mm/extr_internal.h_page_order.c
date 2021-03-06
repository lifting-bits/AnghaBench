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
 int /*<<< orphan*/  PageBuddy (struct page*) ; 
 int /*<<< orphan*/  VM_BUG_ON (int) ; 
 unsigned long page_private (struct page*) ; 

__attribute__((used)) static inline unsigned long page_order(struct page *page)
{
	VM_BUG_ON(!PageBuddy(page));
	return page_private(page);
}