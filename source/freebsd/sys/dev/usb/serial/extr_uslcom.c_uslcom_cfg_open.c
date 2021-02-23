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
struct uslcom_softc {int /*<<< orphan*/  sc_ucom; int /*<<< orphan*/  sc_udev; int /*<<< orphan*/  sc_iface_no; } ;
struct usb_device_request {int /*<<< orphan*/  wLength; int /*<<< orphan*/  wIndex; int /*<<< orphan*/  wValue; int /*<<< orphan*/  bRequest; int /*<<< orphan*/  bmRequestType; } ;
struct ucom_softc {struct uslcom_softc* sc_parent; } ;

/* Variables and functions */
 int /*<<< orphan*/  DPRINTF (char*) ; 
 int /*<<< orphan*/  USETW (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  USLCOM_IFC_ENABLE ; 
 int /*<<< orphan*/  USLCOM_IFC_ENABLE_EN ; 
 int /*<<< orphan*/  USLCOM_WRITE ; 
 scalar_t__ ucom_cfg_do_request (int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct usb_device_request*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  uslcom_watchdog (struct uslcom_softc*) ; 

__attribute__((used)) static void
uslcom_cfg_open(struct ucom_softc *ucom)
{
	struct uslcom_softc *sc = ucom->sc_parent;
	struct usb_device_request req;

	req.bmRequestType = USLCOM_WRITE;
	req.bRequest = USLCOM_IFC_ENABLE;
	USETW(req.wValue, USLCOM_IFC_ENABLE_EN);
	USETW(req.wIndex, sc->sc_iface_no);
	USETW(req.wLength, 0);

        if (ucom_cfg_do_request(sc->sc_udev, &sc->sc_ucom,
	    &req, NULL, 0, 1000)) {
		DPRINTF("UART enable failed (ignored)\n");
	}

	/* start polling status */
	uslcom_watchdog(sc);
}