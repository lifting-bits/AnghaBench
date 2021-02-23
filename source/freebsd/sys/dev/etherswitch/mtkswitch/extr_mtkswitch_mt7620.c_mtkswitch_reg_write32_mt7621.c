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
typedef  int /*<<< orphan*/  uint32_t ;
struct mtkswitch_softc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MTKSWITCH_GLOBAL_PHY ; 
 int /*<<< orphan*/  MTKSWITCH_GLOBAL_REG ; 
 int /*<<< orphan*/  MTKSWITCH_REG_ADDR (int) ; 
 int /*<<< orphan*/  MTKSWITCH_REG_HI (int) ; 
 int /*<<< orphan*/  MTKSWITCH_REG_LO (int) ; 
 int /*<<< orphan*/  MTKSWITCH_VAL_HI (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MTKSWITCH_VAL_LO (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtkswitch_phy_write_locked (struct mtkswitch_softc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static uint32_t
mtkswitch_reg_write32_mt7621(struct mtkswitch_softc *sc, int reg, uint32_t val)
{

	mtkswitch_phy_write_locked(sc, MTKSWITCH_GLOBAL_PHY,
	    MTKSWITCH_GLOBAL_REG, MTKSWITCH_REG_ADDR(reg));
	mtkswitch_phy_write_locked(sc, MTKSWITCH_GLOBAL_PHY,
	    MTKSWITCH_REG_LO(reg), MTKSWITCH_VAL_LO(val));
	mtkswitch_phy_write_locked(sc, MTKSWITCH_GLOBAL_PHY,
	    MTKSWITCH_REG_HI(reg), MTKSWITCH_VAL_HI(val));
	return (0);
}