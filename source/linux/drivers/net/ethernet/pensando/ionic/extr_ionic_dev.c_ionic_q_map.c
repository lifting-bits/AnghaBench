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
struct ionic_queue {unsigned int num_descs; unsigned int desc_size; struct ionic_desc_info* info; int /*<<< orphan*/  base_pa; void* base; } ;
struct ionic_desc_info {void* desc; } ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */

void ionic_q_map(struct ionic_queue *q, void *base, dma_addr_t base_pa)
{
	struct ionic_desc_info *cur;
	unsigned int i;

	q->base = base;
	q->base_pa = base_pa;

	for (i = 0, cur = q->info; i < q->num_descs; i++, cur++)
		cur->desc = base + (i * q->desc_size);
}