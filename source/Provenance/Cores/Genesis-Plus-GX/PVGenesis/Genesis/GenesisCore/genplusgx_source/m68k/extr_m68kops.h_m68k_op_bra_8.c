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

/* Variables and functions */
 int /*<<< orphan*/  MASK_OUT_ABOVE_8 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REG_IR ; 
 int /*<<< orphan*/  m68ki_branch_8 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void m68k_op_bra_8(void)
{
  m68ki_branch_8(MASK_OUT_ABOVE_8(REG_IR));
}