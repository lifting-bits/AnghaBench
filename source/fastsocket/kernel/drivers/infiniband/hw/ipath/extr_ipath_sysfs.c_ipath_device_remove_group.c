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
struct ipath_devdata {int ipath_flags; } ;
struct device {int /*<<< orphan*/  kobj; } ;

/* Variables and functions */
 int IPATH_HAS_MULT_IB_SPEED ; 
 int /*<<< orphan*/  dev_attr_group ; 
 int /*<<< orphan*/  dev_attr_jint_idle_ticks ; 
 int /*<<< orphan*/  dev_attr_jint_max_packets ; 
 int /*<<< orphan*/  dev_attr_reset ; 
 int /*<<< orphan*/  dev_counter_attr_group ; 
 int /*<<< orphan*/  dev_ibcfg_attr_group ; 
 int /*<<< orphan*/  device_remove_file (struct device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

void ipath_device_remove_group(struct device *dev, struct ipath_devdata *dd)
{
	sysfs_remove_group(&dev->kobj, &dev_counter_attr_group);

	if (dd->ipath_flags & IPATH_HAS_MULT_IB_SPEED) {
		sysfs_remove_group(&dev->kobj, &dev_ibcfg_attr_group);
		device_remove_file(dev, &dev_attr_jint_idle_ticks);
		device_remove_file(dev, &dev_attr_jint_max_packets);
	}

	sysfs_remove_group(&dev->kobj, &dev_attr_group);

	device_remove_file(dev, &dev_attr_reset);
}