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
struct TYPE_4__ {struct TYPE_4__* Buffer; struct TYPE_4__* FileName; } ;
typedef  TYPE_1__ HC ;

/* Variables and functions */
 int /*<<< orphan*/  FileClose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  Free (TYPE_1__*) ; 
 TYPE_1__* LIST_DATA (int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ LIST_NUM (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ReleaseList (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * hamcore ; 
 int /*<<< orphan*/ * hamcore_io ; 

void FreeHamcore()
{
	UINT i;
	for (i = 0;i < LIST_NUM(hamcore);i++)
	{
		HC *c = LIST_DATA(hamcore, i);
		Free(c->FileName);
		if (c->Buffer != NULL)
		{
			Free(c->Buffer);
		}
		Free(c);
	}
	ReleaseList(hamcore);

	FileClose(hamcore_io);
	hamcore_io = NULL;
	hamcore = NULL;
}