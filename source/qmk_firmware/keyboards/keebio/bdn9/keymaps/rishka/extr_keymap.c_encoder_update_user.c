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
typedef  int uint8_t ;

/* Variables and functions */
 int /*<<< orphan*/  KC_VOLD ; 
 int /*<<< orphan*/  KC_VOLU ; 
 int /*<<< orphan*/  layer_off (int) ; 
 int /*<<< orphan*/  layer_on (int) ; 
 int layer_state ; 
 int /*<<< orphan*/  tap_code (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uprintf (char*,int) ; 

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
    else if (index == 1) {
        int mod = 0;
        if (clockwise) {
            mod = 1;
        } else {
            mod = -1;
        }
        int n = 2; //sizeof(PROGMEM);
        int new_layer = ((layer_state + mod) % n + n) % n;
        uprintf("new: %d\n", new_layer);
        layer_on(new_layer);
        for(int i=0; i < n; i++) {
            if (new_layer != i) {
                layer_off(i);
            }
        }
    }
}