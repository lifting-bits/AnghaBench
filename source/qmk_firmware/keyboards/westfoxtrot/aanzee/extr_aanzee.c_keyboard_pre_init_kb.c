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
 int /*<<< orphan*/  B2 ; 
 int /*<<< orphan*/  keyboard_pre_init_user () ; 
 int /*<<< orphan*/  setPinOutput (int /*<<< orphan*/ ) ; 

void keyboard_pre_init_kb(void) {

    // Call the keyboard pre init code.
    // Set our LED pins as output
    setPinOutput(B2);

    keyboard_pre_init_user();
}