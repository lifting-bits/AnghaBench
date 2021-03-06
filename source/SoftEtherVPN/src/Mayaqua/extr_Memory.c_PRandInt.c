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
typedef  int /*<<< orphan*/  UINT ;
typedef  int /*<<< orphan*/  PRAND ;

/* Variables and functions */
 int /*<<< orphan*/  PRand (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 

UINT PRandInt(PRAND *p)
{
	UINT r;
	if (p == NULL)
	{
		return 0;
	}

	PRand(p, &r, sizeof(UINT));

	return r;
}