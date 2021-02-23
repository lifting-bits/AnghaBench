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
typedef  int /*<<< orphan*/  uint8_t ;

/* Variables and functions */
 int /*<<< orphan*/  B0 ; 
 int /*<<< orphan*/  E6 ; 
 int /*<<< orphan*/  E7 ; 
 scalar_t__ IS_LED_ON (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  USB_LED_CAPS_LOCK ; 
 int /*<<< orphan*/  USB_LED_NUM_LOCK ; 
 int /*<<< orphan*/  USB_LED_SCROLL_LOCK ; 
 int /*<<< orphan*/  led_set_user (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writePinHigh (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writePinLow (int /*<<< orphan*/ ) ; 

void led_set_kb(uint8_t usb_led) {
    // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here
    if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
        writePinHigh(E7);
    } else {
        writePinLow(E7);
    }

    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        writePinHigh(B0);
    } else {
        writePinLow(B0);
    }

    if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
        writePinHigh(E6);
    } else {
        writePinLow(E6);
    }

    led_set_user(usb_led);
}