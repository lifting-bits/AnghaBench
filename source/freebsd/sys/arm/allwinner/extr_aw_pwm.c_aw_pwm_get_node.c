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
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  ofw_bus_get_node (int /*<<< orphan*/ ) ; 

__attribute__((used)) static phandle_t
aw_pwm_get_node(device_t bus, device_t dev)
{

	/*
	 * Share our controller node with our pwmbus child; it instantiates
	 * devices by walking the children contained within our node.
	 */
	return ofw_bus_get_node(bus);
}