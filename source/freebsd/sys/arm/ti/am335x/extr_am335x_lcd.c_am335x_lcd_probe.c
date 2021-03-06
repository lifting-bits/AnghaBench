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
 int SC_AUTODETECT_KBD ; 
 int device_get_flags (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  device_get_unit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  device_set_desc (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  ofw_bus_is_compatible (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  ofw_bus_status_okay (int /*<<< orphan*/ ) ; 
 int sc_probe_unit (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int
am335x_lcd_probe(device_t dev)
{
#ifdef DEV_SC
	int err;
#endif

	if (!ofw_bus_status_okay(dev))
		return (ENXIO);

	if (!ofw_bus_is_compatible(dev, "ti,am33xx-tilcdc"))
		return (ENXIO);

	device_set_desc(dev, "AM335x LCD controller");

#ifdef DEV_SC
	err = sc_probe_unit(device_get_unit(dev), 
	    device_get_flags(dev) | SC_AUTODETECT_KBD);
	if (err != 0)
		return (err);
#endif

	return (BUS_PROBE_DEFAULT);
}