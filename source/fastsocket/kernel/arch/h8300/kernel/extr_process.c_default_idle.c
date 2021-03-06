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
 int /*<<< orphan*/  local_irq_disable () ; 
 int /*<<< orphan*/  local_irq_enable () ; 
 int /*<<< orphan*/  need_resched () ; 

__attribute__((used)) static void default_idle(void)
{
	local_irq_disable();
	if (!need_resched()) {
		local_irq_enable();
		/* XXX: race here! What if need_resched() gets set now? */
		__asm__("sleep");
	} else
		local_irq_enable();
}