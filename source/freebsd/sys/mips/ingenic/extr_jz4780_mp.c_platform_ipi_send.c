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
 int /*<<< orphan*/  mips_wr_xburst_mbox0 (int) ; 
 int /*<<< orphan*/  mips_wr_xburst_mbox1 (int) ; 

void
platform_ipi_send(int cpuid)
{

	if (cpuid == 0)
		mips_wr_xburst_mbox0(1);
	else
		mips_wr_xburst_mbox1(1);
}