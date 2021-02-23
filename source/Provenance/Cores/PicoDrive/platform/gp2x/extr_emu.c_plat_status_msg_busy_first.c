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
 int /*<<< orphan*/  g_screen_ptr ; 
 int /*<<< orphan*/  gp2x_memcpy_all_buffers (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  plat_status_msg_busy_next (char const*) ; 

void plat_status_msg_busy_first(const char *msg)
{
	gp2x_memcpy_all_buffers(g_screen_ptr, 0, 320*240*2);
	plat_status_msg_busy_next(msg);
}