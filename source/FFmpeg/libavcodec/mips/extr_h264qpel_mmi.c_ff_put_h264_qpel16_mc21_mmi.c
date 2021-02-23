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
typedef  int /*<<< orphan*/  int16_t ;

/* Variables and functions */
 int /*<<< orphan*/  put_h264_qpel16_h_lowpass_l2_mmi (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/ * const,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  put_h264_qpel16_hv_lowpass_mmi (int /*<<< orphan*/ * const,int /*<<< orphan*/ * const,int /*<<< orphan*/  const*,int,int,int /*<<< orphan*/ ) ; 

void ff_put_h264_qpel16_mc21_mmi(uint8_t *dst, const uint8_t *src,
        ptrdiff_t stride)
{
    uint8_t __attribute__ ((aligned(8))) temp[1024];
    uint8_t *const halfHV = temp;
    int16_t *const halfV = (int16_t *) (temp + 256);

    put_h264_qpel16_hv_lowpass_mmi(halfHV, halfV, src, 16, 16, stride);
    put_h264_qpel16_h_lowpass_l2_mmi(dst, src, halfHV, stride, 16);
}