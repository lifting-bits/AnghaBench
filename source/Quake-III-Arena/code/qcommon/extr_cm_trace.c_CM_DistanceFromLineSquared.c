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
typedef  scalar_t__* vec3_t ;

/* Variables and functions */
 int /*<<< orphan*/  CM_ProjectPointOntoVector (scalar_t__*,scalar_t__*,scalar_t__*,scalar_t__*) ; 
 float VectorLengthSquared (scalar_t__*) ; 
 int /*<<< orphan*/  VectorSubtract (scalar_t__*,scalar_t__*,scalar_t__*) ; 
 scalar_t__ fabs (scalar_t__) ; 

float CM_DistanceFromLineSquared(vec3_t p, vec3_t lp1, vec3_t lp2, vec3_t dir) {
	vec3_t proj, t;
	int j;

	CM_ProjectPointOntoVector(p, lp1, dir, proj);
	for (j = 0; j < 3; j++) 
		if ((proj[j] > lp1[j] && proj[j] > lp2[j]) ||
			(proj[j] < lp1[j] && proj[j] < lp2[j]))
			break;
	if (j < 3) {
		if (fabs(proj[j] - lp1[j]) < fabs(proj[j] - lp2[j]))
			VectorSubtract(p, lp1, t);
		else
			VectorSubtract(p, lp2, t);
		return VectorLengthSquared(t);
	}
	VectorSubtract(p, proj, t);
	return VectorLengthSquared(t);
}