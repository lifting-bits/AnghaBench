#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {scalar_t__ rtekind; int /*<<< orphan*/  values_lists; } ;
typedef  TYPE_1__ RangeTblEntry ;

/* Variables and functions */
 int /*<<< orphan*/  Assert (int) ; 
 int /*<<< orphan*/  IntList ; 
 int IsA (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ RTE_RELATION ; 
 int linitial_int (int /*<<< orphan*/ ) ; 
 int list_length (int /*<<< orphan*/ ) ; 

int
GetRTEIdentity(RangeTblEntry *rte)
{
	Assert(rte->rtekind == RTE_RELATION);
	Assert(IsA(rte->values_lists, IntList));
	Assert(list_length(rte->values_lists) == 1);

	return linitial_int(rte->values_lists);
}