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
struct mii_bus {int /*<<< orphan*/  dev; struct gswip_priv* priv; } ;
struct gswip_priv {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  GSWIP_MDIO_CTRL ; 
 int GSWIP_MDIO_CTRL_BUSY ; 
 int GSWIP_MDIO_CTRL_PHYAD_MASK ; 
 int GSWIP_MDIO_CTRL_PHYAD_SHIFT ; 
 int GSWIP_MDIO_CTRL_RD ; 
 int GSWIP_MDIO_CTRL_REGAD_MASK ; 
 int /*<<< orphan*/  GSWIP_MDIO_READ ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int gswip_mdio_poll (struct gswip_priv*) ; 
 int gswip_mdio_r (struct gswip_priv*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gswip_mdio_w (struct gswip_priv*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int gswip_mdio_rd(struct mii_bus *bus, int addr, int reg)
{
	struct gswip_priv *priv = bus->priv;
	int err;

	err = gswip_mdio_poll(priv);
	if (err) {
		dev_err(&bus->dev, "waiting for MDIO bus busy timed out\n");
		return err;
	}

	gswip_mdio_w(priv, GSWIP_MDIO_CTRL_BUSY | GSWIP_MDIO_CTRL_RD |
		((addr & GSWIP_MDIO_CTRL_PHYAD_MASK) << GSWIP_MDIO_CTRL_PHYAD_SHIFT) |
		(reg & GSWIP_MDIO_CTRL_REGAD_MASK),
		GSWIP_MDIO_CTRL);

	err = gswip_mdio_poll(priv);
	if (err) {
		dev_err(&bus->dev, "waiting for MDIO bus busy timed out\n");
		return err;
	}

	return gswip_mdio_r(priv, GSWIP_MDIO_READ);
}