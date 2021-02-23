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

/* Variables and functions */
 int /*<<< orphan*/  float_near_abs_eps_ulp (float const,float const,float,unsigned int) ; 

int float_near_abs_eps_array_ulp(const float *a, const float *b, float eps,
                         unsigned max_ulp, unsigned len)
{
    unsigned i;

    for (i = 0; i < len; i++) {
        if (!float_near_abs_eps_ulp(a[i], b[i], eps, max_ulp))
            return 0;
    }
    return 1;
}