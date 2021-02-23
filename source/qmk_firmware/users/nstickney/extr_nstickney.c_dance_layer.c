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
 int /*<<< orphan*/  KC_APP ; 
 int /*<<< orphan*/  NUMP ; 
 int /*<<< orphan*/  SYMB ; 
 int /*<<< orphan*/  SYSH ; 
 int /*<<< orphan*/  layer_invert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tap_code (int /*<<< orphan*/ ) ; 

void dance_layer (qk_tap_dance_state_t *state, void *user_data) {
	switch (state -> count) {
		case 1: tap_code(KC_APP); break;
		case 2: layer_invert(NUMP); break;
		case 3: layer_invert(SYMB); break;
		case 4: layer_invert(SYSH); break;
		default: break;
	}
}