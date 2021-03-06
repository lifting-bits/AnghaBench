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
struct ieee80211_hw {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  NL80211_IFTYPE_UNSPECIFIED ; 
 int /*<<< orphan*/  rtl92c_set_network_type (struct ieee80211_hw*,int /*<<< orphan*/ ) ; 

void rtl92c_init_network_type(struct ieee80211_hw *hw)
{
	rtl92c_set_network_type(hw, NL80211_IFTYPE_UNSPECIFIED);
}