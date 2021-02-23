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
typedef  int /*<<< orphan*/  gfp_t ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 void* __dma_alloc (struct device*,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ arch_is_coherent () ; 
 scalar_t__ dma_alloc_from_coherent (struct device*,size_t,int /*<<< orphan*/ *,void**) ; 
 void* kmalloc (size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pgprot_kernel ; 
 int /*<<< orphan*/  pgprot_noncached (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  virt_to_dma (struct device*,void*) ; 

void *
dma_alloc_coherent(struct device *dev, size_t size, dma_addr_t *handle, gfp_t gfp)
{
	void *memory;

	if (dma_alloc_from_coherent(dev, size, handle, &memory))
		return memory;

	if (arch_is_coherent()) {
		void *virt;

		virt = kmalloc(size, gfp);
		if (!virt)
			return NULL;
		*handle =  virt_to_dma(dev, virt);

		return virt;
	}

	return __dma_alloc(dev, size, handle, gfp,
			   pgprot_noncached(pgprot_kernel));
}