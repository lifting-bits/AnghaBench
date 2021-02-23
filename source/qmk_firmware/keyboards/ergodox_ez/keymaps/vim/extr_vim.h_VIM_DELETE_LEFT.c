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
 int /*<<< orphan*/  CMD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  KC_LEFT ; 
 int /*<<< orphan*/  KC_NO ; 
 int /*<<< orphan*/  KC_X ; 
 int /*<<< orphan*/  SHIFT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  VIM_LEADER (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  print (char*) ; 

void VIM_DELETE_LEFT(void) {
  print("\e[31mh\e[0m");
  VIM_LEADER(KC_NO);
  SHIFT(KC_LEFT);
  CMD(KC_X);
}