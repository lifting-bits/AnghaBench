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
typedef  scalar_t__ uint8_t ;
typedef  int /*<<< orphan*/  uint16_t ;
struct uslcom_softc {int /*<<< orphan*/  sc_ucom; int /*<<< orphan*/  sc_udev; int /*<<< orphan*/  sc_iface_no; } ;
struct usb_device_request {int /*<<< orphan*/  wLength; int /*<<< orphan*/  wIndex; int /*<<< orphan*/  wValue; int /*<<< orphan*/  bRequest; int /*<<< orphan*/  bmRequestType; } ;
struct ucom_softc {struct uslcom_softc* sc_parent; } ;

/* Variables and functions */
 int /*<<< orphan*/  DPRINTF (char*,...) ; 
 int /*<<< orphan*/  USETW (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  USLCOM_MHS_RTS_ON ; 
 int /*<<< orphan*/  USLCOM_MHS_RTS_SET ; 
 int /*<<< orphan*/  USLCOM_SET_MHS ; 
 int /*<<< orphan*/  USLCOM_WRITE ; 
 scalar_t__ ucom_cfg_do_request (int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct usb_device_request*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void
uslcom_cfg_set_rts(struct ucom_softc *ucom, uint8_t onoff)
{
	struct uslcom_softc *sc = ucom->sc_parent;
	struct usb_device_request req;
	uint16_t ctl;

	DPRINTF("onoff = %d\n", onoff);

	ctl = onoff ? USLCOM_MHS_RTS_ON : 0;
	ctl |= USLCOM_MHS_RTS_SET;

	req.bmRequestType = USLCOM_WRITE;
	req.bRequest = USLCOM_SET_MHS;
	USETW(req.wValue, ctl);
	USETW(req.wIndex, sc->sc_iface_no);
	USETW(req.wLength, 0);

	if (ucom_cfg_do_request(sc->sc_udev, &sc->sc_ucom,
	    &req, NULL, 0, 1000)) {
		DPRINTF("Setting DTR failed (ignored)\n");
	}
}