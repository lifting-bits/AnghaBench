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
typedef  size_t uint8_t ;
struct usb_xfer {int dummy; } ;
struct usb_page_cache {int dummy; } ;
struct umcs7840_softc {struct ucom_softc* sc_ucom; } ;
struct ucom_softc {int /*<<< orphan*/  sc_portno; } ;

/* Variables and functions */
 int /*<<< orphan*/  DPRINTF (char*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  USB_ERR_CANCELLED ; 
 int USB_GET_STATE (struct usb_xfer*) ; 
#define  USB_ST_SETUP 129 
#define  USB_ST_TRANSFERRED 128 
 int /*<<< orphan*/  ucom_put_data (struct ucom_softc*,struct usb_page_cache*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  usbd_transfer_submit (struct usb_xfer*) ; 
 struct usb_page_cache* usbd_xfer_get_frame (struct usb_xfer*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usbd_xfer_max_len (struct usb_xfer*) ; 
 int /*<<< orphan*/  usbd_xfer_set_frame_len (struct usb_xfer*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usbd_xfer_set_stall (struct usb_xfer*) ; 
 struct umcs7840_softc* usbd_xfer_softc (struct usb_xfer*) ; 
 int /*<<< orphan*/  usbd_xfer_status (struct usb_xfer*,int*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
umcs7840_read_callbackN(struct usb_xfer *xfer, usb_error_t error, uint8_t subunit)
{
	struct umcs7840_softc *sc = usbd_xfer_softc(xfer);
	struct ucom_softc *ucom = &sc->sc_ucom[subunit];
	struct usb_page_cache *pc;
	int actlen;

	usbd_xfer_status(xfer, &actlen, NULL, NULL, NULL);

	DPRINTF("Port %d read, state = %d, data length = %d\n", ucom->sc_portno, USB_GET_STATE(xfer), actlen);

	switch (USB_GET_STATE(xfer)) {
	case USB_ST_TRANSFERRED:
		pc = usbd_xfer_get_frame(xfer, 0);
		ucom_put_data(ucom, pc, 0, actlen);
		/* FALLTHROUGH */
	case USB_ST_SETUP:
tr_setup:
		usbd_xfer_set_frame_len(xfer, 0, usbd_xfer_max_len(xfer));
		usbd_transfer_submit(xfer);
		return;

	default:			/* Error */
		if (error != USB_ERR_CANCELLED) {
			/* try to clear stall first */
			usbd_xfer_set_stall(xfer);
			goto tr_setup;
		}
		return;
	}
}