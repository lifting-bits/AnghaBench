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
struct TYPE_2__ {struct isl12xx_softc* ich_arg; int /*<<< orphan*/  ich_func; } ;
struct isl12xx_softc {TYPE_1__ init_hook; int /*<<< orphan*/  dev; int /*<<< orphan*/  busdev; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int ENOMEM ; 
 scalar_t__ config_intrhook_establish (TYPE_1__*) ; 
 int /*<<< orphan*/  device_get_parent (int /*<<< orphan*/ ) ; 
 struct isl12xx_softc* device_get_softc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  isl12xx_init ; 

__attribute__((used)) static int
isl12xx_attach(device_t dev)
{
	struct isl12xx_softc *sc = device_get_softc(dev);

	sc->dev = dev;
	sc->busdev = device_get_parent(sc->dev);

	/*
	 * Chip init must wait until interrupts are enabled.  Often i2c access
	 * works only when the interrupts are available.
	 */
	sc->init_hook.ich_func = isl12xx_init;
	sc->init_hook.ich_arg = sc;
	if (config_intrhook_establish(&sc->init_hook) != 0)
		return (ENOMEM);

	return (0);
}