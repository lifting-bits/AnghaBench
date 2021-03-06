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
typedef  int u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct brcms_phy {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  wlc_phy_table_write_nphy (struct brcms_phy*,int,int,int,int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void wlc_phy_ipa_set_bbmult_nphy(struct brcms_phy *pi, u8 m0, u8 m1)
{
	u16 m0m1 = (u16) ((m0 << 8) | m1);

	wlc_phy_table_write_nphy(pi, 15, 1, 87, 16, &m0m1);
	wlc_phy_table_write_nphy(pi, 15, 1, 95, 16, &m0m1);
}