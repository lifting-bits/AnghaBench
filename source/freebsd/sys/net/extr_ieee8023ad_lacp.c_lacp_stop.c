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
struct lagg_softc {int dummy; } ;
struct lacp_softc {int /*<<< orphan*/  lsc_callout; int /*<<< orphan*/  lsc_transit_callout; } ;

/* Variables and functions */
 int /*<<< orphan*/  LACP_LOCK (struct lacp_softc*) ; 
 struct lacp_softc* LACP_SOFTC (struct lagg_softc*) ; 
 int /*<<< orphan*/  LACP_UNLOCK (struct lacp_softc*) ; 
 int /*<<< orphan*/  callout_stop (int /*<<< orphan*/ *) ; 

void
lacp_stop(struct lagg_softc *sc)
{
	struct lacp_softc *lsc = LACP_SOFTC(sc);

	LACP_LOCK(lsc);
	callout_stop(&lsc->lsc_transit_callout);
	callout_stop(&lsc->lsc_callout);
	LACP_UNLOCK(lsc);
}