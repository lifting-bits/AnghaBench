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
struct ifnet {struct alc_softc* if_softc; } ;
struct alc_softc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ALC_LOCK (struct alc_softc*) ; 
 int /*<<< orphan*/  ALC_UNLOCK (struct alc_softc*) ; 
 int alc_mediachange_locked (struct alc_softc*) ; 

__attribute__((used)) static int
alc_mediachange(struct ifnet *ifp)
{
	struct alc_softc *sc;
	int error;

	sc = ifp->if_softc;
	ALC_LOCK(sc);
	error = alc_mediachange_locked(sc);
	ALC_UNLOCK(sc);

	return (error);
}