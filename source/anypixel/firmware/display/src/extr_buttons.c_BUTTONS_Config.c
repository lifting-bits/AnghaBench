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
 int /*<<< orphan*/  BUTTONS_NUM ; 
 int /*<<< orphan*/  BUTTONS_POWER_AHB ; 
 int /*<<< orphan*/  CONFIG_pins (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ENABLE ; 
 int /*<<< orphan*/  RCC_AHBPeriphClockCmd (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pins_buttons ; 

void BUTTONS_Config(void) {
	// enable clock to the relevant IO PORT(s)
	RCC_AHBPeriphClockCmd(BUTTONS_POWER_AHB, ENABLE);

    CONFIG_pins(pins_buttons, BUTTONS_NUM);
}