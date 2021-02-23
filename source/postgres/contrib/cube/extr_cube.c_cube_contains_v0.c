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
typedef  int /*<<< orphan*/  NDBOX ;

/* Variables and functions */
 int DIM (int /*<<< orphan*/ *) ; 
 int LL_COORD (int /*<<< orphan*/ *,int) ; 
 scalar_t__ Max (int,int) ; 
 scalar_t__ Min (int,int) ; 
 int UR_COORD (int /*<<< orphan*/ *,int) ; 

bool
cube_contains_v0(NDBOX *a, NDBOX *b)
{
	int			i;

	if ((a == NULL) || (b == NULL))
		return false;

	if (DIM(a) < DIM(b))
	{
		/*
		 * the further comparisons will make sense if the excess dimensions of
		 * (b) were zeroes Since both UL and UR coordinates must be zero, we
		 * can check them all without worrying about which is which.
		 */
		for (i = DIM(a); i < DIM(b); i++)
		{
			if (LL_COORD(b, i) != 0)
				return false;
			if (UR_COORD(b, i) != 0)
				return false;
		}
	}

	/* Can't care less about the excess dimensions of (a), if any */
	for (i = 0; i < Min(DIM(a), DIM(b)); i++)
	{
		if (Min(LL_COORD(a, i), UR_COORD(a, i)) >
			Min(LL_COORD(b, i), UR_COORD(b, i)))
			return false;
		if (Max(LL_COORD(a, i), UR_COORD(a, i)) <
			Max(LL_COORD(b, i), UR_COORD(b, i)))
			return false;
	}

	return true;
}