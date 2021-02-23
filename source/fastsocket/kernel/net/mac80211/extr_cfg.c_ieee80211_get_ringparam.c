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
struct wiphy {int dummy; } ;
struct ieee80211_local {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  drv_get_ringparam (struct ieee80211_local*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct ieee80211_local* wiphy_priv (struct wiphy*) ; 

__attribute__((used)) static void ieee80211_get_ringparam(struct wiphy *wiphy,
				    u32 *tx, u32 *tx_max, u32 *rx, u32 *rx_max)
{
	struct ieee80211_local *local = wiphy_priv(wiphy);

	drv_get_ringparam(local, tx, tx_max, rx, rx_max);
}