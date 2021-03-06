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
 int /*<<< orphan*/  i2c_master_init () ; 
 int /*<<< orphan*/  matrix_master_OLED_init () ; 
 int /*<<< orphan*/  serial_master_init () ; 

__attribute__((used)) static void keyboard_master_setup(void) {
#ifdef USE_I2C
#ifdef SSD1306OLED
    matrix_master_OLED_init ();
#endif
#endif
#ifdef USE_MATRIX_I2C
    i2c_master_init();
#else
    serial_master_init();
#endif
}