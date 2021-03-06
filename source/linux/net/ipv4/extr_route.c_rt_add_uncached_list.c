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
struct uncached_list {int /*<<< orphan*/  lock; int /*<<< orphan*/  head; } ;
struct rtable {int /*<<< orphan*/  rt_uncached; struct uncached_list* rt_uncached_list; } ;

/* Variables and functions */
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct uncached_list* raw_cpu_ptr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rt_uncached_list ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 

void rt_add_uncached_list(struct rtable *rt)
{
	struct uncached_list *ul = raw_cpu_ptr(&rt_uncached_list);

	rt->rt_uncached_list = ul;

	spin_lock_bh(&ul->lock);
	list_add_tail(&rt->rt_uncached, &ul->head);
	spin_unlock_bh(&ul->lock);
}