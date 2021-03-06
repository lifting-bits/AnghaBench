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
struct gpio_chip {unsigned int base; } ;

/* Variables and functions */
 int pinctrl_gpio_direction_output (unsigned int) ; 
 int /*<<< orphan*/  rockchip_gpio_set (struct gpio_chip*,unsigned int,int) ; 

__attribute__((used)) static int rockchip_gpio_direction_output(struct gpio_chip *gc,
					  unsigned offset, int value)
{
	rockchip_gpio_set(gc, offset, value);
	return pinctrl_gpio_direction_output(gc->base + offset);
}