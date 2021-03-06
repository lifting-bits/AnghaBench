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
typedef  int u16 ;
struct e1000_phy_info {int /*<<< orphan*/  cable_polarity; } ;
struct e1000_hw {struct e1000_phy_info phy; } ;
typedef  int /*<<< orphan*/  s32 ;

/* Variables and functions */
 int /*<<< orphan*/  M88E1000_PHY_SPEC_STATUS ; 
 int M88E1000_PSSR_REV_POLARITY ; 
 int /*<<< orphan*/  e1000_rev_polarity_normal ; 
 int /*<<< orphan*/  e1000_rev_polarity_reversed ; 
 int /*<<< orphan*/  e1e_rphy (struct e1000_hw*,int /*<<< orphan*/ ,int*) ; 

s32 e1000_check_polarity_m88(struct e1000_hw *hw)
{
	struct e1000_phy_info *phy = &hw->phy;
	s32 ret_val;
	u16 data;

	ret_val = e1e_rphy(hw, M88E1000_PHY_SPEC_STATUS, &data);

	if (!ret_val)
		phy->cable_polarity = ((data & M88E1000_PSSR_REV_POLARITY)
				       ? e1000_rev_polarity_reversed
				       : e1000_rev_polarity_normal);

	return ret_val;
}