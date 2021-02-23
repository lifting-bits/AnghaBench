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
struct smc_softc {int /*<<< orphan*/ * smc_miibus; } ;

/* Variables and functions */
 int /*<<< orphan*/  device_get_softc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mii_mediachg (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
smc_mii_mediachg(struct smc_softc *sc)
{

	if (sc->smc_miibus == NULL)
		return;
	mii_mediachg(device_get_softc(sc->smc_miibus));
}