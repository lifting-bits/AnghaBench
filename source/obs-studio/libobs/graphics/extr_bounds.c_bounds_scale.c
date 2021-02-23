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
struct vec3 {int dummy; } ;
struct bounds {int /*<<< orphan*/  max; int /*<<< orphan*/  min; } ;

/* Variables and functions */
 int /*<<< orphan*/  vec3_mul (int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct vec3 const*) ; 

void bounds_scale(struct bounds *dst, const struct bounds *b,
		  const struct vec3 *v)
{
	vec3_mul(&dst->min, &b->min, v);
	vec3_mul(&dst->max, &b->max, v);
}