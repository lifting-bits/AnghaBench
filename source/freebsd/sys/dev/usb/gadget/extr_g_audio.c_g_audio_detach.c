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
struct g_audio_softc {int /*<<< orphan*/  sc_mtx; int /*<<< orphan*/  sc_watchdog; int /*<<< orphan*/  sc_callout; int /*<<< orphan*/  sc_xfer; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  DPRINTF (char*) ; 
 int /*<<< orphan*/  G_AUDIO_N_TRANSFER ; 
 struct g_audio_softc* device_get_softc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtx_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mtx_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mtx_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  usb_callout_drain (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  usb_callout_stop (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  usbd_transfer_unsetup (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
g_audio_detach(device_t dev)
{
	struct g_audio_softc *sc = device_get_softc(dev);

	DPRINTF("\n");

	mtx_lock(&sc->sc_mtx);
	usb_callout_stop(&sc->sc_callout);
	usb_callout_stop(&sc->sc_watchdog);
	mtx_unlock(&sc->sc_mtx);

	usbd_transfer_unsetup(sc->sc_xfer, G_AUDIO_N_TRANSFER);

	usb_callout_drain(&sc->sc_callout);
	usb_callout_drain(&sc->sc_watchdog);

	mtx_destroy(&sc->sc_mtx);

	return (0);
}