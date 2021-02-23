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
struct ieee80211com {int dummy; } ;
struct ipw_softc {int flags; struct ieee80211com sc_ic; } ;

/* Variables and functions */
 int IPW_FLAG_RUNNING ; 
 int /*<<< orphan*/  IPW_LOCK (struct ipw_softc*) ; 
 int /*<<< orphan*/  IPW_UNLOCK (struct ipw_softc*) ; 
 int /*<<< orphan*/  ieee80211_start_all (struct ieee80211com*) ; 
 int /*<<< orphan*/  ipw_init_locked (struct ipw_softc*) ; 

__attribute__((used)) static void
ipw_init(void *priv)
{
	struct ipw_softc *sc = priv;
	struct ieee80211com *ic = &sc->sc_ic;

	IPW_LOCK(sc);
	ipw_init_locked(sc);
	IPW_UNLOCK(sc);

	if (sc->flags & IPW_FLAG_RUNNING)
		ieee80211_start_all(ic);		/* start all vap's */
}