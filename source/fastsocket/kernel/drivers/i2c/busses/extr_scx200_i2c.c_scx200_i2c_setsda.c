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
 int /*<<< orphan*/  scx200_gpio_set (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  sda ; 

__attribute__((used)) static void scx200_i2c_setsda(void *data, int state)
{
	scx200_gpio_set(sda, state);
}