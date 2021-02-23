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
struct mtk_usb_phy_softc {int /*<<< orphan*/  socid; } ;
typedef  int /*<<< orphan*/  device_t ;
struct TYPE_2__ {int /*<<< orphan*/  ocd_data; } ;

/* Variables and functions */
 int ENXIO ; 
 int /*<<< orphan*/  MTK_SOC_UNKNOWN ; 
 int /*<<< orphan*/  compat_data ; 
 struct mtk_usb_phy_softc* device_get_softc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  device_set_desc (int /*<<< orphan*/ ,char*) ; 
 TYPE_1__* ofw_bus_search_compatible (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ofw_bus_status_okay (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
mtk_usb_phy_probe(device_t dev)
{
	struct mtk_usb_phy_softc *sc = device_get_softc(dev);

	if (!ofw_bus_status_okay(dev))
		return (ENXIO);
	if ((sc->socid =
	    ofw_bus_search_compatible(dev, compat_data)->ocd_data) ==
	    MTK_SOC_UNKNOWN)
		return (ENXIO);

	device_set_desc(dev, "MTK USB PHY");

	return (0);
}