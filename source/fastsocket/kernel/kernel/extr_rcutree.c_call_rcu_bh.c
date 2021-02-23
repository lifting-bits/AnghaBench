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
struct rcu_head {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __call_rcu (struct rcu_head*,void (*) (struct rcu_head*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rcu_bh_state ; 

void call_rcu_bh(struct rcu_head *head, void (*func)(struct rcu_head *rcu))
{
	__call_rcu(head, func, &rcu_bh_state);
}