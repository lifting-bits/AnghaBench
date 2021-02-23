#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  et_min_period; } ;
struct xentimer_softc {TYPE_1__ et; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 struct xentimer_softc* device_get_softc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xentimer_et_start (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
xentimer_percpu_resume(void *arg)
{
	device_t dev = (device_t) arg;
	struct xentimer_softc *sc = device_get_softc(dev);

	xentimer_et_start(&sc->et, sc->et.et_min_period, 0);
}