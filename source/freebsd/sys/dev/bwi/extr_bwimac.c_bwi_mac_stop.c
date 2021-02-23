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
struct bwi_softc {int /*<<< orphan*/  sc_dev; } ;
struct bwi_mac {struct bwi_softc* mac_sc; } ;

/* Variables and functions */
 int BWI_INTR_READY ; 
 int /*<<< orphan*/  BWI_MAC_INTR_STATUS ; 
 int /*<<< orphan*/  BWI_MAC_STATUS ; 
 int /*<<< orphan*/  BWI_MAC_STATUS_ENABLE ; 
 int /*<<< orphan*/  CSR_CLRBITS_4 (struct bwi_softc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int CSR_READ_4 (struct bwi_softc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DELAY (int) ; 
 int ETIMEDOUT ; 
 int NRETRY ; 
 int bwi_mac_config_ps (struct bwi_mac*) ; 
 int /*<<< orphan*/  device_printf (int /*<<< orphan*/ ,char*) ; 

int
bwi_mac_stop(struct bwi_mac *mac)
{
	struct bwi_softc *sc = mac->mac_sc;
	int error, i;

	error = bwi_mac_config_ps(mac);
	if (error)
		return error;

	CSR_CLRBITS_4(sc, BWI_MAC_STATUS, BWI_MAC_STATUS_ENABLE);

	/* Flush pending bus write */
	CSR_READ_4(sc, BWI_MAC_STATUS);

#define NRETRY	10000
	for (i = 0; i < NRETRY; ++i) {
		if (CSR_READ_4(sc, BWI_MAC_INTR_STATUS) & BWI_INTR_READY)
			break;
		DELAY(1);
	}
	if (i == NRETRY) {
		device_printf(sc->sc_dev, "can't stop MAC\n");
		return ETIMEDOUT;
	}
#undef NRETRY

	return 0;
}