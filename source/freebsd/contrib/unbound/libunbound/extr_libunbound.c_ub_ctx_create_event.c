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
struct ub_ctx {int dothread; int /*<<< orphan*/  event_base; scalar_t__ created_bg; } ;
struct event_base {int dummy; } ;

/* Variables and functions */
 struct ub_ctx* ub_ctx_create_nopipe () ; 
 int /*<<< orphan*/  ub_ctx_delete (struct ub_ctx*) ; 
 int /*<<< orphan*/  ub_libevent_event_base (struct event_base*) ; 

struct ub_ctx* 
ub_ctx_create_event(struct event_base* eb)
{
	struct ub_ctx* ctx = ub_ctx_create_nopipe();
	if(!ctx)
		return NULL;
	/* no pipes, but we have the locks to make sure everything works */
	ctx->created_bg = 0;
	ctx->dothread = 1; /* the processing is in the same process,
		makes ub_cancel and ub_ctx_delete do the right thing */
	ctx->event_base = ub_libevent_event_base(eb);
	if (!ctx->event_base) {
		ub_ctx_delete(ctx);
		return NULL;
	}
	return ctx;
}