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
 int /*<<< orphan*/  SLAVE_I2C_ADDRESS ; 
 int /*<<< orphan*/  i2c_slave_init (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  serial_slave_init () ; 
 int /*<<< orphan*/  timer_init () ; 

__attribute__((used)) static void keyboard_slave_setup(void) {
  timer_init();
#ifdef USE_I2C
    i2c_slave_init(SLAVE_I2C_ADDRESS);
#else
    serial_slave_init();
#endif
}