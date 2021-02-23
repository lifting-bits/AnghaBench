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
struct a37x0_gpio_softc {int sc_npins; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 struct a37x0_gpio_softc* device_get_softc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
a37x0_gpio_pin_max(device_t dev, int *maxpin)
{
	struct a37x0_gpio_softc *sc;

	sc = device_get_softc(dev);
	*maxpin = sc->sc_npins - 1;

	return (0);
}