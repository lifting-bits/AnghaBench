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
typedef  int /*<<< orphan*/  rtx ;
typedef  enum machine_mode { ____Placeholder_machine_mode } machine_mode ;

/* Variables and functions */
 int /*<<< orphan*/  GET_MODE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gcc_assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gen_rtx_raw_SUBREG (int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  validate_subreg (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

rtx
gen_rtx_SUBREG (enum machine_mode mode, rtx reg, int offset)
{
  gcc_assert (validate_subreg (mode, GET_MODE (reg), reg, offset));
  return gen_rtx_raw_SUBREG (mode, reg, offset);
}