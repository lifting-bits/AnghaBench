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
typedef  int /*<<< orphan*/  uint16_t ;

/* Variables and functions */
 int /*<<< orphan*/  KC_LGUI ; 
 int /*<<< orphan*/  PRESS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RELEASE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TAP (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void CMD(uint16_t keycode) {
  PRESS(KC_LGUI);
    TAP(keycode);
  RELEASE(KC_LGUI);
}