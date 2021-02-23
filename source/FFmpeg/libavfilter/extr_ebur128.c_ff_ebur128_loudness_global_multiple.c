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
typedef  int /*<<< orphan*/  FFEBUR128State ;

/* Variables and functions */
 int ebur128_gated_loudness (int /*<<< orphan*/ **,size_t,double*) ; 

int ff_ebur128_loudness_global_multiple(FFEBUR128State ** sts, size_t size,
                                        double *out)
{
    return ebur128_gated_loudness(sts, size, out);
}