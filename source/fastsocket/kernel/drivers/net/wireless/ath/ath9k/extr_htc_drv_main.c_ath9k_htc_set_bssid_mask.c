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
struct ieee80211_vif {int /*<<< orphan*/  addr; } ;
struct ath_common {int /*<<< orphan*/  bssidmask; int /*<<< orphan*/  macaddr; } ;
struct ath9k_vif_iter_data {int /*<<< orphan*/  mask; int /*<<< orphan*/  hw_macaddr; } ;
struct ath9k_htc_priv {int /*<<< orphan*/  hw; int /*<<< orphan*/  ah; } ;

/* Variables and functions */
 int /*<<< orphan*/  ETH_ALEN ; 
 int /*<<< orphan*/  IEEE80211_IFACE_ITER_RESUME_ALL ; 
 int /*<<< orphan*/  ath9k_htc_bssid_iter (struct ath9k_vif_iter_data*,int /*<<< orphan*/ ,struct ieee80211_vif*) ; 
 struct ath_common* ath9k_hw_common (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ath_hw_setbssidmask (struct ath_common*) ; 
 int /*<<< orphan*/  ieee80211_iterate_active_interfaces_atomic (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (struct ath9k_vif_iter_data*,int /*<<< orphan*/ ,struct ieee80211_vif*),struct ath9k_vif_iter_data*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void ath9k_htc_set_bssid_mask(struct ath9k_htc_priv *priv,
				     struct ieee80211_vif *vif)
{
	struct ath_common *common = ath9k_hw_common(priv->ah);
	struct ath9k_vif_iter_data iter_data;

	/*
	 * Use the hardware MAC address as reference, the hardware uses it
	 * together with the BSSID mask when matching addresses.
	 */
	iter_data.hw_macaddr = common->macaddr;
	memset(&iter_data.mask, 0xff, ETH_ALEN);

	if (vif)
		ath9k_htc_bssid_iter(&iter_data, vif->addr, vif);

	/* Get list of all active MAC addresses */
	ieee80211_iterate_active_interfaces_atomic(
		priv->hw, IEEE80211_IFACE_ITER_RESUME_ALL,
		ath9k_htc_bssid_iter, &iter_data);

	memcpy(common->bssidmask, iter_data.mask, ETH_ALEN);
	ath_hw_setbssidmask(common);
}