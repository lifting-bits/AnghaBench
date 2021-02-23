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
 scalar_t__ bus_print_child_footer (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int bus_print_child_header (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  device_get_ivars (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ofw_bus_status_okay (int /*<<< orphan*/ ) ; 
 scalar_t__ printf (char*) ; 
 scalar_t__ simplebus_print_res (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
simplebus_print_child(device_t bus, device_t child)
{
	int rv;

	rv = bus_print_child_header(bus, child);
	rv += simplebus_print_res(device_get_ivars(child));
	if (!ofw_bus_status_okay(child))
		rv += printf(" disabled");
	rv += bus_print_child_footer(bus, child);
	return (rv);
}