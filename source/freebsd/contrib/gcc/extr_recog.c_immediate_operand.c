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
 scalar_t__ CONSTANT_P (int /*<<< orphan*/ ) ; 
 scalar_t__ CONST_INT ; 
 scalar_t__ GET_CODE (int /*<<< orphan*/ ) ; 
 scalar_t__ GET_MODE (int /*<<< orphan*/ ) ; 
 scalar_t__ GET_MODE_CLASS (int) ; 
 scalar_t__ INTVAL (int /*<<< orphan*/ ) ; 
 scalar_t__ LEGITIMATE_CONSTANT_P (int /*<<< orphan*/ ) ; 
 scalar_t__ LEGITIMATE_PIC_OPERAND_P (int /*<<< orphan*/ ) ; 
 scalar_t__ MODE_INT ; 
 scalar_t__ MODE_PARTIAL_INT ; 
 scalar_t__ VOIDmode ; 
 int /*<<< orphan*/  flag_pic ; 
 scalar_t__ trunc_int_for_mode (scalar_t__,int) ; 

int
immediate_operand (rtx op, enum machine_mode mode)
{
  /* Don't accept CONST_INT or anything similar
     if the caller wants something floating.  */
  if (GET_MODE (op) == VOIDmode && mode != VOIDmode
      && GET_MODE_CLASS (mode) != MODE_INT
      && GET_MODE_CLASS (mode) != MODE_PARTIAL_INT)
    return 0;

  if (GET_CODE (op) == CONST_INT
      && mode != VOIDmode
      && trunc_int_for_mode (INTVAL (op), mode) != INTVAL (op))
    return 0;

  return (CONSTANT_P (op)
	  && (GET_MODE (op) == mode || mode == VOIDmode
	      || GET_MODE (op) == VOIDmode)
	  && (! flag_pic || LEGITIMATE_PIC_OPERAND_P (op))
	  && LEGITIMATE_CONSTANT_P (op));
}