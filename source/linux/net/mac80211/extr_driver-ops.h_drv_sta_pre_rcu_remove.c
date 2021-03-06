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
struct sta_info {int /*<<< orphan*/  sta; } ;
struct ieee80211_sub_if_data {int /*<<< orphan*/  vif; } ;
struct ieee80211_local {int /*<<< orphan*/  hw; TYPE_1__* ops; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* sta_pre_rcu_remove ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  check_sdata_in_driver (struct ieee80211_sub_if_data*) ; 
 struct ieee80211_sub_if_data* get_bss_sdata (struct ieee80211_sub_if_data*) ; 
 int /*<<< orphan*/  might_sleep () ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  trace_drv_return_void (struct ieee80211_local*) ; 
 int /*<<< orphan*/  trace_drv_sta_pre_rcu_remove (struct ieee80211_local*,struct ieee80211_sub_if_data*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void drv_sta_pre_rcu_remove(struct ieee80211_local *local,
					  struct ieee80211_sub_if_data *sdata,
					  struct sta_info *sta)
{
	might_sleep();

	sdata = get_bss_sdata(sdata);
	if (!check_sdata_in_driver(sdata))
		return;

	trace_drv_sta_pre_rcu_remove(local, sdata, &sta->sta);
	if (local->ops->sta_pre_rcu_remove)
		local->ops->sta_pre_rcu_remove(&local->hw, &sdata->vif,
					       &sta->sta);
	trace_drv_return_void(local);
}