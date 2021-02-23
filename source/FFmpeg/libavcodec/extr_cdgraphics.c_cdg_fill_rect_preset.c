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

/* Variables and functions */
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int,int) ; 

__attribute__((used)) static void cdg_fill_rect_preset(int tl_x, int tl_y, uint8_t *out,
                                 int color, int w, int h, int stride)
{
    int y;

    for (y = tl_y; y < tl_y + h; y++)
        memset(out + tl_x + y * stride, color, w);
}