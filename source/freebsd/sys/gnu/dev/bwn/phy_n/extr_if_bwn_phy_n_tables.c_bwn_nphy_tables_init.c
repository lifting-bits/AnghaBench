#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int rev; } ;
struct bwn_mac {TYPE_1__ mac_phy; } ;

/* Variables and functions */
 int /*<<< orphan*/  bwn_nphy_tables_init_rev0 (struct bwn_mac*) ; 
 int /*<<< orphan*/  bwn_nphy_tables_init_rev16 (struct bwn_mac*) ; 
 int /*<<< orphan*/  bwn_nphy_tables_init_rev3 (struct bwn_mac*) ; 
 int /*<<< orphan*/  bwn_nphy_tables_init_rev7 (struct bwn_mac*) ; 

void bwn_nphy_tables_init(struct bwn_mac *mac)
{
	if (mac->mac_phy.rev >= 16)
		bwn_nphy_tables_init_rev16(mac);
	else if (mac->mac_phy.rev >= 7)
		bwn_nphy_tables_init_rev7(mac);
	else if (mac->mac_phy.rev >= 3)
		bwn_nphy_tables_init_rev3(mac);
	else
		bwn_nphy_tables_init_rev0(mac);
}