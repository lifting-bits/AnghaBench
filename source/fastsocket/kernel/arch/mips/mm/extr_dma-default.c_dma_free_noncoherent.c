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
 int /*<<< orphan*/  DMA_BIDIRECTIONAL ; 
 int /*<<< orphan*/  free_pages (unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_order (size_t) ; 
 int /*<<< orphan*/  plat_unmap_dma_mem (struct device*,int /*<<< orphan*/ ,size_t,int /*<<< orphan*/ ) ; 

void dma_free_noncoherent(struct device *dev, size_t size, void *vaddr,
	dma_addr_t dma_handle)
{
	plat_unmap_dma_mem(dev, dma_handle, size, DMA_BIDIRECTIONAL);
	free_pages((unsigned long) vaddr, get_order(size));
}