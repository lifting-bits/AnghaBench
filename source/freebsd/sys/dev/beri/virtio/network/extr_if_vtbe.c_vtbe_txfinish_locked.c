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
struct vtbe_softc {struct ifnet* ifp; } ;
struct ifnet {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  VTBE_ASSERT_LOCKED (struct vtbe_softc*) ; 

__attribute__((used)) static void
vtbe_txfinish_locked(struct vtbe_softc *sc)
{
	struct ifnet *ifp;

	VTBE_ASSERT_LOCKED(sc);

	ifp = sc->ifp;
}