#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  bEndpointAddress; } ;
struct usb_host_endpoint {struct ep_device* ep_dev; TYPE_1__ desc; } ;
struct usb_device {int dummy; } ;
struct TYPE_5__ {int /*<<< orphan*/  release; struct device* parent; int /*<<< orphan*/ * type; int /*<<< orphan*/  groups; } ;
struct ep_device {TYPE_2__ dev; struct usb_device* udev; TYPE_1__* desc; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  dev_set_name (TYPE_2__*,char*,int /*<<< orphan*/ ) ; 
 int device_register (TYPE_2__*) ; 
 int /*<<< orphan*/  ep_dev_groups ; 
 int /*<<< orphan*/  ep_device_release ; 
 int /*<<< orphan*/  kfree (struct ep_device*) ; 
 struct ep_device* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_ep_device_type ; 

int usb_create_ep_devs(struct device *parent,
			struct usb_host_endpoint *endpoint,
			struct usb_device *udev)
{
	struct ep_device *ep_dev;
	int retval;

	ep_dev = kzalloc(sizeof(*ep_dev), GFP_KERNEL);
	if (!ep_dev) {
		retval = -ENOMEM;
		goto exit;
	}

	ep_dev->desc = &endpoint->desc;
	ep_dev->udev = udev;
	ep_dev->dev.groups = ep_dev_groups;
	ep_dev->dev.type = &usb_ep_device_type;
	ep_dev->dev.parent = parent;
	ep_dev->dev.release = ep_device_release;
	dev_set_name(&ep_dev->dev, "ep_%02x", endpoint->desc.bEndpointAddress);

	retval = device_register(&ep_dev->dev);
	if (retval)
		goto error_register;

	endpoint->ep_dev = ep_dev;
	return retval;

error_register:
	kfree(ep_dev);
exit:
	return retval;
}