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
typedef  int uint8_t ;
typedef  int /*<<< orphan*/  uint32_t ;
struct uvisor_softc {int /*<<< orphan*/  sc_ucom; } ;
struct usb_xfer {int dummy; } ;
struct usb_page_cache {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  USB_ERR_CANCELLED ; 
 int USB_GET_STATE (struct usb_xfer*) ; 
#define  USB_ST_SETUP 129 
#define  USB_ST_TRANSFERRED 128 
 int UVISOROBUFSIZE ; 
 int UVISOROFRAMES ; 
 int /*<<< orphan*/  ucom_get_data (int /*<<< orphan*/ *,struct usb_page_cache*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  usbd_transfer_submit (struct usb_xfer*) ; 
 struct usb_page_cache* usbd_xfer_get_frame (struct usb_xfer*,int) ; 
 int /*<<< orphan*/  usbd_xfer_set_frame_len (struct usb_xfer*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usbd_xfer_set_frame_offset (struct usb_xfer*,int,int) ; 
 int /*<<< orphan*/  usbd_xfer_set_frames (struct usb_xfer*,int) ; 
 int /*<<< orphan*/  usbd_xfer_set_stall (struct usb_xfer*) ; 
 struct uvisor_softc* usbd_xfer_softc (struct usb_xfer*) ; 

__attribute__((used)) static void
uvisor_write_callback(struct usb_xfer *xfer, usb_error_t error)
{
	struct uvisor_softc *sc = usbd_xfer_softc(xfer);
	struct usb_page_cache *pc;
	uint32_t actlen;
	uint8_t x;

	switch (USB_GET_STATE(xfer)) {
	case USB_ST_SETUP:
	case USB_ST_TRANSFERRED:
tr_setup:
		for (x = 0; x != UVISOROFRAMES; x++) {

			usbd_xfer_set_frame_offset(xfer, 
			    x * UVISOROBUFSIZE, x);

			pc = usbd_xfer_get_frame(xfer, x);
			if (ucom_get_data(&sc->sc_ucom, pc, 0,
			    UVISOROBUFSIZE, &actlen)) {
				usbd_xfer_set_frame_len(xfer, x, actlen);
			} else {
				break;
			}
		}
		/* check for data */
		if (x != 0) {
			usbd_xfer_set_frames(xfer, x);
			usbd_transfer_submit(xfer);
		}
		break;

	default:			/* Error */
		if (error != USB_ERR_CANCELLED) {
			/* try to clear stall first */
			usbd_xfer_set_stall(xfer);
			goto tr_setup;
		}
		break;
	}
}