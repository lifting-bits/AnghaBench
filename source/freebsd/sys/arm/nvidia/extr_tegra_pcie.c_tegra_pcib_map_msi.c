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
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  phandle_t ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  OF_xref_from_node (int /*<<< orphan*/ ) ; 
 int intr_map_msi (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ofw_bus_get_node (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
tegra_pcib_map_msi(device_t pci, device_t child, int irq, uint64_t *addr,
    uint32_t *data)
{
	phandle_t msi_parent;

	/* XXXX ofw_bus_msimap() don't works for Tegra DT.
	ofw_bus_msimap(ofw_bus_get_node(pci), pci_get_rid(child), &msi_parent,
	    NULL);
	*/
	msi_parent = OF_xref_from_node(ofw_bus_get_node(pci));
	return (intr_map_msi(pci, child, msi_parent, irq, addr, data));
}