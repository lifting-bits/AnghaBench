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
 int /*<<< orphan*/  KC_LCTRL ; 
 int /*<<< orphan*/  KC_LSFT ; 
 int /*<<< orphan*/  unregister_code (int /*<<< orphan*/ ) ; 

void unregister_ctrl_shift (void) {
  unregister_code (KC_LSFT);
  unregister_code (KC_LCTRL);
}