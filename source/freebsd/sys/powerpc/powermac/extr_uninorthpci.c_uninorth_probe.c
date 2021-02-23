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
 int ENXIO ; 
 int /*<<< orphan*/  device_set_desc (int /*<<< orphan*/ ,char*) ; 
 char* ofw_bus_get_compat (int /*<<< orphan*/ ) ; 
 char* ofw_bus_get_type (int /*<<< orphan*/ ) ; 
 scalar_t__ strcmp (char const*,char*) ; 

__attribute__((used)) static int
uninorth_probe(device_t dev)
{
	const char	*type, *compatible;

	type = ofw_bus_get_type(dev);
	compatible = ofw_bus_get_compat(dev);

	if (type == NULL || compatible == NULL)
		return (ENXIO);

	if (strcmp(type, "pci") != 0)
		return (ENXIO);

	if (strcmp(compatible, "uni-north") == 0) {
		device_set_desc(dev, "Apple UniNorth Host-PCI bridge");
		return (0);
	} else if (strcmp(compatible, "u3-agp") == 0) {
		device_set_desc(dev, "Apple U3 Host-AGP bridge");
		return (0);
	} else if (strcmp(compatible, "u4-pcie") == 0) {
		device_set_desc(dev, "IBM CPC945 PCI Express Root");
		return (0);
	}
	
	return (ENXIO);
}