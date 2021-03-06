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
 int FFMAX (int,int) ; 
 int /*<<< orphan*/  draw_dc (int /*<<< orphan*/ *,int,int,int,int) ; 

__attribute__((used)) static void dc_test(uint8_t *dst, int dst_linesize, int w, int h, int off)
{
    const int step = FFMAX(256/(w*h/256), 1);
    int x, y, color = off;

    for (y = 0; y < h; y += 16) {
        for (x = 0; x < w; x += 16) {
            draw_dc(dst + x + y*dst_linesize, dst_linesize, color, 8, 8);
            color += step;
        }
    }
}