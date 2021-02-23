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
typedef  int uint ;

/* Variables and functions */
 int CYC_SHIFT ; 
 int DY ; 
 int FLAG_C ; 
 int /*<<< orphan*/  FLAG_N ; 
 int FLAG_V ; 
 int FLAG_X ; 
 int FLAG_Z ; 
 int MASK_OUT_ABOVE_32 (int) ; 
 int /*<<< orphan*/  NFLAG_32 (int) ; 
 int REG_IR ; 
 int /*<<< orphan*/  USE_CYCLES (int) ; 
 int* m68ki_shift_32_table ; 

__attribute__((used)) static void m68k_op_asl_32_s(void)
{
  uint* r_dst = &DY;
  uint shift = (((REG_IR >> 9) - 1) & 7) + 1;
  uint src = *r_dst;
  uint res = MASK_OUT_ABOVE_32(src << shift);

  if(shift != 0)
    USE_CYCLES(shift * CYC_SHIFT);

  *r_dst = res;

  FLAG_N = NFLAG_32(res);
  FLAG_Z = res;
  FLAG_X = FLAG_C = src >> (24-shift);
  src &= m68ki_shift_32_table[shift + 1];
  FLAG_V = (!(src == 0 || src == m68ki_shift_32_table[shift + 1]))<<7;
}