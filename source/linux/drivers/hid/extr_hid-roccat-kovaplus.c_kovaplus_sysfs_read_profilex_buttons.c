#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint ;
struct usb_device {int dummy; } ;
struct kobject {int dummy; } ;
struct file {int dummy; } ;
struct device {int dummy; } ;
struct bin_attribute {scalar_t__ private; } ;
typedef  scalar_t__ ssize_t ;
typedef  int /*<<< orphan*/  loff_t ;
struct TYPE_4__ {TYPE_1__* parent; } ;
struct TYPE_3__ {struct device* parent; } ;

/* Variables and functions */
 int /*<<< orphan*/  KOVAPLUS_COMMAND_PROFILE_BUTTONS ; 
 int /*<<< orphan*/  KOVAPLUS_CONTROL_REQUEST_PROFILE_BUTTONS ; 
 int /*<<< orphan*/  KOVAPLUS_SIZE_PROFILE_BUTTONS ; 
 struct usb_device* interface_to_usbdev (int /*<<< orphan*/ ) ; 
 TYPE_2__* kobj_to_dev (struct kobject*) ; 
 scalar_t__ kovaplus_select_profile (struct usb_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ kovaplus_sysfs_read (struct file*,struct kobject*,char*,int /*<<< orphan*/ ,size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  to_usb_interface (struct device*) ; 

__attribute__((used)) static ssize_t kovaplus_sysfs_read_profilex_buttons(struct file *fp,
		struct kobject *kobj, struct bin_attribute *attr, char *buf,
		loff_t off, size_t count)
{
	struct device *dev = kobj_to_dev(kobj)->parent->parent;
	struct usb_device *usb_dev = interface_to_usbdev(to_usb_interface(dev));
	ssize_t retval;

	retval = kovaplus_select_profile(usb_dev, *(uint *)(attr->private),
			KOVAPLUS_CONTROL_REQUEST_PROFILE_BUTTONS);
	if (retval)
		return retval;

	return kovaplus_sysfs_read(fp, kobj, buf, off, count,
			KOVAPLUS_SIZE_PROFILE_BUTTONS,
			KOVAPLUS_COMMAND_PROFILE_BUTTONS);
}