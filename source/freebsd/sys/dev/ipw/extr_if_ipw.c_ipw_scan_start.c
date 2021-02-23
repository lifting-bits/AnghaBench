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
struct ipw_softc {int dummy; } ;
struct ieee80211com {struct ipw_softc* ic_softc; } ;

/* Variables and functions */
 int /*<<< orphan*/  IPW_LOCK (struct ipw_softc*) ; 
 int /*<<< orphan*/  IPW_UNLOCK (struct ipw_softc*) ; 
 int /*<<< orphan*/  ipw_scan (struct ipw_softc*) ; 

__attribute__((used)) static void
ipw_scan_start(struct ieee80211com *ic)
{
	struct ipw_softc *sc = ic->ic_softc;

	IPW_LOCK(sc);
	ipw_scan(sc);
	IPW_UNLOCK(sc);
}