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
typedef  int /*<<< orphan*/  uint8_t ;
struct ieee80211_node {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ieee80211_parse_vhtcap (struct ieee80211_node*,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  ieee80211_parse_vhtopmode (struct ieee80211_node*,int /*<<< orphan*/  const*) ; 

void
ieee80211_vht_update_cap(struct ieee80211_node *ni, const uint8_t *vhtcap_ie,
    const uint8_t *vhtop_ie)
{

	ieee80211_parse_vhtcap(ni, vhtcap_ie);
	ieee80211_parse_vhtopmode(ni, vhtop_ie);
}