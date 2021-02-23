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
struct terasic_mtl_softc {int /*<<< orphan*/  mtl_reg_res; } ;

/* Variables and functions */
 int /*<<< orphan*/  TERASIC_MTL_OFF_TEXTFRAMEBUFADDR ; 
 int /*<<< orphan*/  bus_write_4 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  htole32 (int /*<<< orphan*/ ) ; 

void
terasic_mtl_reg_textframebufaddr_set(struct terasic_mtl_softc *sc,
    uint32_t addr)
{

	addr = htole32(addr);
	bus_write_4(sc->mtl_reg_res, TERASIC_MTL_OFF_TEXTFRAMEBUFADDR, addr);
}