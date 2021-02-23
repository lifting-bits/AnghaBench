#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  lock; int /*<<< orphan*/  Traffic; struct TYPE_4__* Policy; struct TYPE_4__* Note; struct TYPE_4__* RealName; struct TYPE_4__* Name; } ;
typedef  TYPE_1__ USERGROUP ;

/* Variables and functions */
 int /*<<< orphan*/  DeleteLock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Free (TYPE_1__*) ; 
 int /*<<< orphan*/  FreeTraffic (int /*<<< orphan*/ ) ; 

void CleanupGroup(USERGROUP *g)
{
	// Validate arguments
	if (g == NULL)
	{
		return;
	}

	Free(g->Name);
	Free(g->RealName);
	Free(g->Note);

	if (g->Policy)
	{
		// Free policy data
		Free(g->Policy);
	}


	FreeTraffic(g->Traffic);

	DeleteLock(g->lock);
	Free(g);
}