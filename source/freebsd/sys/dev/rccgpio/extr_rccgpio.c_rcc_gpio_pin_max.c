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
struct rcc_gpio_softc {int sc_gpio_npins; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 struct rcc_gpio_softc* device_get_softc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
rcc_gpio_pin_max(device_t dev, int *maxpin)
{
	struct rcc_gpio_softc *sc;

	sc = device_get_softc(dev);
	*maxpin = sc->sc_gpio_npins - 1;

	return (0);
}