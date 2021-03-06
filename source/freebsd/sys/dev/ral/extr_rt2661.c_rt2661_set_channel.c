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
struct rt2661_softc {int dummy; } ;
struct ieee80211com {int /*<<< orphan*/  ic_curchan; struct rt2661_softc* ic_softc; } ;

/* Variables and functions */
 int /*<<< orphan*/  RAL_LOCK (struct rt2661_softc*) ; 
 int /*<<< orphan*/  RAL_UNLOCK (struct rt2661_softc*) ; 
 int /*<<< orphan*/  rt2661_set_chan (struct rt2661_softc*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
rt2661_set_channel(struct ieee80211com *ic)
{
	struct rt2661_softc *sc = ic->ic_softc;

	RAL_LOCK(sc);
	rt2661_set_chan(sc, ic->ic_curchan);
	RAL_UNLOCK(sc);

}