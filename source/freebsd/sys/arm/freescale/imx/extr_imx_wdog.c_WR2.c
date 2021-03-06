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
typedef  int /*<<< orphan*/  uint16_t ;
struct imx_wdog_softc {int /*<<< orphan*/ * sc_res; } ;
typedef  int /*<<< orphan*/  bus_size_t ;

/* Variables and functions */
 size_t MEMRES ; 
 int /*<<< orphan*/  bus_write_2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void
WR2(struct imx_wdog_softc *sc, bus_size_t offs, uint16_t val)
{

	bus_write_2(sc->sc_res[MEMRES], offs, val);
}