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
 int /*<<< orphan*/  ALT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  KC_LEFT ; 
 int /*<<< orphan*/  print (char*) ; 

void VIM_BACK(void) {
  print("\e[31mb\e[0m");
  ALT(KC_LEFT);
}