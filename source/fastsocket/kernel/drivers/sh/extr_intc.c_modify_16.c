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
 int /*<<< orphan*/  __raw_readw (unsigned long) ; 
 int /*<<< orphan*/  __raw_writew (int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  set_field (int /*<<< orphan*/ ,unsigned long,unsigned long) ; 

__attribute__((used)) static void modify_16(unsigned long addr, unsigned long h, unsigned long data)
{
	unsigned long flags;
	local_irq_save(flags);
	__raw_writew(set_field(__raw_readw(addr), data, h), addr);
	(void)__raw_readw(addr);	/* Defeat write posting */
	local_irq_restore(flags);
}