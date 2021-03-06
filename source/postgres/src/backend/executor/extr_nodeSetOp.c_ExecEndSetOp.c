#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int /*<<< orphan*/  ps_ResultTupleSlot; } ;
struct TYPE_5__ {TYPE_3__ ps; scalar_t__ tableContext; } ;
typedef  TYPE_1__ SetOpState ;

/* Variables and functions */
 int /*<<< orphan*/  ExecClearTuple (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ExecEndNode (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ExecFreeExprContext (TYPE_3__*) ; 
 int /*<<< orphan*/  MemoryContextDelete (scalar_t__) ; 
 int /*<<< orphan*/  outerPlanState (TYPE_1__*) ; 

void
ExecEndSetOp(SetOpState *node)
{
	/* clean up tuple table */
	ExecClearTuple(node->ps.ps_ResultTupleSlot);

	/* free subsidiary stuff including hashtable */
	if (node->tableContext)
		MemoryContextDelete(node->tableContext);
	ExecFreeExprContext(&node->ps);

	ExecEndNode(outerPlanState(node));
}