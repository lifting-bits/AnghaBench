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
typedef  int u8 ;
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 scalar_t__ RGLV ; 
 scalar_t__ gpio_ba ; 
 int /*<<< orphan*/  gpio_lock ; 
 int inb (scalar_t__) ; 
 int /*<<< orphan*/  outb (int,scalar_t__) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void sch_gpio_resume_set(struct gpio_chip *gc,
				unsigned gpio_num, int val)
{
	u8 curr_vals;

	spin_lock(&gpio_lock);

	curr_vals = inb(gpio_ba + RGLV);

	if (val)
		outb(curr_vals | (1 << gpio_num), gpio_ba + RGLV);
	else
		outb((curr_vals & ~(1 << gpio_num)), gpio_ba + RGLV);

	spin_unlock(&gpio_lock);
}