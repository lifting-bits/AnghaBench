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
struct usb_ether {int dummy; } ;
struct mos_softc {int /*<<< orphan*/  mos_link; } ;
struct mii_data {int mii_media_status; int /*<<< orphan*/  mii_media_active; } ;

/* Variables and functions */
 struct mii_data* GET_MII (struct mos_softc*) ; 
 int IFM_ACTIVE ; 
 scalar_t__ IFM_NONE ; 
 scalar_t__ IFM_SUBTYPE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MA_OWNED ; 
 int /*<<< orphan*/  MOS_DPRINTFN (char*) ; 
 int /*<<< orphan*/  MOS_LOCK_ASSERT (struct mos_softc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mii_tick (struct mii_data*) ; 
 int /*<<< orphan*/  mos_start (struct usb_ether*) ; 
 struct mos_softc* uether_getsc (struct usb_ether*) ; 

__attribute__((used)) static void
mos_tick(struct usb_ether *ue)
{
	struct mos_softc *sc = uether_getsc(ue);
	struct mii_data *mii = GET_MII(sc);

	MOS_LOCK_ASSERT(sc, MA_OWNED);

	mii_tick(mii);
	if (!sc->mos_link && mii->mii_media_status & IFM_ACTIVE &&
	    IFM_SUBTYPE(mii->mii_media_active) != IFM_NONE) {
		MOS_DPRINTFN("got link");
		sc->mos_link++;
		mos_start(ue);
	}
}