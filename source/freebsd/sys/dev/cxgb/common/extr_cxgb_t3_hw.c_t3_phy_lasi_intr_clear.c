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
typedef  int /*<<< orphan*/  u32 ;
struct cphy {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  LASI_STAT ; 
 int /*<<< orphan*/  MDIO_DEV_PMA_PMD ; 
 int mdio_read (struct cphy*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

int t3_phy_lasi_intr_clear(struct cphy *phy)
{
	u32 val;

	return mdio_read(phy, MDIO_DEV_PMA_PMD, LASI_STAT, &val);
}