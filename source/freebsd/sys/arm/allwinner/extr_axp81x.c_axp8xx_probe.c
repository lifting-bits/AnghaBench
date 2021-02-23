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
typedef  int /*<<< orphan*/  device_t ;
struct TYPE_2__ {int ocd_data; } ;

/* Variables and functions */
#define  AXP803 129 
#define  AXP813 128 
 int BUS_PROBE_DEFAULT ; 
 int ENXIO ; 
 int /*<<< orphan*/  compat_data ; 
 int /*<<< orphan*/  device_set_desc (int /*<<< orphan*/ ,char*) ; 
 TYPE_1__* ofw_bus_search_compatible (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ofw_bus_status_okay (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
axp8xx_probe(device_t dev)
{
	if (!ofw_bus_status_okay(dev))
		return (ENXIO);

	switch (ofw_bus_search_compatible(dev, compat_data)->ocd_data)
	{
	case AXP803:
		device_set_desc(dev, "X-Powers AXP803 Power Management Unit");
		break;
	case AXP813:
		device_set_desc(dev, "X-Powers AXP813 Power Management Unit");
		break;
	default:
		return (ENXIO);
	}

	return (BUS_PROBE_DEFAULT);
}