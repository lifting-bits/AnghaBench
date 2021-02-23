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
typedef  int uint16_t ;
struct ure_softc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  URE_MCU_TYPE_PLA ; 
 int URE_PLA_OCP_GPHY_BASE ; 
 int /*<<< orphan*/  ure_write_2 (struct ure_softc*,int,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void
ure_ocp_reg_write(struct ure_softc *sc, uint16_t addr, uint16_t data)
{
	uint16_t reg;

	ure_write_2(sc, URE_PLA_OCP_GPHY_BASE, URE_MCU_TYPE_PLA, addr & 0xf000);
	reg = (addr & 0x0fff) | 0xb000;

	ure_write_2(sc, reg, URE_MCU_TYPE_PLA, data);
}