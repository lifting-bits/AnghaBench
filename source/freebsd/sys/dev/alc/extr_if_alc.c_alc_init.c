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
struct alc_softc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ALC_LOCK (struct alc_softc*) ; 
 int /*<<< orphan*/  ALC_UNLOCK (struct alc_softc*) ; 
 int /*<<< orphan*/  alc_init_locked (struct alc_softc*) ; 

__attribute__((used)) static void
alc_init(void *xsc)
{
	struct alc_softc *sc;

	sc = (struct alc_softc *)xsc;
	ALC_LOCK(sc);
	alc_init_locked(sc);
	ALC_UNLOCK(sc);
}