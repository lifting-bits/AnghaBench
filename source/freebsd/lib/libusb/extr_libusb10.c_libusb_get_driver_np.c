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
struct libusb20_device {int dummy; } ;

/* Variables and functions */
 int libusb_get_driver (struct libusb20_device*,int,char*,int) ; 

int
libusb_get_driver_np(struct libusb20_device *pdev, int interface,
    char *name, int namelen)
{
	return (libusb_get_driver(pdev, interface, name, namelen));
}