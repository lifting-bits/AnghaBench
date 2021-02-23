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
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 unsigned int TWL4030_GPIO_MAX ; 
 int /*<<< orphan*/  twl4030_led_set_value (unsigned int,int) ; 
 int /*<<< orphan*/  twl4030_set_gpio_dataout (unsigned int,int) ; 
 int twl4030_set_gpio_direction (unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int twl_direction_out(struct gpio_chip *chip, unsigned offset, int value)
{
	if (offset < TWL4030_GPIO_MAX) {
		twl4030_set_gpio_dataout(offset, value);
		return twl4030_set_gpio_direction(offset, 0);
	} else {
		twl4030_led_set_value(offset - TWL4030_GPIO_MAX, value);
		return 0;
	}
}