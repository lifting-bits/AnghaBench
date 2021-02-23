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
 int /*<<< orphan*/  KC_LSHIFT ; 
 int /*<<< orphan*/  KC_SPACE ; 
 int /*<<< orphan*/  register_code (int /*<<< orphan*/ ) ; 
 scalar_t__ shift_count ; 
 int /*<<< orphan*/  tap_code (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  unregister_code (int /*<<< orphan*/ ) ; 

void press_space(void) {
  if(shift_count > 0) unregister_code (KC_LSHIFT);
  tap_code(KC_SPACE);
  if(shift_count > 0) register_code (KC_LSHIFT);
}