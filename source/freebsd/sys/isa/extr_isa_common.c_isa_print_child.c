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
 scalar_t__ bus_print_child_header (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ isa_print_all_resources (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
isa_print_child(device_t bus, device_t dev)
{
	int retval = 0;

	retval += bus_print_child_header(bus, dev);
	retval += isa_print_all_resources(dev);
	retval += bus_print_child_footer(bus, dev);

	return (retval);
}