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
typedef  int /*<<< orphan*/  qk_tap_dance_state_t ;

/* Variables and functions */
#define  DOUBLE_SINGLE_TAP 131 
 int /*<<< orphan*/  KC_ESC ; 
#define  NONE_NONE 130 
#define  SINGLE_HOLD 129 
#define  SINGLE_TAP 128 
 int /*<<< orphan*/  _FN ; 
 int /*<<< orphan*/  layer_off (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  register_code16 (int /*<<< orphan*/ ) ; 
 int sstate ; 
 int td_state ; 
 int /*<<< orphan*/  unregister_code16 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  update_led_state_c () ; 

void lesc_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(KC_ESC);
      break;
    case SINGLE_HOLD:
      layer_off(_FN);
      if (sstate == false) {
        register_code16(KC_ESC);
        unregister_code16(KC_ESC);
      }
      break;
    case DOUBLE_SINGLE_TAP:
      break;
    case NONE_NONE:
      break;
  }
  td_state = NONE_NONE;
  update_led_state_c();
}