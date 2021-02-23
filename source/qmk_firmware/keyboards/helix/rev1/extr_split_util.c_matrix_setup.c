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
 int /*<<< orphan*/  has_usb () ; 
 int /*<<< orphan*/  keyboard_slave_loop () ; 
 int /*<<< orphan*/  split_keyboard_setup () ; 

void matrix_setup(void) {
    split_keyboard_setup();

    if (!has_usb()) {
        keyboard_slave_loop();
    }
}