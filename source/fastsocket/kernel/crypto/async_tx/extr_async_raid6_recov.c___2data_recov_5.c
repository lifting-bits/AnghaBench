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
struct page {int dummy; } ;
struct dma_async_tx_descriptor {int dummy; } ;
struct async_submit_ctl {int flags; void* scribble; void* cb_param; int /*<<< orphan*/ * cb_fn; } ;
typedef  enum async_tx_flags { ____Placeholder_async_tx_flags } async_tx_flags ;
typedef  int /*<<< orphan*/ * dma_async_tx_callback ;

/* Variables and functions */
 int ASYNC_TX_FENCE ; 
 int ASYNC_TX_XOR_DROP_DST ; 
 int /*<<< orphan*/  BUG_ON (int) ; 
 struct dma_async_tx_descriptor* async_memcpy (struct page*,struct page*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t,struct async_submit_ctl*) ; 
 struct dma_async_tx_descriptor* async_mult (struct page*,struct page*,size_t,size_t,struct async_submit_ctl*) ; 
 struct dma_async_tx_descriptor* async_sum_product (struct page*,struct page**,unsigned char*,size_t,struct async_submit_ctl*) ; 
 struct dma_async_tx_descriptor* async_xor (struct page*,struct page**,int /*<<< orphan*/ ,int,size_t,struct async_submit_ctl*) ; 
 int /*<<< orphan*/  init_async_submit (struct async_submit_ctl*,int,struct dma_async_tx_descriptor*,int /*<<< orphan*/ *,void*,void*) ; 
 unsigned char* raid6_gfexi ; 
 size_t* raid6_gfexp ; 
 unsigned char* raid6_gfinv ; 

__attribute__((used)) static struct dma_async_tx_descriptor *
__2data_recov_5(int disks, size_t bytes, int faila, int failb,
		struct page **blocks, struct async_submit_ctl *submit)
{
	struct dma_async_tx_descriptor *tx = NULL;
	struct page *p, *q, *g, *dp, *dq;
	struct page *srcs[2];
	unsigned char coef[2];
	enum async_tx_flags flags = submit->flags;
	dma_async_tx_callback cb_fn = submit->cb_fn;
	void *cb_param = submit->cb_param;
	void *scribble = submit->scribble;
	int good_srcs, good, i;

	good_srcs = 0;
	good = -1;
	for (i = 0; i < disks-2; i++) {
		if (blocks[i] == NULL)
			continue;
		if (i == faila || i == failb)
			continue;
		good = i;
		good_srcs++;
	}
	BUG_ON(good_srcs > 1);

	p = blocks[disks-2];
	q = blocks[disks-1];
	g = blocks[good];

	/* Compute syndrome with zero for the missing data pages
	 * Use the dead data pages as temporary storage for delta p and
	 * delta q
	 */
	dp = blocks[faila];
	dq = blocks[failb];

	init_async_submit(submit, ASYNC_TX_FENCE, tx, NULL, NULL, scribble);
	tx = async_memcpy(dp, g, 0, 0, bytes, submit);
	init_async_submit(submit, ASYNC_TX_FENCE, tx, NULL, NULL, scribble);
	tx = async_mult(dq, g, raid6_gfexp[good], bytes, submit);

	/* compute P + Pxy */
	srcs[0] = dp;
	srcs[1] = p;
	init_async_submit(submit, ASYNC_TX_FENCE|ASYNC_TX_XOR_DROP_DST, tx,
			  NULL, NULL, scribble);
	tx = async_xor(dp, srcs, 0, 2, bytes, submit);

	/* compute Q + Qxy */
	srcs[0] = dq;
	srcs[1] = q;
	init_async_submit(submit, ASYNC_TX_FENCE|ASYNC_TX_XOR_DROP_DST, tx,
			  NULL, NULL, scribble);
	tx = async_xor(dq, srcs, 0, 2, bytes, submit);

	/* Dx = A*(P+Pxy) + B*(Q+Qxy) */
	srcs[0] = dp;
	srcs[1] = dq;
	coef[0] = raid6_gfexi[failb-faila];
	coef[1] = raid6_gfinv[raid6_gfexp[faila]^raid6_gfexp[failb]];
	init_async_submit(submit, ASYNC_TX_FENCE, tx, NULL, NULL, scribble);
	tx = async_sum_product(dq, srcs, coef, bytes, submit);

	/* Dy = P+Pxy+Dx */
	srcs[0] = dp;
	srcs[1] = dq;
	init_async_submit(submit, flags | ASYNC_TX_XOR_DROP_DST, tx, cb_fn,
			  cb_param, scribble);
	tx = async_xor(dp, srcs, 0, 2, bytes, submit);

	return tx;
}