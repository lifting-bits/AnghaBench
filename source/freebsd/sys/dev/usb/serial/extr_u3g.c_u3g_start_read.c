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
struct ucom_softc {size_t sc_subunit; struct u3g_softc* sc_parent; } ;
struct u3g_softc {int /*<<< orphan*/ ** sc_xfer; } ;

/* Variables and functions */
 size_t U3G_BULK_RD ; 
 size_t U3G_INTR ; 
 int /*<<< orphan*/  usbd_transfer_start (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
u3g_start_read(struct ucom_softc *ucom)
{
	struct u3g_softc *sc = ucom->sc_parent;

	/* start interrupt endpoint (if configured) */
	usbd_transfer_start(sc->sc_xfer[ucom->sc_subunit][U3G_INTR]);

	/* start read endpoint */
	usbd_transfer_start(sc->sc_xfer[ucom->sc_subunit][U3G_BULK_RD]);
}