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
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;

/* Variables and functions */
 int /*<<< orphan*/  OMAP1_IO_ADDRESS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OMAP2_IO_ADDRESS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_readw (int /*<<< orphan*/ ) ; 
 scalar_t__ cpu_class_is_omap1 () ; 

u16 omap_readw(u32 pa)
{
	if (cpu_class_is_omap1())
		return __raw_readw(OMAP1_IO_ADDRESS(pa));
	else
		return __raw_readw(OMAP2_IO_ADDRESS(pa));
}