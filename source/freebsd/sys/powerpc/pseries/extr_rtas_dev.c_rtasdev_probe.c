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
 char* ofw_bus_get_name (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtas_exists () ; 
 scalar_t__ strcmp (char const*,char*) ; 

__attribute__((used)) static int
rtasdev_probe(device_t dev)
{
	const char *name = ofw_bus_get_name(dev);

	if (strcmp(name, "rtas") != 0)
		return (ENXIO);
	if (!rtas_exists())
		return (ENXIO);

	device_set_desc(dev, "Run-Time Abstraction Services");
	return (0);
}