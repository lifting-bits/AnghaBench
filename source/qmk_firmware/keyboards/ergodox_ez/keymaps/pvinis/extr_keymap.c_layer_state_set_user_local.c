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
#define  LR_KBCTL 130 
#define  LR_SYMBOL 129 
#define  LR_SYSCTL 128 
 int biton32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ergodox_right_led_1_off () ; 
 int /*<<< orphan*/  ergodox_right_led_1_on () ; 
 int /*<<< orphan*/  ergodox_right_led_2_off () ; 
 int /*<<< orphan*/  ergodox_right_led_2_on () ; 
 int /*<<< orphan*/  ergodox_right_led_3_off () ; 
 int /*<<< orphan*/  ergodox_right_led_3_on () ; 

uint32_t layer_state_set_user_local(uint32_t state) {
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (biton32(state)) {
  case LR_SYSCTL:
    ergodox_right_led_3_on(); // blue
    break;
  case LR_KBCTL:
    ergodox_right_led_1_on(); // red
    break;
  case LR_SYMBOL:
    ergodox_right_led_2_on(); // green
    break;
  default: break;
  }
  return state;
}