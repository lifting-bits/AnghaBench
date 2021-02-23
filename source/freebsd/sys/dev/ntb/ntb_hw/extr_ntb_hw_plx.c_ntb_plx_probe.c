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
 int BUS_PROBE_DEFAULT ; 
 int ENXIO ; 
 int /*<<< orphan*/  device_set_desc (int /*<<< orphan*/ ,char*) ; 
 int pci_get_devid (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
ntb_plx_probe(device_t dev)
{

	switch (pci_get_devid(dev)) {
	case 0x87a010b5:
		device_set_desc(dev, "PLX Non-Transparent Bridge NT0 Link");
		return (BUS_PROBE_DEFAULT);
	case 0x87a110b5:
		device_set_desc(dev, "PLX Non-Transparent Bridge NT1 Link");
		return (BUS_PROBE_DEFAULT);
	case 0x87b010b5:
		device_set_desc(dev, "PLX Non-Transparent Bridge NT0 Virtual");
		return (BUS_PROBE_DEFAULT);
	case 0x87b110b5:
		device_set_desc(dev, "PLX Non-Transparent Bridge NT1 Virtual");
		return (BUS_PROBE_DEFAULT);
	}
	return (ENXIO);
}