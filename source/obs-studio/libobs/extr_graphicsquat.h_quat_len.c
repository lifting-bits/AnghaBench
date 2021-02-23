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
struct quat {int dummy; } ;

/* Variables and functions */
 float quat_dot (struct quat const*,struct quat const*) ; 
 float sqrtf (float) ; 

__attribute__((used)) static inline float quat_len(const struct quat *q)
{
	float dot_val = quat_dot(q, q);
	return (dot_val > 0.0f) ? sqrtf(dot_val) : 0.0f;
}