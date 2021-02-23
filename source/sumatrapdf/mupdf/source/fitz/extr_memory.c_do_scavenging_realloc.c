#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int /*<<< orphan*/  user; void* (* realloc ) (int /*<<< orphan*/ ,void*,size_t) ;} ;
struct TYPE_8__ {TYPE_1__ alloc; } ;
typedef  TYPE_2__ fz_context ;

/* Variables and functions */
 int /*<<< orphan*/  FZ_LOCK_ALLOC ; 
 int /*<<< orphan*/  fz_lock (TYPE_2__*,int /*<<< orphan*/ ) ; 
 scalar_t__ fz_store_scavenge (TYPE_2__*,size_t,int*) ; 
 int /*<<< orphan*/  fz_unlock (TYPE_2__*,int /*<<< orphan*/ ) ; 
 void* stub1 (int /*<<< orphan*/ ,void*,size_t) ; 

__attribute__((used)) static void *
do_scavenging_realloc(fz_context *ctx, void *p, size_t size)
{
	void *q;
	int phase = 0;

	fz_lock(ctx, FZ_LOCK_ALLOC);
	do {
		q = ctx->alloc.realloc(ctx->alloc.user, p, size);
		if (q != NULL)
		{
			fz_unlock(ctx, FZ_LOCK_ALLOC);
			return q;
		}
	} while (fz_store_scavenge(ctx, size, &phase));
	fz_unlock(ctx, FZ_LOCK_ALLOC);

	return NULL;
}