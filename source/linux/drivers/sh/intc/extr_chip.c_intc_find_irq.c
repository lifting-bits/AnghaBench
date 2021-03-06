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
struct intc_handle_int {unsigned int irq; scalar_t__ handle; } ;

/* Variables and functions */
 struct intc_handle_int* bsearch (struct intc_handle_int*,struct intc_handle_int*,unsigned int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  intc_handle_int_cmp ; 

__attribute__((used)) static struct intc_handle_int *intc_find_irq(struct intc_handle_int *hp,
					     unsigned int nr_hp,
					     unsigned int irq)
{
	struct intc_handle_int key;

	key.irq = irq;
	key.handle = 0;

	return bsearch(&key, hp, nr_hp, sizeof(*hp), intc_handle_int_cmp);
}