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
struct atse_softc {int atse_phy_addr; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  PHY_WRITE_2 (struct atse_softc*,int,int) ; 
 struct atse_softc* device_get_softc (int /*<<< orphan*/ ) ; 

int
atse_miibus_writereg(device_t dev, int phy, int reg, int data)
{
	struct atse_softc *sc;

	sc = device_get_softc(dev);

	/*
	 * We currently do not support re-mapping of MDIO space on-the-fly
	 * but de-facto hard-code the phy#.
	 */
	if (phy != sc->atse_phy_addr) {
		return (0);
	}

	PHY_WRITE_2(sc, reg, data);
	return (0);
}