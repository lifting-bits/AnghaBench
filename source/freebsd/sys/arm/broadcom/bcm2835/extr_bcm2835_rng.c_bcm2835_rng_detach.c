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
struct bcm2835_rng_softc {int /*<<< orphan*/ * sc_mem_res; int /*<<< orphan*/  sc_rngto; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  SYS_RES_MEMORY ; 
 int /*<<< orphan*/  bcm2835_rng_stop (struct bcm2835_rng_softc*) ; 
 int /*<<< orphan*/  bus_release_resource (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  callout_drain (int /*<<< orphan*/ *) ; 
 struct bcm2835_rng_softc* device_get_softc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
bcm2835_rng_detach(device_t dev)
{
	struct bcm2835_rng_softc *sc;

	sc = device_get_softc(dev);

	/* Stop the RNG */
	bcm2835_rng_stop(sc);

	/* Drain the callout it */
	callout_drain(&sc->sc_rngto);

	/* Release memory resource */
	if (sc->sc_mem_res != NULL)
		bus_release_resource(dev, SYS_RES_MEMORY, 0, sc->sc_mem_res);

	return (0);
}