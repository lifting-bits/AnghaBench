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
struct vmbus_xact_ctx {int xc_flags; int /*<<< orphan*/  xc_lock; struct vmbus_xact* xc_active; } ;
struct vmbus_xact {int /*<<< orphan*/ * x_resp; struct vmbus_xact_ctx* x_ctx; } ;

/* Variables and functions */
 int /*<<< orphan*/  DELAY (int) ; 
 int /*<<< orphan*/  KASSERT (int,char*) ; 
 int VMBUS_XACT_CTXF_DESTROY ; 
 int /*<<< orphan*/  mtx_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mtx_sleep (struct vmbus_xact**,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtx_unlock (int /*<<< orphan*/ *) ; 
 void* vmbus_xact_return (struct vmbus_xact*,size_t*) ; 

__attribute__((used)) static const void *
vmbus_xact_wait1(struct vmbus_xact *xact, size_t *resp_len,
    bool can_sleep)
{
	struct vmbus_xact_ctx *ctx = xact->x_ctx;
	const void *resp;

	mtx_lock(&ctx->xc_lock);

	KASSERT(ctx->xc_active == xact, ("xact mismatch"));
	while (xact->x_resp == NULL &&
	    (ctx->xc_flags & VMBUS_XACT_CTXF_DESTROY) == 0) {
		if (can_sleep) {
			mtx_sleep(&ctx->xc_active, &ctx->xc_lock, 0,
			    "wxact", 0);
		} else {
			mtx_unlock(&ctx->xc_lock);
			DELAY(1000);
			mtx_lock(&ctx->xc_lock);
		}
	}
	resp = vmbus_xact_return(xact, resp_len);

	mtx_unlock(&ctx->xc_lock);

	return (resp);
}