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
typedef  int /*<<< orphan*/  uint16_t ;

/* Variables and functions */
 int const AV_RN16A (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  av_clip (int,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void filter16_row(uint8_t *dstp, int width,
                         float rdiv, float bias, const int *const matrix,
                         const uint8_t *c[], int peak, int radius,
                         int dstride, int stride)
{
    uint16_t *dst = (uint16_t *)dstp;
    int x;

    for (x = 0; x < width; x++) {
        int i, sum = 0;

        for (i = 0; i < 2 * radius + 1; i++)
            sum += AV_RN16A(&c[i][2 * x]) * matrix[i];

        sum = (int)(sum * rdiv + bias + 0.5f);
        dst[x] = av_clip(sum, 0, peak);
    }
}