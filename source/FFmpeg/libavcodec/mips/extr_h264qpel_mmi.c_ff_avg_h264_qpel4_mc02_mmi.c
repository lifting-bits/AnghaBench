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
typedef  int ptrdiff_t ;

/* Variables and functions */
 int /*<<< orphan*/  avg_h264_qpel4_v_lowpass_mmi (int /*<<< orphan*/ *,int /*<<< orphan*/ * const,int,int) ; 
 int /*<<< orphan*/  copy_block4_mmi (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int,int,int) ; 

void ff_avg_h264_qpel4_mc02_mmi(uint8_t *dst, const uint8_t *src,
        ptrdiff_t stride)
{
    uint8_t full[36];
    uint8_t * const full_mid= full + 8;
    copy_block4_mmi(full, src - stride*2, 4,  stride, 9);
    avg_h264_qpel4_v_lowpass_mmi(dst, full_mid, stride, 4);
}