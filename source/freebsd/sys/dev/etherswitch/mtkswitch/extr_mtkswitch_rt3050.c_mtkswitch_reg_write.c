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
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  MA_OWNED ; 
 int /*<<< orphan*/  MTKSWITCH_HI16_MSK ; 
 scalar_t__ MTKSWITCH_IS_HI16 (int) ; 
 int /*<<< orphan*/  MTKSWITCH_LO16_MSK ; 
 int /*<<< orphan*/  MTKSWITCH_LOCK_ASSERT (struct mtkswitch_softc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MTKSWITCH_READ (struct mtkswitch_softc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MTKSWITCH_REG32 (int) ; 
 int /*<<< orphan*/  MTKSWITCH_TO_HI16 (int) ; 
 int /*<<< orphan*/  MTKSWITCH_TO_LO16 (int) ; 
 int /*<<< orphan*/  MTKSWITCH_WRITE (struct mtkswitch_softc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct mtkswitch_softc* device_get_softc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
mtkswitch_reg_write(device_t dev, int reg, int val)
{
	struct mtkswitch_softc *sc = device_get_softc(dev);
	uint32_t tmp;

	MTKSWITCH_LOCK_ASSERT(sc, MA_OWNED);
	tmp = MTKSWITCH_READ(sc, MTKSWITCH_REG32(reg));
	if (MTKSWITCH_IS_HI16(reg)) {
		tmp &= MTKSWITCH_LO16_MSK;
		tmp |= MTKSWITCH_TO_HI16(val);
	} else {
		tmp &= MTKSWITCH_HI16_MSK;
		tmp |= MTKSWITCH_TO_LO16(val);
	}
	MTKSWITCH_WRITE(sc, MTKSWITCH_REG32(reg), tmp);

	return (0);
}