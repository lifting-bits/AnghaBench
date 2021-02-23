#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u_int32_t ;
struct qfq_if {int dummy; } ;
struct ifclassq {scalar_t__ ifcq_type; TYPE_1__* ifcq_disc_slots; struct qfq_if* ifcq_disc; } ;
struct if_ifclassq_stats {int /*<<< orphan*/  ifqs_qfq_stats; } ;
struct TYPE_2__ {int /*<<< orphan*/  qid; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  IFCQ_LOCK_ASSERT_HELD (struct ifclassq*) ; 
 size_t IFCQ_SC_MAX ; 
 scalar_t__ PKTSCHEDT_QFQ ; 
 int /*<<< orphan*/  VERIFY (int) ; 
 int qfq_get_class_stats (struct qfq_if*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

int
qfq_getqstats_ifclassq(struct ifclassq *ifq, u_int32_t slot,
    struct if_ifclassq_stats *ifqs)
{
	struct qfq_if *qif = ifq->ifcq_disc;

	IFCQ_LOCK_ASSERT_HELD(ifq);
	VERIFY(ifq->ifcq_type == PKTSCHEDT_QFQ);

	if (slot >= IFCQ_SC_MAX)
		return (EINVAL);

	return (qfq_get_class_stats(qif, ifq->ifcq_disc_slots[slot].qid,
	    &ifqs->ifqs_qfq_stats));
}