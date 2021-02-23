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
struct TYPE_8__ {int /*<<< orphan*/  modset; } ;
struct TYPE_7__ {scalar_t__ r; int /*<<< orphan*/  t; } ;
typedef  scalar_t__ Reg ;
typedef  TYPE_1__ IRIns ;
typedef  TYPE_2__ ASMState ;

/* Variables and functions */
 TYPE_1__* IR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REF_BASE ; 
 scalar_t__ RID_BASE ; 
 scalar_t__ RID_INIT ; 
 int /*<<< orphan*/  XO_MOV ; 
 int /*<<< orphan*/  emit_rr (TYPE_2__*,int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 scalar_t__ irt_ismarked (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ra_free (TYPE_2__*,scalar_t__) ; 
 scalar_t__ ra_hasreg (scalar_t__) ; 
 scalar_t__ rset_test (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void asm_head_root_base(ASMState *as)
{
  IRIns *ir = IR(REF_BASE);
  Reg r = ir->r;
  if (ra_hasreg(r)) {
    ra_free(as, r);
    if (rset_test(as->modset, r) || irt_ismarked(ir->t))
      ir->r = RID_INIT;  /* No inheritance for modified BASE register. */
    if (r != RID_BASE)
      emit_rr(as, XO_MOV, r, RID_BASE);
  }
}