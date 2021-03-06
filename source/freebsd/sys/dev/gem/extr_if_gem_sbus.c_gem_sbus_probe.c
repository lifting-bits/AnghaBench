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
 int /*<<< orphan*/ * ofw_bus_get_compat (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * ofw_bus_get_name (int /*<<< orphan*/ ) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ *,char*) ; 

__attribute__((used)) static int
gem_sbus_probe(device_t dev)
{

	if (strcmp(ofw_bus_get_name(dev), "network") == 0 &&
	    ofw_bus_get_compat(dev) != NULL &&
	    strcmp(ofw_bus_get_compat(dev), "SUNW,sbus-gem") == 0) {
		device_set_desc(dev, "Sun GEM Gigabit Ethernet");
		return (0);
	}

	return (ENXIO);
}