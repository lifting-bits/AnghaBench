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
struct rtwn_softc {int dummy; } ;
struct ieee80211_channel {int /*<<< orphan*/  ic_flags; } ;

/* Variables and functions */
 scalar_t__ IEEE80211_IS_CHAN_2GHZ (struct ieee80211_channel*) ; 
 scalar_t__ IEEE80211_IS_CHAN_5GHZ (struct ieee80211_channel*) ; 
 int /*<<< orphan*/  KASSERT (int /*<<< orphan*/ ,char*) ; 
 int rtwn_chan2centieee (struct ieee80211_channel*) ; 

__attribute__((used)) static int
r12a_get_power_group(struct rtwn_softc *sc, struct ieee80211_channel *c)
{
	uint8_t chan;
	int group;

	chan = rtwn_chan2centieee(c);
	if (IEEE80211_IS_CHAN_2GHZ(c)) {
		if (chan <= 2)			group = 0;
		else if (chan <= 5)		group = 1;
		else if (chan <= 8)		group = 2;
		else if (chan <= 11)		group = 3;
		else if (chan <= 14)		group = 4;
		else {
			KASSERT(0, ("wrong 2GHz channel %d!\n", chan));
			return (-1);
		}
	} else if (IEEE80211_IS_CHAN_5GHZ(c)) {
		if (chan < 36)
			return (-1);

		if (chan <= 42)			group = 0;
		else if (chan <= 48)		group = 1;
		else if (chan <= 58)		group = 2;
		else if (chan <= 64)		group = 3;
		else if (chan <= 106)		group = 4;
		else if (chan <= 114)		group = 5;
		else if (chan <= 122)		group = 6;
		else if (chan <= 130)		group = 7;
		else if (chan <= 138)		group = 8;
		else if (chan <= 144)		group = 9;
		else if (chan <= 155)		group = 10;
		else if (chan <= 161)		group = 11;
		else if (chan <= 171)		group = 12;
		else if (chan <= 177)		group = 13;
		else {
			KASSERT(0, ("wrong 5GHz channel %d!\n", chan));
			return (-1);
		}
	} else {
		KASSERT(0, ("wrong channel band (flags %08X)\n", c->ic_flags));
		return (-1);
	}

	return (group);
}