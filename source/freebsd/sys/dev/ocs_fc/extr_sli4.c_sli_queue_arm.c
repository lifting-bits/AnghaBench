#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint32_t ;
struct TYPE_5__ {int /*<<< orphan*/  os; } ;
typedef  TYPE_1__ sli4_t ;
struct TYPE_6__ {int type; int /*<<< orphan*/  lock; int /*<<< orphan*/  n_posted; int /*<<< orphan*/  doorbell_offset; int /*<<< orphan*/  doorbell_rset; int /*<<< orphan*/  id; } ;
typedef  TYPE_2__ sli4_queue_t ;
typedef  int /*<<< orphan*/  int32_t ;

/* Variables and functions */
 int /*<<< orphan*/ * SLI_QNAME ; 
#define  SLI_QTYPE_CQ 129 
#define  SLI_QTYPE_EQ 128 
 int /*<<< orphan*/  ocs_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ocs_log_test (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ocs_reg_write32 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ocs_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sli_cq_doorbell (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sli_eq_doorbell (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int32_t
sli_queue_arm(sli4_t *sli4, sli4_queue_t *q, uint8_t arm)
{
	uint32_t	val = 0;

	ocs_lock(&q->lock);

	switch (q->type) {
	case SLI_QTYPE_EQ:
		val = sli_eq_doorbell(q->n_posted, q->id, arm);
		ocs_reg_write32(sli4->os, q->doorbell_rset, q->doorbell_offset, val);
		q->n_posted = 0;
		break;
	case SLI_QTYPE_CQ:
		val = sli_cq_doorbell(q->n_posted, q->id, arm);
		ocs_reg_write32(sli4->os, q->doorbell_rset, q->doorbell_offset, val);
		q->n_posted = 0;
		break;
	default:
		ocs_log_test(sli4->os, "should only be used for EQ/CQ, not %s\n",
			     SLI_QNAME[q->type]);
	}

	ocs_unlock(&q->lock);

	return 0;
}