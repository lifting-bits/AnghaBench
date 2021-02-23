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
 int /*<<< orphan*/  __raw_readl (unsigned long) ; 
 int /*<<< orphan*/  __raw_writel (int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  set_field (int /*<<< orphan*/ ,unsigned long,unsigned long) ; 

__attribute__((used)) static void write_32(unsigned long addr, unsigned long h, unsigned long data)
{
	__raw_writel(set_field(0, data, h), addr);
	(void)__raw_readl(addr);	/* Defeat write posting */
}