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
typedef  int /*<<< orphan*/  ResultState ;
typedef  int /*<<< orphan*/  PlanState ;

/* Variables and functions */
 int /*<<< orphan*/  DEBUG2 ; 
 int /*<<< orphan*/  ExecMarkPos (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  elog (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/ * outerPlanState (int /*<<< orphan*/ *) ; 

void
ExecResultMarkPos(ResultState *node)
{
	PlanState  *outerPlan = outerPlanState(node);

	if (outerPlan != NULL)
		ExecMarkPos(outerPlan);
	else
		elog(DEBUG2, "Result nodes do not support mark/restore");
}