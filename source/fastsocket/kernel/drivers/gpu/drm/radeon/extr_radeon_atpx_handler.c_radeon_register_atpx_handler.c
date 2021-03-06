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
 int radeon_atpx_detect () ; 
 int /*<<< orphan*/  radeon_atpx_handler ; 
 int /*<<< orphan*/  vga_switcheroo_register_handler (int /*<<< orphan*/ *) ; 

void radeon_register_atpx_handler(void)
{
	bool r;

	/* detect if we have any ATPX + 2 VGA in the system */
	r = radeon_atpx_detect();
	if (!r)
		return;

	vga_switcheroo_register_handler(&radeon_atpx_handler);
}