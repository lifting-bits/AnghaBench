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
struct TYPE_4__ {struct TYPE_4__* StringA; struct TYPE_4__* String; } ;
typedef  TYPE_1__ VI_STRING ;
typedef  scalar_t__ UINT ;

/* Variables and functions */
 int /*<<< orphan*/  Free (TYPE_1__*) ; 
 TYPE_1__* LIST_DATA (int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ LIST_NUM (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ReleaseList (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * string_table ; 

void ViFreeStringTables()
{
	UINT i;
	if (string_table == NULL)
	{
		return;
	}

	for (i = 0;i < LIST_NUM(string_table);i++)
	{
		VI_STRING *s = LIST_DATA(string_table, i);

		Free(s->String);
		Free(s->StringA);
		Free(s);
	}

	ReleaseList(string_table);
	string_table = NULL;
}