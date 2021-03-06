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
struct irq_data {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ICTLR_CPU_IEP_FIR_CLR ; 
 int /*<<< orphan*/  irq_chip_eoi_parent (struct irq_data*) ; 
 int /*<<< orphan*/  tegra_ictlr_write_mask (struct irq_data*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void tegra_eoi(struct irq_data *d)
{
	tegra_ictlr_write_mask(d, ICTLR_CPU_IEP_FIR_CLR);
	irq_chip_eoi_parent(d);
}