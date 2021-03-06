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
typedef  int /*<<< orphan*/  uint ;

/* Variables and functions */
 int /*<<< orphan*/  CFLAG_CLEAR ; 
 int /*<<< orphan*/  DX ; 
 int /*<<< orphan*/  FLAG_C ; 
 int /*<<< orphan*/  FLAG_N ; 
 int /*<<< orphan*/  FLAG_V ; 
 int /*<<< orphan*/  FLAG_Z ; 
 int /*<<< orphan*/  MAKE_INT_8 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MASK_OUT_ABOVE_8 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NFLAG_32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REG_IR ; 
 int /*<<< orphan*/  VFLAG_CLEAR ; 

__attribute__((used)) static void m68k_op_moveq_32(void)
{
  uint res = DX = MAKE_INT_8(MASK_OUT_ABOVE_8(REG_IR));

  FLAG_N = NFLAG_32(res);
  FLAG_Z = res;
  FLAG_V = VFLAG_CLEAR;
  FLAG_C = CFLAG_CLEAR;
}