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
struct bwn_phy {int rev; int /*<<< orphan*/  rf_rev; } ;
struct bwn_mac {struct bwn_phy mac_phy; } ;
struct b2056_inittabs_pts {int dummy; } ;

/* Variables and functions */
 struct b2056_inittabs_pts const b2056_inittab_phy_rev3 ; 
 struct b2056_inittabs_pts const b2056_inittab_phy_rev4 ; 
 struct b2056_inittabs_pts const b2056_inittab_radio_rev11 ; 
 struct b2056_inittabs_pts const b2056_inittab_radio_rev5 ; 
 struct b2056_inittabs_pts const b2056_inittab_radio_rev6 ; 
 struct b2056_inittabs_pts const b2056_inittab_radio_rev7_9 ; 
 struct b2056_inittabs_pts const b2056_inittab_radio_rev8 ; 

__attribute__((used)) static const struct b2056_inittabs_pts
*bwn_nphy_get_inittabs_rev3(struct bwn_mac *mac)
{
	struct bwn_phy *phy = &mac->mac_phy;

	switch (phy->rev) {
	case 3:
		return &b2056_inittab_phy_rev3;
	case 4:
		return &b2056_inittab_phy_rev4;
	default:
		switch (phy->rf_rev) {
		case 5:
			return &b2056_inittab_radio_rev5;
		case 6:
			return &b2056_inittab_radio_rev6;
		case 7:
		case 9:
			return &b2056_inittab_radio_rev7_9;
		case 8:
			return &b2056_inittab_radio_rev8;
		case 11:
			return &b2056_inittab_radio_rev11;
		}
	}

	return NULL;
}