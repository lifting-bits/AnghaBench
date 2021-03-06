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
struct mthca_eq {int /*<<< orphan*/  eqn; int /*<<< orphan*/  cons_index; struct mthca_dev* dev; } ;
struct mthca_dev {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  mthca_eq_int (struct mthca_dev*,struct mthca_eq*) ; 
 int /*<<< orphan*/  tavor_eq_req_not (struct mthca_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tavor_set_eq_ci (struct mthca_dev*,struct mthca_eq*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static irqreturn_t mthca_tavor_msi_x_interrupt(int irq, void *eq_ptr)
{
	struct mthca_eq  *eq  = eq_ptr;
	struct mthca_dev *dev = eq->dev;

	mthca_eq_int(dev, eq);
	tavor_set_eq_ci(dev, eq, eq->cons_index);
	tavor_eq_req_not(dev, eq->eqn);

	/* MSI-X vectors always belong to us */
	return IRQ_HANDLED;
}