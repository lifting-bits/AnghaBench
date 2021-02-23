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
typedef  int uint32_t ;
struct zy7_slcr_softc {int dummy; } ;

/* Variables and functions */
 int RD4 (struct zy7_slcr_softc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ZSLCR_LOCK (struct zy7_slcr_softc*) ; 
 int /*<<< orphan*/  ZSLCR_UNLOCK (struct zy7_slcr_softc*) ; 
 int /*<<< orphan*/  ZY7_SLCR_FPGA_THR_CNT (int) ; 
 struct zy7_slcr_softc* zy7_slcr_softc_p ; 

int 
zy7_pl_fclk_enabled(int unit)
{
	struct zy7_slcr_softc *sc = zy7_slcr_softc_p;
	uint32_t reg;

	if (!sc)
		return (-1);

	ZSLCR_LOCK(sc);
	reg = RD4(sc, ZY7_SLCR_FPGA_THR_CNT(unit));
	ZSLCR_UNLOCK(sc);

	return !(reg & 1);
}