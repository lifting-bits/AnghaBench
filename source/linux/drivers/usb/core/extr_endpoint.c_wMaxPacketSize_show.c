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
struct ep_device {int /*<<< orphan*/  desc; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 struct ep_device* to_ep_device (struct device*) ; 
 int usb_endpoint_maxp (int /*<<< orphan*/ ) ; 

__attribute__((used)) static ssize_t wMaxPacketSize_show(struct device *dev,
				   struct device_attribute *attr, char *buf)
{
	struct ep_device *ep = to_ep_device(dev);
	return sprintf(buf, "%04x\n", usb_endpoint_maxp(ep->desc));
}