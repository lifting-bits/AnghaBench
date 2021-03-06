#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct clk {TYPE_1__* parent; int /*<<< orphan*/  node; scalar_t__ refcount; scalar_t__ usage; } ;
struct TYPE_2__ {int /*<<< orphan*/  refcount; } ;

/* Variables and functions */
 int EBUSY ; 
 int /*<<< orphan*/  clk_lock ; 
 int /*<<< orphan*/  list_del (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

int clk_unregister(struct clk *clk)
{
	int ret = 0;
	unsigned long flags;

	spin_lock_irqsave(&clk_lock, flags);

	if (clk->usage || clk->refcount)
		ret = -EBUSY;
	else
		list_del(&clk->node);

	if (clk->parent)
		--clk->parent->refcount;

	spin_unlock_irqrestore(&clk_lock, flags);

	return ret;
}