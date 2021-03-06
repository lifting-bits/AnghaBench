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
typedef  int /*<<< orphan*/  u16 ;
struct pci_dev_rh1 {int /*<<< orphan*/  pcie_flags_reg; } ;
struct pci_dev {scalar_t__ rh_reserved1; } ;

/* Variables and functions */

u16 pcie_caps_reg(const struct pci_dev *dev)
{
	return ((struct pci_dev_rh1 *)dev->rh_reserved1)->pcie_flags_reg;
}