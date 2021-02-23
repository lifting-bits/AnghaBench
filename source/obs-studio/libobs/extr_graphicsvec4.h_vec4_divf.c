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
struct vec4 {int /*<<< orphan*/  m; } ;

/* Variables and functions */
 int /*<<< orphan*/  _mm_div_ps (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _mm_set1_ps (float) ; 

__attribute__((used)) static inline void vec4_divf(struct vec4 *dst, const struct vec4 *v, float f)
{
	dst->m = _mm_div_ps(v->m, _mm_set1_ps(f));
}