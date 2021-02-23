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
struct ag71xx_ring {scalar_t__ descs_dma; void* descs_cpu; int /*<<< orphan*/  order; int /*<<< orphan*/ * buf; } ;
struct ag71xx {struct ag71xx_ring rx_ring; struct ag71xx_ring tx_ring; } ;

/* Variables and functions */
 int AG71XX_DESC_SIZE ; 
 size_t BIT (int /*<<< orphan*/ ) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int ag71xx_ring_rx_init (struct ag71xx*) ; 
 int /*<<< orphan*/  ag71xx_ring_tx_init (struct ag71xx*) ; 
 void* dma_alloc_coherent (int /*<<< orphan*/ *,int,scalar_t__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * kzalloc (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ag71xx_rings_init(struct ag71xx *ag)
{
	struct ag71xx_ring *tx = &ag->tx_ring;
	struct ag71xx_ring *rx = &ag->rx_ring;
	int ring_size = BIT(tx->order) + BIT(rx->order);
	int tx_size = BIT(tx->order);

	tx->buf = kzalloc(ring_size * sizeof(*tx->buf), GFP_KERNEL);
	if (!tx->buf)
		return -ENOMEM;

	tx->descs_cpu = dma_alloc_coherent(NULL, ring_size * AG71XX_DESC_SIZE,
					   &tx->descs_dma, GFP_ATOMIC);
	if (!tx->descs_cpu) {
		kfree(tx->buf);
		tx->buf = NULL;
		return -ENOMEM;
	}

	rx->buf = &tx->buf[BIT(tx->order)];
	rx->descs_cpu = ((void *)tx->descs_cpu) + tx_size * AG71XX_DESC_SIZE;
	rx->descs_dma = tx->descs_dma + tx_size * AG71XX_DESC_SIZE;

	ag71xx_ring_tx_init(ag);
	return ag71xx_ring_rx_init(ag);
}