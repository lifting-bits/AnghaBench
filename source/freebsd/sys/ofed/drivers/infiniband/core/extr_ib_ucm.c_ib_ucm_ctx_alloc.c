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
struct ib_ucm_file {int /*<<< orphan*/  ctxs; } ;
struct ib_ucm_context {scalar_t__ id; int /*<<< orphan*/  file_list; int /*<<< orphan*/  events; struct ib_ucm_file* file; int /*<<< orphan*/  comp; int /*<<< orphan*/  ref; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ctx_id_mutex ; 
 int /*<<< orphan*/  ctx_id_table ; 
 scalar_t__ idr_alloc (int /*<<< orphan*/ *,struct ib_ucm_context*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct ib_ucm_context*) ; 
 struct ib_ucm_context* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static struct ib_ucm_context *ib_ucm_ctx_alloc(struct ib_ucm_file *file)
{
	struct ib_ucm_context *ctx;

	ctx = kzalloc(sizeof *ctx, GFP_KERNEL);
	if (!ctx)
		return NULL;

	atomic_set(&ctx->ref, 1);
	init_completion(&ctx->comp);
	ctx->file = file;
	INIT_LIST_HEAD(&ctx->events);

	mutex_lock(&ctx_id_mutex);
	ctx->id = idr_alloc(&ctx_id_table, ctx, 0, 0, GFP_KERNEL);
	mutex_unlock(&ctx_id_mutex);
	if (ctx->id < 0)
		goto error;

	list_add_tail(&ctx->file_list, &file->ctxs);
	return ctx;

error:
	kfree(ctx);
	return NULL;
}