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
 int /*<<< orphan*/  _set_gpio_direction (struct gpio_chip*,unsigned int,int) ; 
 int /*<<< orphan*/  gemini_gpio_set (struct gpio_chip*,unsigned int,int) ; 

__attribute__((used)) static int gemini_gpio_direction_output(struct gpio_chip *chip, unsigned offset,
					int value)
{
	_set_gpio_direction(chip, offset, 1);
	gemini_gpio_set(chip, offset, value);
	return 0;
}