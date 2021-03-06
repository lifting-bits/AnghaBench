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
struct of_device {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  phandle ;

/* Variables and functions */
 struct device* bus_find_device (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_dev_phandle_match ; 
 int /*<<< orphan*/  of_platform_bus_type ; 
 struct of_device* to_of_device (struct device*) ; 

struct of_device *of_find_device_by_phandle(phandle ph)
{
	struct device *dev;

	dev = bus_find_device(&of_platform_bus_type,
			      NULL, &ph, of_dev_phandle_match);
	if (dev)
		return to_of_device(dev);
	return NULL;
}