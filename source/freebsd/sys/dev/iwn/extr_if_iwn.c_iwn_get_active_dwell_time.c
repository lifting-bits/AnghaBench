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
typedef  int uint8_t ;
typedef  scalar_t__ uint16_t ;
struct iwn_softc {int dummy; } ;
struct ieee80211_channel {int dummy; } ;

/* Variables and functions */
 scalar_t__ IEEE80211_IS_CHAN_2GHZ (struct ieee80211_channel*) ; 
 int IWN_ACTIVE_DWELL_FACTOR_2GHZ ; 
 int IWN_ACTIVE_DWELL_FACTOR_5GHZ ; 
 scalar_t__ IWN_ACTIVE_DWELL_TIME_2GHZ ; 
 scalar_t__ IWN_ACTIVE_DWELL_TIME_5GHZ ; 

__attribute__((used)) static uint16_t
iwn_get_active_dwell_time(struct iwn_softc *sc,
    struct ieee80211_channel *c, uint8_t n_probes)
{
	/* No channel? Default to 2GHz settings */
	if (c == NULL || IEEE80211_IS_CHAN_2GHZ(c)) {
		return (IWN_ACTIVE_DWELL_TIME_2GHZ +
		IWN_ACTIVE_DWELL_FACTOR_2GHZ * (n_probes + 1));
	}

	/* 5GHz dwell time */
	return (IWN_ACTIVE_DWELL_TIME_5GHZ +
	    IWN_ACTIVE_DWELL_FACTOR_5GHZ * (n_probes + 1));
}