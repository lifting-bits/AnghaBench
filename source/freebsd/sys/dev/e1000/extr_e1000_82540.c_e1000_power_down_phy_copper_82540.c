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
struct e1000_hw {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  E1000_MANC ; 
 int E1000_MANC_SMBUS_EN ; 
 int E1000_READ_REG (struct e1000_hw*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  e1000_power_down_phy_copper (struct e1000_hw*) ; 

__attribute__((used)) static void e1000_power_down_phy_copper_82540(struct e1000_hw *hw)
{
	/* If the management interface is not enabled, then power down */
	if (!(E1000_READ_REG(hw, E1000_MANC) & E1000_MANC_SMBUS_EN))
		e1000_power_down_phy_copper(hw);

	return;
}