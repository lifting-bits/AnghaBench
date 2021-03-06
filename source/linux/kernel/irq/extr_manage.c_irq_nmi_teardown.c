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
struct irq_desc {int dummy; } ;
struct irq_data {struct irq_chip* chip; } ;
struct irq_chip {int /*<<< orphan*/  (* irq_nmi_teardown ) (struct irq_data*) ;} ;

/* Variables and functions */
 struct irq_data* irq_desc_get_irq_data (struct irq_desc*) ; 
 int /*<<< orphan*/  stub1 (struct irq_data*) ; 

__attribute__((used)) static void irq_nmi_teardown(struct irq_desc *desc)
{
	struct irq_data *d = irq_desc_get_irq_data(desc);
	struct irq_chip *c = d->chip;

	if (c->irq_nmi_teardown)
		c->irq_nmi_teardown(d);
}