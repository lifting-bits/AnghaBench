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
 int /*<<< orphan*/  IN_KeyDown (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * in_buttons ; 

void IN_Button5Down(void) {IN_KeyDown(&in_buttons[5]);}