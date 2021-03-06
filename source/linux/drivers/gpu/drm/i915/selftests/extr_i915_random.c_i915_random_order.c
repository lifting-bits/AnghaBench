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
struct rnd_state {int dummy; } ;

/* Variables and functions */
 int GFP_KERNEL ; 
 int __GFP_NOWARN ; 
 int __GFP_RETRY_MAYFAIL ; 
 int /*<<< orphan*/  i915_random_reorder (unsigned int*,unsigned int,struct rnd_state*) ; 
 unsigned int* kmalloc_array (unsigned int,int,int) ; 

unsigned int *i915_random_order(unsigned int count, struct rnd_state *state)
{
	unsigned int *order, i;

	order = kmalloc_array(count, sizeof(*order),
			      GFP_KERNEL | __GFP_RETRY_MAYFAIL | __GFP_NOWARN);
	if (!order)
		return order;

	for (i = 0; i < count; i++)
		order[i] = i;

	i915_random_reorder(order, count, state);
	return order;
}