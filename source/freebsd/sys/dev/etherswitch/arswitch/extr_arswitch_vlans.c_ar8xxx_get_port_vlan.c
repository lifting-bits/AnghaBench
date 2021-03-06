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
struct arswitch_softc {int /*<<< orphan*/  sc_dev; } ;

/* Variables and functions */
 int AR8X16_PORT_VLAN_DEST_PORTS_SHIFT ; 
 int /*<<< orphan*/  AR8X16_REG_PORT_VLAN (int) ; 
 int AR8X16_VLAN_MEMBER ; 
 int /*<<< orphan*/  ARSWITCH_LOCK_ASSERT (struct arswitch_softc*,int /*<<< orphan*/ ) ; 
 int ETHERSWITCH_VID_MASK ; 
 int /*<<< orphan*/  MA_OWNED ; 
 int arswitch_readreg (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int
ar8xxx_get_port_vlan(struct arswitch_softc *sc, uint32_t *ports, int vid)
{
	int port;
	uint32_t reg;

	ARSWITCH_LOCK_ASSERT(sc, MA_OWNED);
	/* For port based vlans the vlanid is the same as the port index. */
	port = vid & ETHERSWITCH_VID_MASK;
	reg = arswitch_readreg(sc->sc_dev, AR8X16_REG_PORT_VLAN(port));
	*ports = (reg >> AR8X16_PORT_VLAN_DEST_PORTS_SHIFT);
	*ports &= AR8X16_VLAN_MEMBER;
	return (0);
}