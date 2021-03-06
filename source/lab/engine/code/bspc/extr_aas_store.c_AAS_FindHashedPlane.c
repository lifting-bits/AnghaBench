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
typedef  int /*<<< orphan*/  vec3_t ;
typedef  int qboolean ;

/* Variables and functions */
 scalar_t__ AAS_PlaneEqual (int /*<<< orphan*/ ,float,int) ; 
 int PLANE_HASH_SIZE ; 
 int* aas_hashplanes ; 
 int* aas_planechain ; 
 scalar_t__ fabs (float) ; 

qboolean AAS_FindHashedPlane(vec3_t normal, float dist, int *planenum)
{
	int i, p;
	int hash, h;

	hash = (int)fabs(dist) / 8;
	hash &= (PLANE_HASH_SIZE-1);

	//search the border bins as well
	for (i = -1; i <= 1; i++)
	{
		h = (hash+i)&(PLANE_HASH_SIZE-1);
		for (p = aas_hashplanes[h]; p >= 0; p = aas_planechain[p])
		{
			if (AAS_PlaneEqual(normal, dist, p))
			{
				*planenum = p;
				return true;
			} //end if
		} //end for
	} //end for
	return false;
}