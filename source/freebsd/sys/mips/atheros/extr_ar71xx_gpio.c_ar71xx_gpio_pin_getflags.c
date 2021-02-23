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
typedef  scalar_t__ uint32_t ;
struct ar71xx_gpio_softc {int gpio_npins; TYPE_1__* gpio_pins; } ;
typedef  int /*<<< orphan*/  device_t ;
struct TYPE_2__ {scalar_t__ gp_pin; scalar_t__ gp_flags; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  GPIO_LOCK (struct ar71xx_gpio_softc*) ; 
 int /*<<< orphan*/  GPIO_UNLOCK (struct ar71xx_gpio_softc*) ; 
 struct ar71xx_gpio_softc* device_get_softc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
ar71xx_gpio_pin_getflags(device_t dev, uint32_t pin, uint32_t *flags)
{
	struct ar71xx_gpio_softc *sc = device_get_softc(dev);
	int i;

	for (i = 0; i < sc->gpio_npins; i++) {
		if (sc->gpio_pins[i].gp_pin == pin)
			break;
	}

	if (i >= sc->gpio_npins)
		return (EINVAL);

	GPIO_LOCK(sc);
	*flags = sc->gpio_pins[i].gp_flags;
	GPIO_UNLOCK(sc);

	return (0);
}