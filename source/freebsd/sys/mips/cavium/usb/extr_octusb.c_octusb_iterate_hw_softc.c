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
typedef  int /*<<< orphan*/  usb_bus_mem_sub_cb_t ;
struct usb_bus {int dummy; } ;

/* Variables and functions */

void
octusb_iterate_hw_softc(struct usb_bus *bus, usb_bus_mem_sub_cb_t *cb)
{

}