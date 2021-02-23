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
struct wlan_iface {scalar_t__ status; } ;

/* Variables and functions */
 scalar_t__ RowStatus_active ; 
 scalar_t__ WLAN_LIST_MAXAGE ; 
 scalar_t__ time (int /*<<< orphan*/ *) ; 
 struct wlan_iface* wlan_first_interface () ; 
 int /*<<< orphan*/  wlan_get_scan_results (struct wlan_iface*) ; 
 struct wlan_iface* wlan_next_interface (struct wlan_iface*) ; 
 int /*<<< orphan*/  wlan_scan_free_results (struct wlan_iface*) ; 
 scalar_t__ wlan_scanlist_age ; 

__attribute__((used)) static void
wlan_scan_update_results(void)
{
	struct wlan_iface *wif;

	if ((time(NULL) - wlan_scanlist_age) <= WLAN_LIST_MAXAGE)
		return;

	for (wif = wlan_first_interface(); wif != NULL;
	    wif = wlan_next_interface(wif)) {
		if (wif->status != RowStatus_active)
			continue;
		wlan_scan_free_results(wif);
		(void)wlan_get_scan_results(wif);
	}
	wlan_scanlist_age = time(NULL);
}