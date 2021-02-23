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
typedef  int /*<<< orphan*/  usb_error_t ;
typedef  int uint8_t ;
struct TYPE_4__ {scalar_t__ usb_mode; } ;
struct usb_xfer {int endpointno; TYPE_2__ flags_int; int /*<<< orphan*/  endpoint; TYPE_1__* xroot; } ;
struct avr32dci_softc {int /*<<< orphan*/  sc_bus; } ;
struct TYPE_3__ {int /*<<< orphan*/  bus; } ;

/* Variables and functions */
 struct avr32dci_softc* AVR32_BUS2SC (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AVR32_INT_EPT_INT (int) ; 
 int /*<<< orphan*/  DPRINTFN (int,char*,...) ; 
 int /*<<< orphan*/  MA_OWNED ; 
 int UE_ADDR ; 
 int /*<<< orphan*/  USB_BUS_LOCK_ASSERT (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ USB_MODE_DEVICE ; 
 int /*<<< orphan*/  avr32dci_mod_ien (struct avr32dci_softc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usbd_transfer_done (struct usb_xfer*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
avr32dci_device_done(struct usb_xfer *xfer, usb_error_t error)
{
	struct avr32dci_softc *sc = AVR32_BUS2SC(xfer->xroot->bus);
	uint8_t ep_no;

	USB_BUS_LOCK_ASSERT(&sc->sc_bus, MA_OWNED);

	DPRINTFN(9, "xfer=%p, pipe=%p, error=%d\n",
	    xfer, xfer->endpoint, error);

	if (xfer->flags_int.usb_mode == USB_MODE_DEVICE) {
		ep_no = (xfer->endpointno & UE_ADDR);

		/* disable endpoint interrupt */
		avr32dci_mod_ien(sc, 0, AVR32_INT_EPT_INT(ep_no));

		DPRINTFN(15, "disabled interrupts!\n");
	}
	/* dequeue transfer and start next transfer */
	usbd_transfer_done(xfer, error);
}