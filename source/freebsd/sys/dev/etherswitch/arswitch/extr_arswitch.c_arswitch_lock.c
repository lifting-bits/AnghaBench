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
struct arswitch_softc {int dummy; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  ARSWITCH_LOCK (struct arswitch_softc*) ; 
 int /*<<< orphan*/  ARSWITCH_LOCK_ASSERT (struct arswitch_softc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MA_NOTOWNED ; 
 struct arswitch_softc* device_get_softc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
arswitch_lock(device_t dev)
{
	struct arswitch_softc *sc = device_get_softc(dev);

	ARSWITCH_LOCK_ASSERT(sc, MA_NOTOWNED);
	ARSWITCH_LOCK(sc);
}