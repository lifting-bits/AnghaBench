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
struct msk_softc {int dummy; } ;
struct msk_if_softc {int /*<<< orphan*/  msk_ifp; int /*<<< orphan*/  msk_port; struct msk_softc* msk_softc; } ;

/* Variables and functions */
 int /*<<< orphan*/  DELAY (int) ; 
 int GMAC_READ_2 (struct msk_softc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GMAC_WRITE_2 (struct msk_softc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  GM_SMI_CTRL ; 
 int GM_SMI_CT_OP_RD ; 
 int GM_SMI_CT_PHY_AD (int) ; 
 int GM_SMI_CT_RD_VAL ; 
 int GM_SMI_CT_REG_AD (int) ; 
 int /*<<< orphan*/  GM_SMI_DATA ; 
 int MSK_TIMEOUT ; 
 int /*<<< orphan*/  if_printf (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static int
msk_phy_readreg(struct msk_if_softc *sc_if, int phy, int reg)
{
	struct msk_softc *sc;
	int i, val;

	sc = sc_if->msk_softc;

        GMAC_WRITE_2(sc, sc_if->msk_port, GM_SMI_CTRL,
	    GM_SMI_CT_PHY_AD(phy) | GM_SMI_CT_REG_AD(reg) | GM_SMI_CT_OP_RD);

	for (i = 0; i < MSK_TIMEOUT; i++) {
		DELAY(1);
		val = GMAC_READ_2(sc, sc_if->msk_port, GM_SMI_CTRL);
		if ((val & GM_SMI_CT_RD_VAL) != 0) {
			val = GMAC_READ_2(sc, sc_if->msk_port, GM_SMI_DATA);
			break;
		}
	}

	if (i == MSK_TIMEOUT) {
		if_printf(sc_if->msk_ifp, "phy failed to come ready\n");
		val = 0;
	}

	return (val);
}