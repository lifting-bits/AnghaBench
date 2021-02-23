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
typedef  int /*<<< orphan*/  VP8Frame ;
typedef  int /*<<< orphan*/  AVCodecContext ;

/* Variables and functions */
 int /*<<< orphan*/  IS_VP8 ; 
 int vp78_decode_mv_mb_modes (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int vp8_decode_mv_mb_modes(AVCodecContext *avctx, VP8Frame *cur_frame,
                                   VP8Frame *prev_frame)
{
    return vp78_decode_mv_mb_modes(avctx, cur_frame, prev_frame, IS_VP8);
}