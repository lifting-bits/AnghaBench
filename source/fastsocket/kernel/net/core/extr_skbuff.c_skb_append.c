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
struct sk_buff_head {int /*<<< orphan*/  lock; } ;
struct sk_buff {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __skb_queue_after (struct sk_buff_head*,struct sk_buff*,struct sk_buff*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

void skb_append(struct sk_buff *old, struct sk_buff *newsk, struct sk_buff_head *list)
{
	unsigned long flags;

	spin_lock_irqsave(&list->lock, flags);
	__skb_queue_after(list, old, newsk);
	spin_unlock_irqrestore(&list->lock, flags);
}