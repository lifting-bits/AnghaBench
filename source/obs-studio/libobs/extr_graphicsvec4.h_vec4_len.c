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
struct vec4 {int dummy; } ;

/* Variables and functions */
 float sqrtf (float) ; 
 float vec4_dot (struct vec4 const*,struct vec4 const*) ; 

__attribute__((used)) static inline float vec4_len(const struct vec4 *v)
{
	float dot_val = vec4_dot(v, v);
	return (dot_val > 0.0f) ? sqrtf(dot_val) : 0.0f;
}