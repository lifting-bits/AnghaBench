#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  v8i16 ;
typedef  int /*<<< orphan*/  v4i32 ;
typedef  int /*<<< orphan*/  v16u8 ;
struct TYPE_6__ {int /*<<< orphan*/  member_0; } ;
typedef  TYPE_1__ v16i8 ;
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int uint32_t ;
typedef  int int32_t ;
typedef  int /*<<< orphan*/  int16_t ;

/* Variables and functions */
 int /*<<< orphan*/  HEVC_BIW_RND_CLIP4_MAX_SATU (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ILVRL_B2_SH (TYPE_1__,TYPE_1__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LD_SB2 (int /*<<< orphan*/ *,int,TYPE_1__,TYPE_1__) ; 
 int /*<<< orphan*/  LD_SH4 (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PCKEV_B2_UB (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SLLI_4V (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ST_UB2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  __msa_fill_w (int) ; 

__attribute__((used)) static void hevc_biwgt_copy_32w_msa(uint8_t *src0_ptr,
                                    int32_t src_stride,
                                    int16_t *src1_ptr,
                                    int32_t src2_stride,
                                    uint8_t *dst,
                                    int32_t dst_stride,
                                    int32_t height,
                                    int32_t weight0,
                                    int32_t weight1,
                                    int32_t offset0,
                                    int32_t offset1,
                                    int32_t rnd_val)
{
    uint32_t loop_cnt;
    int32_t offset, weight;
    v16u8 out0, out1, out2, out3;
    v16i8 zero = { 0 };
    v16i8 src0, src1, src2, src3;
    v8i16 in0, in1, in2, in3, in4, in5, in6, in7;
    v8i16 tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7;
    v4i32 offset_vec, weight_vec, rnd_vec;

    offset = (offset0 + offset1) << rnd_val;
    weight0 = weight0 & 0x0000FFFF;
    weight = weight0 | (weight1 << 16);

    offset_vec = __msa_fill_w(offset);
    weight_vec = __msa_fill_w(weight);
    rnd_vec = __msa_fill_w(rnd_val + 1);

    for (loop_cnt = (height >> 1); loop_cnt--;) {
        LD_SB2(src0_ptr, 16, src0, src1);
        src0_ptr += src_stride;
        LD_SB2(src0_ptr, 16, src2, src3);
        src0_ptr += src_stride;
        LD_SH4(src1_ptr, 8, in0, in1, in2, in3);
        src1_ptr += src2_stride;
        LD_SH4(src1_ptr, 8, in4, in5, in6, in7);
        src1_ptr += src2_stride;

        ILVRL_B2_SH(zero, src0, tmp0, tmp4);
        ILVRL_B2_SH(zero, src1, tmp1, tmp5);
        ILVRL_B2_SH(zero, src2, tmp2, tmp6);
        ILVRL_B2_SH(zero, src3, tmp3, tmp7);
        SLLI_4V(tmp0, tmp1, tmp2, tmp3, 6);
        SLLI_4V(tmp4, tmp5, tmp6, tmp7, 6);
        HEVC_BIW_RND_CLIP4_MAX_SATU(tmp0, tmp4, tmp1, tmp5, in0, in1, in2, in3,
                                    weight_vec, rnd_vec, offset_vec, tmp0, tmp4,
                                    tmp1, tmp5);
        HEVC_BIW_RND_CLIP4_MAX_SATU(tmp2, tmp6, tmp3, tmp7, in4, in5, in6, in7,
                                    weight_vec, rnd_vec, offset_vec, tmp2, tmp6,
                                    tmp3, tmp7);
        PCKEV_B2_UB(tmp4, tmp0, tmp5, tmp1, out0, out1);
        PCKEV_B2_UB(tmp6, tmp2, tmp7, tmp3, out2, out3);
        ST_UB2(out0, out1, dst, 16);
        dst += dst_stride;
        ST_UB2(out2, out3, dst, 16);
        dst += dst_stride;
    }
}