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
 scalar_t__ IS_LED_ON (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  USB_LED_CAPS_LOCK ; 
 int /*<<< orphan*/  host_keyboard_leds () ; 
 int /*<<< orphan*/  rgb_matrix_set_color (int,int,int,int) ; 

__attribute__ ((weak))

void rgb_matrix_indicators_user(void)
{
    if (IS_LED_ON(host_keyboard_leds(), USB_LED_CAPS_LOCK))
    {
        rgb_matrix_set_color(30, 0xFF, 0x00, 0x00);
    }
}