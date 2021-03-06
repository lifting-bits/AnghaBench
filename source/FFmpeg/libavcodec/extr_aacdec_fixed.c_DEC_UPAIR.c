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

__attribute__((used)) static inline int *DEC_UPAIR(int *dst, unsigned idx, unsigned sign)
{
    dst[0] = (idx & 15) * (1 - (sign & 0xFFFFFFFE));
    dst[1] = (idx >> 4 & 15) * (1 - ((sign & 1) * 2));

    return dst + 2;
}