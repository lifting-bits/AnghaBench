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
 int /*<<< orphan*/  ff_avg_pixels8_y2_8_mmi (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/ ,int) ; 

void ff_avg_pixels16_y2_8_mmi(uint8_t *block, const uint8_t *pixels,
    ptrdiff_t line_size, int h)
{
    ff_avg_pixels8_y2_8_mmi(block, pixels, line_size, h);
    ff_avg_pixels8_y2_8_mmi(block + 8, pixels + 8, line_size, h);
}