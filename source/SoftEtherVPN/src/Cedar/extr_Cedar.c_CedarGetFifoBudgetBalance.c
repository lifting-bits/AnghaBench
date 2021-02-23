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
typedef  scalar_t__ UINT ;
typedef  int /*<<< orphan*/  CEDAR ;

/* Variables and functions */
 scalar_t__ CedarGetFifoBudgetConsuming (int /*<<< orphan*/ *) ; 
 scalar_t__ FIFO_BUDGET ; 

UINT CedarGetFifoBudgetBalance(CEDAR *c)
{
	UINT current = CedarGetFifoBudgetConsuming(c);
	UINT budget = FIFO_BUDGET;

	if (current <= budget)
	{
		return budget - current;
	}
	else
	{
		return 0;
	}
}