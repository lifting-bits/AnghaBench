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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  ptrdiff_t ;

/* Variables and functions */
 int /*<<< orphan*/  ff_avg_pixels16_8_mmi (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/ ,int) ; 

void ff_avg_vc1_mspel_mc00_16_mmi(uint8_t *dst, const uint8_t *src,
                                  ptrdiff_t stride, int rnd)
{
    ff_avg_pixels16_8_mmi(dst, src, stride, 16);
}