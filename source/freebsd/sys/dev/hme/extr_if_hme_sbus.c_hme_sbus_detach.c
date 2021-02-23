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
struct hme_softc {int /*<<< orphan*/  sc_lock; } ;
struct hme_sbus_softc {int /*<<< orphan*/ * hsc_seb_res; int /*<<< orphan*/ * hsc_etx_res; int /*<<< orphan*/ * hsc_erx_res; int /*<<< orphan*/ * hsc_mac_res; int /*<<< orphan*/ * hsc_mif_res; int /*<<< orphan*/ * hsc_ires; int /*<<< orphan*/  hsc_ih; struct hme_softc hsc_hme; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  SYS_RES_IRQ ; 
 int /*<<< orphan*/  SYS_RES_MEMORY ; 
 int /*<<< orphan*/  bus_release_resource (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bus_teardown_intr (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct hme_sbus_softc* device_get_softc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hme_detach (struct hme_softc*) ; 
 int /*<<< orphan*/  mtx_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rman_get_rid (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int
hme_sbus_detach(device_t dev)
{
	struct hme_sbus_softc *hsc;
	struct hme_softc *sc;

	hsc = device_get_softc(dev);
	sc = &hsc->hsc_hme;
	bus_teardown_intr(dev, hsc->hsc_ires, hsc->hsc_ih);
	hme_detach(sc);
	bus_release_resource(dev, SYS_RES_IRQ,
	    rman_get_rid(hsc->hsc_ires), hsc->hsc_ires);
	if (hsc->hsc_mif_res != NULL) {
		bus_release_resource(dev, SYS_RES_MEMORY,
		    rman_get_rid(hsc->hsc_mif_res), hsc->hsc_mif_res);
	}
	bus_release_resource(dev, SYS_RES_MEMORY,
	    rman_get_rid(hsc->hsc_mac_res), hsc->hsc_mac_res);
	bus_release_resource(dev, SYS_RES_MEMORY,
	    rman_get_rid(hsc->hsc_erx_res), hsc->hsc_erx_res);
	bus_release_resource(dev, SYS_RES_MEMORY,
	    rman_get_rid(hsc->hsc_etx_res), hsc->hsc_etx_res);
	bus_release_resource(dev, SYS_RES_MEMORY,
	    rman_get_rid(hsc->hsc_seb_res), hsc->hsc_seb_res);
	mtx_destroy(&sc->sc_lock);
	return (0);
}