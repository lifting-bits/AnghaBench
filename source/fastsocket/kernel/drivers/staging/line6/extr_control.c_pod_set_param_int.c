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
struct usb_line6_pod {int dummy; } ;
struct usb_interface {int dummy; } ;
struct device {int dummy; } ;
typedef  size_t ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  pod_transmit_parameter (struct usb_line6_pod*,int,int) ; 
 int simple_strtoul (char const*,int /*<<< orphan*/ *,int) ; 
 struct usb_interface* to_usb_interface (struct device*) ; 
 struct usb_line6_pod* usb_get_intfdata (struct usb_interface*) ; 

__attribute__((used)) static ssize_t pod_set_param_int(struct device *dev, const char *buf, size_t count, int param)
{
	struct usb_interface *interface = to_usb_interface(dev);
	struct usb_line6_pod *pod = usb_get_intfdata(interface);
	int value = simple_strtoul(buf, NULL, 10);
	pod_transmit_parameter(pod, param, value);
	return count;
}