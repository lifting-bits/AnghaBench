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
struct ntb_dev {int /*<<< orphan*/  ctx_lock; int /*<<< orphan*/  ctx; TYPE_1__* ctx_ops; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* msg_event ) (int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ) ; 

void ntb_msg_event(struct ntb_dev *ntb)
{
	unsigned long irqflags;

	spin_lock_irqsave(&ntb->ctx_lock, irqflags);
	{
		if (ntb->ctx_ops && ntb->ctx_ops->msg_event)
			ntb->ctx_ops->msg_event(ntb->ctx);
	}
	spin_unlock_irqrestore(&ntb->ctx_lock, irqflags);
}