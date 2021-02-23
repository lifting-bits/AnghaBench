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
typedef  int /*<<< orphan*/  u_int ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  device_add_child_ordered (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*,int) ; 

device_t
bus_generic_add_child(device_t dev, u_int order, const char *name, int unit)
{

	return (device_add_child_ordered(dev, order, name, unit));
}