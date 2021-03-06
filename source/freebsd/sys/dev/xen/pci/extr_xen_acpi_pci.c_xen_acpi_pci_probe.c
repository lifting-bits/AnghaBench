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
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int BUS_PROBE_SPECIFIC ; 
 int ENXIO ; 
 int /*<<< orphan*/ * acpi_get_handle (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  device_set_desc (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  xen_pv_domain () ; 

__attribute__((used)) static int
xen_acpi_pci_probe(device_t dev)
{

	if (!xen_pv_domain())
		return (ENXIO);
	if (acpi_get_handle(dev) == NULL)
		return (ENXIO);

	device_set_desc(dev, "Xen ACPI PCI bus");

	return (BUS_PROBE_SPECIFIC);
}