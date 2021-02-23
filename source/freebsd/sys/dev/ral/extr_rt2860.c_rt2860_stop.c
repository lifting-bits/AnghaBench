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
struct rt2860_softc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  RAL_LOCK (struct rt2860_softc*) ; 
 int /*<<< orphan*/  RAL_UNLOCK (struct rt2860_softc*) ; 
 int /*<<< orphan*/  rt2860_stop_locked (struct rt2860_softc*) ; 

__attribute__((used)) static void
rt2860_stop(void *arg)
{
	struct rt2860_softc *sc = arg;

	RAL_LOCK(sc);
	rt2860_stop_locked(sc);
	RAL_UNLOCK(sc);
}