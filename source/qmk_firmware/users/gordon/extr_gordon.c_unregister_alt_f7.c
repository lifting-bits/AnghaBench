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
 int /*<<< orphan*/  KC_F7 ; 
 int /*<<< orphan*/  KC_LALT ; 
 int /*<<< orphan*/  unregister_code (int /*<<< orphan*/ ) ; 

void unregister_alt_f7 (void) {
  unregister_code (KC_LALT);
  unregister_code (KC_F7);
}