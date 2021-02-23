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
struct gpio_bank {int dummy; } ;

/* Variables and functions */
 unsigned int IH_GPIO_BASE ; 
 int /*<<< orphan*/  IRQ_TYPE_NONE ; 
 int /*<<< orphan*/  _set_gpio_irqenable (struct gpio_bank*,unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _set_gpio_triggering (struct gpio_bank*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_gpio_index (unsigned int) ; 
 struct gpio_bank* get_irq_chip_data (unsigned int) ; 

__attribute__((used)) static void gpio_mask_irq(unsigned int irq)
{
	unsigned int gpio = irq - IH_GPIO_BASE;
	struct gpio_bank *bank = get_irq_chip_data(irq);

	_set_gpio_irqenable(bank, gpio, 0);
	_set_gpio_triggering(bank, get_gpio_index(gpio), IRQ_TYPE_NONE);
}