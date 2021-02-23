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
struct fpu_cc_ent {int /*<<< orphan*/ * ctx; } ;

/* Variables and functions */
 int FPU_KERN_NORMAL ; 
 int FPU_KERN_NOWAIT ; 
 struct fpu_cc_ent* LIST_FIRST (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  LIST_INSERT_HEAD (int /*<<< orphan*/ *,struct fpu_cc_ent*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LIST_REMOVE (struct fpu_cc_ent*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  M_DEVBUF ; 
 int M_NOWAIT ; 
 int M_ZERO ; 
 int /*<<< orphan*/  entries ; 
 int /*<<< orphan*/  fpu_busy_head ; 
 int /*<<< orphan*/  fpu_busy_mtx ; 
 int /*<<< orphan*/  fpu_free_head ; 
 int /*<<< orphan*/  fpu_free_mtx ; 
 int /*<<< orphan*/ * fpu_kern_alloc_ctx (int) ; 
 int /*<<< orphan*/  free (struct fpu_cc_ent*,int /*<<< orphan*/ ) ; 
 struct fpu_cc_ent* malloc (int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mtx_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mtx_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static struct fpu_cc_ent *
request_fpu_cc_ent(void)
{
	struct fpu_cc_ent *ent;

	mtx_lock(&fpu_free_mtx);
	if ((ent = LIST_FIRST(&fpu_free_head)) != NULL) {
		LIST_REMOVE(ent, entries);
		mtx_unlock(&fpu_free_mtx);
		mtx_lock(&fpu_busy_mtx);
		LIST_INSERT_HEAD(&fpu_busy_head, ent, entries);
		mtx_unlock(&fpu_busy_mtx);
		return (ent);
	}
	mtx_unlock(&fpu_free_mtx);

	if ((ent = malloc(sizeof(struct fpu_cc_ent), M_DEVBUF, M_NOWAIT |
	    M_ZERO)) != NULL) {
		ent->ctx = fpu_kern_alloc_ctx(FPU_KERN_NORMAL |
		    FPU_KERN_NOWAIT);
		if (ent->ctx != NULL) {
			mtx_lock(&fpu_busy_mtx);
			LIST_INSERT_HEAD(&fpu_busy_head, ent, entries);
			mtx_unlock(&fpu_busy_mtx);
		} else {
			free(ent, M_DEVBUF);
			ent = NULL;
		}
	}

	return (ent);
}