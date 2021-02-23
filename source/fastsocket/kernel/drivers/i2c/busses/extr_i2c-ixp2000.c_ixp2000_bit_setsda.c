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

/* Variables and functions */
 int /*<<< orphan*/  GPIO_IN ; 
 int /*<<< orphan*/  GPIO_OUT ; 
 int /*<<< orphan*/  gpio_line_config (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ixp2000_sda_pin (void*) ; 

__attribute__((used)) static void ixp2000_bit_setsda(void *data, int val)
{
	if (val) {
		gpio_line_config(ixp2000_sda_pin(data), GPIO_IN);
	} else {
		gpio_line_config(ixp2000_sda_pin(data), GPIO_OUT);
	}
}