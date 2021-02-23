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
struct usb_xfer {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  dwc_otg_setup_standard_chain (struct usb_xfer*) ; 
 int /*<<< orphan*/  dwc_otg_start_standard_chain (struct usb_xfer*) ; 

__attribute__((used)) static void
dwc_otg_device_non_isoc_start(struct usb_xfer *xfer)
{
	/* setup TDs */
	dwc_otg_setup_standard_chain(xfer);
	dwc_otg_start_standard_chain(xfer);
}