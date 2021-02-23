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
 int /*<<< orphan*/  pemu_forced_frame (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pemu_sound_stop () ; 

void pemu_loop_end(void)
{
	pemu_sound_stop();

	/* do one more frame for menu bg */
	pemu_forced_frame(0, 1);
}