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
struct mv_rtc_softc {int /*<<< orphan*/  res; int /*<<< orphan*/  mutex; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  bus_release_resources (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct mv_rtc_softc* device_get_softc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtx_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  res_spec ; 

__attribute__((used)) static int
mv_rtc_detach(device_t dev)
{
	struct mv_rtc_softc *sc;

	sc = device_get_softc(dev);

	mtx_destroy(&sc->mutex);

	bus_release_resources(dev, res_spec, sc->res);

	return (0);
}