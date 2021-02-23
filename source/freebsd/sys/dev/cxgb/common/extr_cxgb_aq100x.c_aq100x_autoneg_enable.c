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
struct cphy {int dummy; } ;

/* Variables and functions */
 int BMCR_ANENABLE ; 
 int BMCR_ANRESTART ; 
 int /*<<< orphan*/  BMCR_RESET ; 
 int /*<<< orphan*/  MDIO_DEV_ANEG ; 
 int /*<<< orphan*/  MII_BMCR ; 
 int aq100x_power_down (struct cphy*,int /*<<< orphan*/ ) ; 
 int t3_mdio_change_bits (struct cphy*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int
aq100x_autoneg_enable(struct cphy *phy)
{
	int err;

	err = aq100x_power_down(phy, 0);
	if (!err)
		err = t3_mdio_change_bits(phy, MDIO_DEV_ANEG, MII_BMCR,
		    BMCR_RESET, BMCR_ANENABLE | BMCR_ANRESTART);

	return (err);
}