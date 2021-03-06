#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u64 ;
struct TYPE_2__ {int /*<<< orphan*/  coherent_dma_mask; } ;
struct pci_dev {int /*<<< orphan*/  dma_mask; TYPE_1__ dev; } ;

/* Variables and functions */
 int dma_set_mask (TYPE_1__*,int /*<<< orphan*/ ) ; 

int pci_set_consistent_dma_mask(struct pci_dev *dev, u64 mask)
{
	int rc;

	rc = dma_set_mask(&dev->dev, mask);
	dev->dev.coherent_dma_mask = dev->dma_mask;

	return rc;
}