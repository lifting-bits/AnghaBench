#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  name; } ;
struct usb_line6_variax {TYPE_1__ model_data; int /*<<< orphan*/  dumpreq; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  get_string (char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  line6_wait_dump (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  to_usb_interface (struct device*) ; 
 struct usb_line6_variax* usb_get_intfdata (int /*<<< orphan*/ ) ; 

__attribute__((used)) static ssize_t variax_get_name(struct device *dev,
			       struct device_attribute *attr, char *buf)
{
	struct usb_line6_variax *variax = usb_get_intfdata(to_usb_interface(dev));
	line6_wait_dump(&variax->dumpreq, 0);
	return get_string(buf, variax->model_data.name,
			  sizeof(variax->model_data.name));
}