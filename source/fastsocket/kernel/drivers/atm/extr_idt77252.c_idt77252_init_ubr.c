#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct vc_map {int init_er; int lacr; int max_er; int /*<<< orphan*/  class; TYPE_1__* estimator; int /*<<< orphan*/  lock; } ;
struct idt77252_dev {int link_pcr; } ;
struct atm_vcc {int dummy; } ;
struct atm_qos {int /*<<< orphan*/  txtp; } ;
struct TYPE_3__ {int /*<<< orphan*/  timer; } ;

/* Variables and functions */
 int /*<<< orphan*/  SCHED_UBR ; 
 int atm_pcr_goal (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  del_timer (int /*<<< orphan*/ *) ; 
 TYPE_1__* idt77252_init_est (struct vc_map*,int) ; 
 int idt77252_rate_logindex (struct idt77252_dev*,int) ; 
 int /*<<< orphan*/  kfree (TYPE_1__*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static int
idt77252_init_ubr(struct idt77252_dev *card, struct vc_map *vc,
		  struct atm_vcc *vcc, struct atm_qos *qos)
{
	unsigned long flags;
	int tcr;

	spin_lock_irqsave(&vc->lock, flags);
	if (vc->estimator) {
		del_timer(&vc->estimator->timer);
		kfree(vc->estimator);
		vc->estimator = NULL;
	}
	spin_unlock_irqrestore(&vc->lock, flags);

	tcr = atm_pcr_goal(&qos->txtp);
	if (tcr == 0)
		tcr = card->link_pcr;

	vc->estimator = idt77252_init_est(vc, tcr);

	vc->class = SCHED_UBR;
	vc->init_er = idt77252_rate_logindex(card, tcr);
	vc->lacr = vc->init_er;
	if (tcr < 0)
		vc->max_er = vc->init_er;
	else
		vc->max_er = 0xff;

	return 0;
}