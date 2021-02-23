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
struct resource_list {int dummy; } ;
struct bhnd_usb_devinfo {struct resource_list sdi_rl; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 scalar_t__ STAILQ_FIRST (struct resource_list*) ; 
 int /*<<< orphan*/  SYS_RES_IRQ ; 
 int /*<<< orphan*/  SYS_RES_MEMORY ; 
 struct bhnd_usb_devinfo* device_get_ivars (int /*<<< orphan*/ ) ; 
 scalar_t__ printf (char*) ; 
 scalar_t__ resource_list_print_type (struct resource_list*,char*,int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static int
bhnd_usb_print_all_resources(device_t dev)
{
	struct bhnd_usb_devinfo	*sdi;
	struct resource_list	*rl;
	int			 retval;

	retval = 0;
	sdi = device_get_ivars(dev);
	rl = &sdi->sdi_rl;

	if (STAILQ_FIRST(rl))
		retval += printf(" at");

	retval += resource_list_print_type(rl, "mem", SYS_RES_MEMORY, "%jx");
	retval += resource_list_print_type(rl, "irq", SYS_RES_IRQ, "%ld");

	return (retval);
}