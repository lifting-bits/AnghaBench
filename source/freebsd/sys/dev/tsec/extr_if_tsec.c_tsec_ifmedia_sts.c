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
struct tsec_softc {struct mii_data* tsec_mii; } ;
struct mii_data {int /*<<< orphan*/  mii_media_status; int /*<<< orphan*/  mii_media_active; } ;
struct ifnet {struct tsec_softc* if_softc; } ;
struct ifmediareq {int /*<<< orphan*/  ifm_status; int /*<<< orphan*/  ifm_active; } ;

/* Variables and functions */
 int /*<<< orphan*/  TSEC_TRANSMIT_LOCK (struct tsec_softc*) ; 
 int /*<<< orphan*/  TSEC_TRANSMIT_UNLOCK (struct tsec_softc*) ; 
 int /*<<< orphan*/  mii_pollstat (struct mii_data*) ; 

__attribute__((used)) static void
tsec_ifmedia_sts(struct ifnet *ifp, struct ifmediareq *ifmr)
{
	struct tsec_softc *sc = ifp->if_softc;
	struct mii_data *mii;

	TSEC_TRANSMIT_LOCK(sc);

	mii = sc->tsec_mii;
	mii_pollstat(mii);

	ifmr->ifm_active = mii->mii_media_active;
	ifmr->ifm_status = mii->mii_media_status;

	TSEC_TRANSMIT_UNLOCK(sc);
}