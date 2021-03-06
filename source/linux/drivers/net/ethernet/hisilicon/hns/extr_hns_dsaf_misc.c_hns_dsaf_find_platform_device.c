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
struct platform_device {int dummy; } ;
struct fwnode_handle {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 struct device* bus_find_device_by_fwnode (int /*<<< orphan*/ *,struct fwnode_handle*) ; 
 int /*<<< orphan*/  platform_bus_type ; 
 struct platform_device* to_platform_device (struct device*) ; 

struct
platform_device *hns_dsaf_find_platform_device(struct fwnode_handle *fwnode)
{
	struct device *dev;

	dev = bus_find_device_by_fwnode(&platform_bus_type, fwnode);
	return dev ? to_platform_device(dev) : NULL;
}