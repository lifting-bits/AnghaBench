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
struct wahc {unsigned int rpipes; int /*<<< orphan*/  rpipe_bm_lock; int /*<<< orphan*/  rpipe_bm; } ;

/* Variables and functions */
 unsigned int find_next_zero_bit (int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  set_bit (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static unsigned rpipe_get_idx(struct wahc *wa, unsigned rpipe_idx)
{
	unsigned long flags;

	spin_lock_irqsave(&wa->rpipe_bm_lock, flags);
	rpipe_idx = find_next_zero_bit(wa->rpipe_bm, wa->rpipes, rpipe_idx);
	if (rpipe_idx < wa->rpipes)
		set_bit(rpipe_idx, wa->rpipe_bm);
	spin_unlock_irqrestore(&wa->rpipe_bm_lock, flags);

	return rpipe_idx;
}