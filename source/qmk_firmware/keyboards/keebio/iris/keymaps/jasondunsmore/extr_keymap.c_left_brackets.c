#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int count; int /*<<< orphan*/  pressed; } ;
typedef  TYPE_1__ qk_tap_dance_state_t ;

/* Variables and functions */
 int /*<<< orphan*/  KC_9 ; 
 int /*<<< orphan*/  KC_LBRC ; 
 int /*<<< orphan*/  KC_LSFT ; 
 int /*<<< orphan*/  register_code (int /*<<< orphan*/ ) ; 

void left_brackets(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (!state->pressed) {
      register_code(KC_LSFT);
      register_code(KC_9);
    } else {
      register_code(KC_LSFT);
    }
  } else if (state->count == 2) {
    register_code(KC_LBRC);
  }
}