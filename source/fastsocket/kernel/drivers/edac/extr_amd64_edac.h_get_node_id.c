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
typedef  scalar_t__ u8 ;
struct pci_dev {int /*<<< orphan*/  devfn; } ;

/* Variables and functions */
 scalar_t__ PCI_SLOT (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline u8 get_node_id(struct pci_dev *pdev)
{
	return PCI_SLOT(pdev->devfn) - 0x18;
}