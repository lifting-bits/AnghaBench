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
struct octeon_rnd_softc {int /*<<< orphan*/  sc_callout; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  callout_stop (int /*<<< orphan*/ *) ; 
 struct octeon_rnd_softc* device_get_softc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
octeon_rnd_detach(device_t dev)
{
	struct octeon_rnd_softc *sc;

	sc = device_get_softc(dev);

	callout_stop(&sc->sc_callout);

	return (0);
}