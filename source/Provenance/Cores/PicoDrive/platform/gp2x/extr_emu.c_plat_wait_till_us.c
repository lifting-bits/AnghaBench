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
 unsigned int plat_get_ticks_us () ; 
 int /*<<< orphan*/  spend_cycles (int) ; 

void plat_wait_till_us(unsigned int us_to)
{
	unsigned int now;

	spend_cycles(1024);
	now = plat_get_ticks_us();

	while ((signed int)(us_to - now) > 512)
	{
		spend_cycles(1024);
		now = plat_get_ticks_us();
	}
}