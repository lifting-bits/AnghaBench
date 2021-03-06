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
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 int /*<<< orphan*/  CONFIG_ARCH_HAS_UNCACHED_SEGMENT ; 
 int /*<<< orphan*/  IS_ENABLED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  arch_dma_free (struct device*,size_t,void*,int /*<<< orphan*/ ,unsigned long) ; 
 scalar_t__ dma_alloc_need_uncached (struct device*,unsigned long) ; 
 int /*<<< orphan*/  dma_direct_free_pages (struct device*,size_t,void*,int /*<<< orphan*/ ,unsigned long) ; 

void dma_direct_free(struct device *dev, size_t size,
		void *cpu_addr, dma_addr_t dma_addr, unsigned long attrs)
{
	if (!IS_ENABLED(CONFIG_ARCH_HAS_UNCACHED_SEGMENT) &&
	    dma_alloc_need_uncached(dev, attrs))
		arch_dma_free(dev, size, cpu_addr, dma_addr, attrs);
	else
		dma_direct_free_pages(dev, size, cpu_addr, dma_addr, attrs);
}