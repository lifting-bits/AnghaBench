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
typedef  int /*<<< orphan*/  u8 ;
struct vnic_dev_ring {int base_addr_unaligned; int base_addr; scalar_t__ desc_count; scalar_t__ desc_avail; scalar_t__ descs_unaligned; int /*<<< orphan*/ * descs; int /*<<< orphan*/  base_align; scalar_t__ size; int /*<<< orphan*/  size_unaligned; } ;
struct vnic_dev {int /*<<< orphan*/  pdev; } ;

/* Variables and functions */
 int ALIGN (int,int /*<<< orphan*/ ) ; 
 int ENOMEM ; 
 scalar_t__ pci_alloc_consistent (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  vdev_err (struct vnic_dev*,char*,int) ; 
 int /*<<< orphan*/  vnic_dev_clear_desc_ring (struct vnic_dev_ring*) ; 
 int /*<<< orphan*/  vnic_dev_desc_ring_size (struct vnic_dev_ring*,unsigned int,unsigned int) ; 

int vnic_dev_alloc_desc_ring(struct vnic_dev *vdev, struct vnic_dev_ring *ring,
	unsigned int desc_count, unsigned int desc_size)
{
	vnic_dev_desc_ring_size(ring, desc_count, desc_size);

	ring->descs_unaligned = pci_alloc_consistent(vdev->pdev,
		ring->size_unaligned,
		&ring->base_addr_unaligned);

	if (!ring->descs_unaligned) {
		vdev_err(vdev, "Failed to allocate ring (size=%d), aborting\n",
			 (int)ring->size);
		return -ENOMEM;
	}

	ring->base_addr = ALIGN(ring->base_addr_unaligned,
		ring->base_align);
	ring->descs = (u8 *)ring->descs_unaligned +
		(ring->base_addr - ring->base_addr_unaligned);

	vnic_dev_clear_desc_ring(ring);

	ring->desc_avail = ring->desc_count - 1;

	return 0;
}