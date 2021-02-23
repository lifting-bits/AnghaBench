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
struct TYPE_3__ {int count; } ;
typedef  TYPE_1__ qk_tap_dance_state_t ;

/* Variables and functions */
 int /*<<< orphan*/  KC_LSFT ; 
 int /*<<< orphan*/  MOD_LSFT ; 
 int /*<<< orphan*/  NM_MODE ; 
 int /*<<< orphan*/  layer_on (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  register_code (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_oneshot_mods (int /*<<< orphan*/ ) ; 

void dance_SFT_NM_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
	register_code (KC_LSFT);
	set_oneshot_mods(MOD_LSFT);
  } else {
    register_code (KC_LSFT);
	layer_on(NM_MODE);
  }
}