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
typedef  int v8i16 ;
typedef  int /*<<< orphan*/  v16i8 ;
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  int8_t ;
typedef  int int32_t ;
typedef  int /*<<< orphan*/  int16_t ;

/* Variables and functions */
 int /*<<< orphan*/  DPADD_SB2_SH (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int,int) ; 
 int /*<<< orphan*/  HEVC_BI_RND_CLIP2 (int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  ILVR_B2_SB (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LD_SB2 (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LD_SB3 (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int LD_SH (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  LD_SH2 (int /*<<< orphan*/ *,int,int,int) ; 
 int /*<<< orphan*/  SPLATI_H2_SH (int,int /*<<< orphan*/ ,int,int,int) ; 
 int /*<<< orphan*/  ST_D2 (int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  XORI_B2_128_SB (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XORI_B3_128_SB (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int __msa_ldi_h (int) ; 
 scalar_t__ __msa_pckev_b (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void hevc_vt_bi_4t_8x2_msa(uint8_t *src0_ptr,
                                  int32_t src_stride,
                                  int16_t *src1_ptr,
                                  int32_t src2_stride,
                                  uint8_t *dst,
                                  int32_t dst_stride,
                                  const int8_t *filter,
                                  int32_t height)
{
    v16i8 src0, src1, src2, src3, src4;
    v8i16 in0, in1, dst0_r, dst1_r;
    v16i8 src10_r, src32_r, src21_r, src43_r;
    v8i16 filt0, filt1;
    v8i16 filter_vec, const_vec;

    src0_ptr -= src_stride;

    const_vec = __msa_ldi_h(128);
    const_vec <<= 6;

    filter_vec = LD_SH(filter);
    SPLATI_H2_SH(filter_vec, 0, 1, filt0, filt1);

    LD_SB3(src0_ptr, src_stride, src0, src1, src2);
    src0_ptr += (3 * src_stride);
    XORI_B3_128_SB(src0, src1, src2);
    ILVR_B2_SB(src1, src0, src2, src1, src10_r, src21_r);

    LD_SB2(src0_ptr, src_stride, src3, src4);
    LD_SH2(src1_ptr, src2_stride, in0, in1);
    XORI_B2_128_SB(src3, src4);
    ILVR_B2_SB(src3, src2, src4, src3, src32_r, src43_r);

    dst0_r = const_vec;
    DPADD_SB2_SH(src10_r, src32_r, filt0, filt1, dst0_r, dst0_r);
    dst1_r = const_vec;
    DPADD_SB2_SH(src21_r, src43_r, filt0, filt1, dst1_r, dst1_r);

    HEVC_BI_RND_CLIP2(in0, in1, dst0_r, dst1_r, 7, dst0_r, dst1_r);
    dst0_r = (v8i16) __msa_pckev_b((v16i8) dst1_r, (v16i8) dst0_r);

    ST_D2(dst0_r, 0, 1, dst, dst_stride);
}