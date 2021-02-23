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
struct dc_softc {int dummy; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int BUS_SPACE_BARRIER_READ ; 
 int BUS_SPACE_BARRIER_WRITE ; 
 int /*<<< orphan*/  CSR_BARRIER_4 (struct dc_softc*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  CSR_READ_4 (struct dc_softc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DC_SIO ; 
 struct dc_softc* device_get_softc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static uint32_t
dc_mii_bitbang_read(device_t dev)
{
	struct dc_softc *sc;
	uint32_t val;

	sc = device_get_softc(dev);

	val = CSR_READ_4(sc, DC_SIO);
	CSR_BARRIER_4(sc, DC_SIO,
	    BUS_SPACE_BARRIER_READ | BUS_SPACE_BARRIER_WRITE);

	return (val);
}