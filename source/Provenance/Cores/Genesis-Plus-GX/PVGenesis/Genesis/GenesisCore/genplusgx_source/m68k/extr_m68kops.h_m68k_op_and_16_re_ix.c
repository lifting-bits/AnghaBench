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
 int /*<<< orphan*/  CFLAG_CLEAR ; 
 int DX ; 
 int EA_AY_IX_16 () ; 
 int /*<<< orphan*/  FLAG_C ; 
 int /*<<< orphan*/  FLAG_N ; 
 int /*<<< orphan*/  FLAG_V ; 
 int /*<<< orphan*/  FLAG_Z ; 
 int /*<<< orphan*/  MASK_OUT_ABOVE_16 (int) ; 
 int /*<<< orphan*/  NFLAG_16 (int) ; 
 int /*<<< orphan*/  VFLAG_CLEAR ; 
 int m68ki_read_16 (int) ; 
 int /*<<< orphan*/  m68ki_write_16 (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void m68k_op_and_16_re_ix(void)
{
  uint ea = EA_AY_IX_16();
  uint res = DX & m68ki_read_16(ea);

  FLAG_N = NFLAG_16(res);
  FLAG_C = CFLAG_CLEAR;
  FLAG_V = VFLAG_CLEAR;
  FLAG_Z = MASK_OUT_ABOVE_16(res);

  m68ki_write_16(ea, FLAG_Z);
}