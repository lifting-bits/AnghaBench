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
 int /*<<< orphan*/  layer_state_set_rgb (int) ; 
 int /*<<< orphan*/  rgblight_enable_noeeprom () ; 

void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom();
  layer_state_set_rgb(1); // Set layer 0 (bit 1) on
}