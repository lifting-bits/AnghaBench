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
typedef  int /*<<< orphan*/  uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  disable_intr_times ; 
 int /*<<< orphan*/  ets_printf (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_get_level (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_intr_disable (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void gpio_isr_level_handler(void* arg)
{
    uint32_t gpio_num = (uint32_t) arg;
    disable_intr_times++;
    ets_printf("GPIO[%d] intr, val: %d, disable_intr_times = %d\n", gpio_num, gpio_get_level(gpio_num), disable_intr_times);
    gpio_intr_disable(gpio_num);
}