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
typedef  int /*<<< orphan*/  usb_error_t ;
struct usb_xfer {int dummy; } ;
struct usb_page_cache {int dummy; } ;
struct usb_ether {int dummy; } ;
struct axe_softc {struct usb_ether sc_ue; } ;

/* Variables and functions */
 int /*<<< orphan*/  DPRINTF (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  USB_ERR_CANCELLED ; 
 int USB_GET_STATE (struct usb_xfer*) ; 
#define  USB_ST_SETUP 129 
#define  USB_ST_TRANSFERRED 128 
 int /*<<< orphan*/  axe_rx_frame (struct usb_ether*,struct usb_page_cache*,int) ; 
 int /*<<< orphan*/  uether_rxflush (struct usb_ether*) ; 
 int /*<<< orphan*/  usbd_errstr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usbd_transfer_submit (struct usb_xfer*) ; 
 struct usb_page_cache* usbd_xfer_get_frame (struct usb_xfer*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usbd_xfer_max_len (struct usb_xfer*) ; 
 int /*<<< orphan*/  usbd_xfer_set_frame_len (struct usb_xfer*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usbd_xfer_set_stall (struct usb_xfer*) ; 
 struct axe_softc* usbd_xfer_softc (struct usb_xfer*) ; 
 int /*<<< orphan*/  usbd_xfer_status (struct usb_xfer*,int*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
axe_bulk_read_callback(struct usb_xfer *xfer, usb_error_t error)
{
	struct axe_softc *sc = usbd_xfer_softc(xfer);
	struct usb_ether *ue = &sc->sc_ue;
	struct usb_page_cache *pc;
	int actlen;

	usbd_xfer_status(xfer, &actlen, NULL, NULL, NULL);

	switch (USB_GET_STATE(xfer)) {
	case USB_ST_TRANSFERRED:
		pc = usbd_xfer_get_frame(xfer, 0);
		axe_rx_frame(ue, pc, actlen);

		/* FALLTHROUGH */
	case USB_ST_SETUP:
tr_setup:
		usbd_xfer_set_frame_len(xfer, 0, usbd_xfer_max_len(xfer));
		usbd_transfer_submit(xfer);
		uether_rxflush(ue);
		return;

	default:			/* Error */
		DPRINTF("bulk read error, %s\n", usbd_errstr(error));

		if (error != USB_ERR_CANCELLED) {
			/* try to clear stall first */
			usbd_xfer_set_stall(xfer);
			goto tr_setup;
		}
		return;

	}
}