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
typedef  int /*<<< orphan*/  u32 ;
struct crypto4xx_device {scalar_t__ gdr_tail; scalar_t__ gdr_head; TYPE_1__* core_dev; } ;
struct TYPE_2__ {int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 scalar_t__ PPC4XX_LAST_GD ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static u32 crypto4xx_put_gd_to_gdr(struct crypto4xx_device *dev)
{
	unsigned long flags;

	spin_lock_irqsave(&dev->core_dev->lock, flags);
	if (dev->gdr_tail == dev->gdr_head) {
		spin_unlock_irqrestore(&dev->core_dev->lock, flags);
		return 0;
	}

	if (dev->gdr_tail != PPC4XX_LAST_GD)
		dev->gdr_tail++;
	else
		dev->gdr_tail = 0;

	spin_unlock_irqrestore(&dev->core_dev->lock, flags);

	return 0;
}