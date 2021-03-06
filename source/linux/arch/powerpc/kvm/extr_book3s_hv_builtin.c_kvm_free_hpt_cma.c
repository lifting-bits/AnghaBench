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
 int /*<<< orphan*/  cma_release (int /*<<< orphan*/ ,struct page*,unsigned long) ; 
 int /*<<< orphan*/  kvm_cma ; 

void kvm_free_hpt_cma(struct page *page, unsigned long nr_pages)
{
	cma_release(kvm_cma, page, nr_pages);
}