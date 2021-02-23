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
struct vec3 {float w; void* z; void* y; void* x; } ;
struct matrix3 {int /*<<< orphan*/  z; int /*<<< orphan*/  y; int /*<<< orphan*/  x; int /*<<< orphan*/  t; } ;

/* Variables and functions */
 void* vec3_dot (struct vec3*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vec3_sub (struct vec3*,struct vec3 const*,int /*<<< orphan*/ *) ; 

void vec3_transform3x4(struct vec3 *dst, const struct vec3 *v,
		       const struct matrix3 *m)
{
	struct vec3 temp;
	vec3_sub(&temp, v, &m->t);

	dst->x = vec3_dot(&temp, &m->x);
	dst->y = vec3_dot(&temp, &m->y);
	dst->z = vec3_dot(&temp, &m->z);
	dst->w = 0.0f;
}