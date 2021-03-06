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
struct aq_vec_s {unsigned int tx_rings; int /*<<< orphan*/  napi; int /*<<< orphan*/  aq_hw; TYPE_1__* aq_hw_ops; struct aq_ring_s** ring; } ;
struct aq_ring_s {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* hw_ring_rx_stop ) (int /*<<< orphan*/ ,struct aq_ring_s*) ;int /*<<< orphan*/  (* hw_ring_tx_stop ) (int /*<<< orphan*/ ,struct aq_ring_s*) ;} ;

/* Variables and functions */
 size_t AQ_VEC_RX_ID ; 
 size_t AQ_VEC_TX_ID ; 
 int /*<<< orphan*/  napi_disable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,struct aq_ring_s*) ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ ,struct aq_ring_s*) ; 

void aq_vec_stop(struct aq_vec_s *self)
{
	struct aq_ring_s *ring = NULL;
	unsigned int i = 0U;

	for (i = 0U, ring = self->ring[0];
		self->tx_rings > i; ++i, ring = self->ring[i]) {
		self->aq_hw_ops->hw_ring_tx_stop(self->aq_hw,
						 &ring[AQ_VEC_TX_ID]);

		self->aq_hw_ops->hw_ring_rx_stop(self->aq_hw,
						 &ring[AQ_VEC_RX_ID]);
	}

	napi_disable(&self->napi);
}