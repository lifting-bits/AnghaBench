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
struct dmar_unit {int dummy; } ;
struct dmar_qi_genseq {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DMAR_ASSERT_LOCKED (struct dmar_unit*) ; 
 int DMAR_IQ_DESCR_CTX_GLOB ; 
 int DMAR_IQ_DESCR_CTX_INV ; 
 int /*<<< orphan*/  dmar_qi_advance_tail (struct dmar_unit*) ; 
 int /*<<< orphan*/  dmar_qi_emit (struct dmar_unit*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dmar_qi_emit_wait_seq (struct dmar_unit*,struct dmar_qi_genseq*,int) ; 
 int /*<<< orphan*/  dmar_qi_ensure (struct dmar_unit*,int) ; 
 int /*<<< orphan*/  dmar_qi_wait_for_seq (struct dmar_unit*,struct dmar_qi_genseq*,int) ; 

void
dmar_qi_invalidate_ctx_glob_locked(struct dmar_unit *unit)
{
	struct dmar_qi_genseq gseq;

	DMAR_ASSERT_LOCKED(unit);
	dmar_qi_ensure(unit, 2);
	dmar_qi_emit(unit, DMAR_IQ_DESCR_CTX_INV | DMAR_IQ_DESCR_CTX_GLOB, 0);
	dmar_qi_emit_wait_seq(unit, &gseq, true);
	dmar_qi_advance_tail(unit);
	dmar_qi_wait_for_seq(unit, &gseq, false);
}