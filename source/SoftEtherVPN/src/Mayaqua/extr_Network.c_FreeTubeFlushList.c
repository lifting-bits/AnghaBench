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
typedef  scalar_t__ UINT ;
struct TYPE_4__ {int /*<<< orphan*/  List; } ;
typedef  TYPE_1__ TUBE_FLUSH_LIST ;
typedef  int /*<<< orphan*/  TUBE ;

/* Variables and functions */
 int /*<<< orphan*/  Free (TYPE_1__*) ; 
 int /*<<< orphan*/ * LIST_DATA (int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ LIST_NUM (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ReleaseList (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ReleaseTube (int /*<<< orphan*/ *) ; 

void FreeTubeFlushList(TUBE_FLUSH_LIST *f)
{
	UINT i;
	// Validate arguments
	if (f == NULL)
	{
		return;
	}

	for (i = 0;i < LIST_NUM(f->List);i++)
	{
		TUBE *t = LIST_DATA(f->List, i);

		ReleaseTube(t);
	}

	ReleaseList(f->List);

	Free(f);
}