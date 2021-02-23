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
typedef  int /*<<< orphan*/  phandle_t ;
typedef  int /*<<< orphan*/  driver_t ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/ * BUS_ADD_CHILD (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  OF_finddevice (char*) ; 
 int /*<<< orphan*/ * device_find_child (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  device_printf (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  ofw_bus_node_is_compatible (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static void
tegra124_coretemp_identify(driver_t *driver, device_t parent)
{
	phandle_t root;

	root = OF_finddevice("/");
	if (!ofw_bus_node_is_compatible(root, "nvidia,tegra124"))
		return;
	if (device_find_child(parent, "tegra124_coretemp", -1) != NULL)
		return;
	if (BUS_ADD_CHILD(parent, 0, "tegra124_coretemp", -1) == NULL)
		device_printf(parent, "add child failed\n");
}