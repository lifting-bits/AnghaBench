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
 int /*<<< orphan*/  OF_prop_free (char*) ; 
 int /*<<< orphan*/  ofw_bus_get_node (int /*<<< orphan*/ ) ; 
 scalar_t__ strcmp (char*,char const*) ; 
 int strlen (char*) ; 
 int ti_get_hwmods_prop (int /*<<< orphan*/ ,void**) ; 

int ti_hwmods_contains(device_t dev, const char *hwmod)
{
	phandle_t node;
	int len, l;
	char *name;
	char *buf;
	int result;

	if ((node = ofw_bus_get_node(dev)) == 0)
		return (0);

	if ((len = ti_get_hwmods_prop(node, (void **)&name)) <= 0)
		return (0);

	buf = name;

	result = 0;
	while (len > 0) {
		if (strcmp(name, hwmod) == 0) {
			result = 1;
			break;
		}

		/* Slide to the next sub-string. */
		l = strlen(name) + 1;
		name += l;
		len -= l;
	}

	OF_prop_free(buf);

	return (result);
}