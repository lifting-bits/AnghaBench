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
struct brcms_phy_pub {int dummy; } ;
struct brcms_phy {int ofdm_rateset_war; } ;

/* Variables and functions */

void wlc_phy_ofdm_rateset_war(struct brcms_phy_pub *pih, bool war)
{
	struct brcms_phy *pi = (struct brcms_phy *) pih;

	pi->ofdm_rateset_war = war;
}