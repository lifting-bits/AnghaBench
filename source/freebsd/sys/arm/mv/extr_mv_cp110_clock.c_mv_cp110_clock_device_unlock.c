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
struct mv_cp110_clock_softc {int /*<<< orphan*/  mtx; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 struct mv_cp110_clock_softc* device_get_softc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtx_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
mv_cp110_clock_device_unlock(device_t dev)
{
	struct mv_cp110_clock_softc *sc;

	sc = device_get_softc(dev);
	mtx_unlock(&sc->mtx);
}