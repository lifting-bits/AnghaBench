#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  qk_tap_dance_state_t ;
struct TYPE_4__ {int state; } ;
struct TYPE_3__ {int /*<<< orphan*/  status; } ;

/* Variables and functions */
#define  DOUBLE_HOLD 128 
 int /*<<< orphan*/  ENABLED ; 
 int /*<<< orphan*/  KC_LALT ; 
 int /*<<< orphan*/  KC_LGUI ; 
 size_t RBW_LSPR ; 
 int cur_dance (int /*<<< orphan*/ *) ; 
 TYPE_2__ lsprtap_state ; 
 TYPE_1__* rbw_led_keys ; 
 int /*<<< orphan*/  register_code (int /*<<< orphan*/ ) ; 

void dance_lspr_finished(qk_tap_dance_state_t *state, void *user_data) {
  lsprtap_state.state = cur_dance(state);

  switch (lsprtap_state.state) {
  case DOUBLE_HOLD:
    rbw_led_keys[RBW_LSPR].status = ENABLED;
    register_code(KC_LALT);
    break;
  default:
    register_code(KC_LGUI);
    break;
  }
}