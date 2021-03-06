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
struct bnx2x {int dummy; } ;

/* Variables and functions */
 int BP_ABS_FUNC (struct bnx2x*) ; 
 int /*<<< orphan*/  CHIP_IS_E1x (struct bnx2x*) ; 
 int /*<<< orphan*/  PGLUE_B_REG_WAS_ERROR_PF_7_0_CLR ; 
 int /*<<< orphan*/  REG_WR (struct bnx2x*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void bnx2x_clean_pglue_errors(struct bnx2x *bp)
{
	if (!CHIP_IS_E1x(bp))
		REG_WR(bp, PGLUE_B_REG_WAS_ERROR_PF_7_0_CLR,
		       1 << BP_ABS_FUNC(bp));
}