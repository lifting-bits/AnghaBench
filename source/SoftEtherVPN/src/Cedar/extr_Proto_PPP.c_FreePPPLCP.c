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
struct TYPE_4__ {struct TYPE_4__* Data; int /*<<< orphan*/  OptionList; } ;
typedef  TYPE_1__ PPP_LCP ;

/* Variables and functions */
 int /*<<< orphan*/  Free (TYPE_1__*) ; 
 int /*<<< orphan*/  FreePPPOptionList (int /*<<< orphan*/ ) ; 

void FreePPPLCP(PPP_LCP *c)
{
	// Validate arguments
	if (c == NULL)
	{
		return;
	}

	FreePPPOptionList(c->OptionList);

	Free(c->Data);

	Free(c);
}