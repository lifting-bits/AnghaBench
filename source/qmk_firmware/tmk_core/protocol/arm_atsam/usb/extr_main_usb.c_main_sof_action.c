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
 int /*<<< orphan*/  udd_get_frame_number () ; 
 int /*<<< orphan*/  ui_process (int /*<<< orphan*/ ) ; 

void main_sof_action(void) { ui_process(udd_get_frame_number()); }