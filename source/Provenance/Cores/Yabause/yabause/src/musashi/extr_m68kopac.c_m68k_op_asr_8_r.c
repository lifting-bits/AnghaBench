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
 int CFLAG_CLEAR ; 
 int CFLAG_SET ; 
 int CYC_SHIFT ; 
 int DX ; 
 int DY ; 
 int FLAG_C ; 
 int /*<<< orphan*/  FLAG_N ; 
 int /*<<< orphan*/  FLAG_V ; 
 int FLAG_X ; 
 int FLAG_Z ; 
 scalar_t__ GET_MSB_8 (int) ; 
 int MASK_OUT_ABOVE_8 (int) ; 
 int MASK_OUT_BELOW_8 (int) ; 
 int /*<<< orphan*/  NFLAG_8 (int) ; 
 int /*<<< orphan*/  NFLAG_CLEAR ; 
 int /*<<< orphan*/  NFLAG_SET ; 
 int /*<<< orphan*/  USE_CYCLES (int) ; 
 int /*<<< orphan*/  VFLAG_CLEAR ; 
 int XFLAG_CLEAR ; 
 int XFLAG_SET ; 
 int ZFLAG_CLEAR ; 
 int ZFLAG_SET ; 
 int* m68ki_shift_8_table ; 

void m68k_op_asr_8_r(void)
{
	uint* r_dst = &DY;
	uint shift = DX & 0x3f;
	uint src = MASK_OUT_ABOVE_8(*r_dst);
	uint res = src >> shift;

	if(shift != 0)
	{
		USE_CYCLES(shift<<CYC_SHIFT);

		if(shift < 8)
		{
			if(GET_MSB_8(src))
				res |= m68ki_shift_8_table[shift];

			*r_dst = MASK_OUT_BELOW_8(*r_dst) | res;

			FLAG_X = FLAG_C = src << (9-shift);
			FLAG_N = NFLAG_8(res);
			FLAG_Z = res;
			FLAG_V = VFLAG_CLEAR;
			return;
		}

		if(GET_MSB_8(src))
		{
			*r_dst |= 0xff;
			FLAG_C = CFLAG_SET;
			FLAG_X = XFLAG_SET;
			FLAG_N = NFLAG_SET;
			FLAG_Z = ZFLAG_CLEAR;
			FLAG_V = VFLAG_CLEAR;
			return;
		}

		*r_dst &= 0xffffff00;
		FLAG_C = CFLAG_CLEAR;
		FLAG_X = XFLAG_CLEAR;
		FLAG_N = NFLAG_CLEAR;
		FLAG_Z = ZFLAG_SET;
		FLAG_V = VFLAG_CLEAR;
		return;
	}

	FLAG_C = CFLAG_CLEAR;
	FLAG_N = NFLAG_8(src);
	FLAG_Z = src;
	FLAG_V = VFLAG_CLEAR;
}