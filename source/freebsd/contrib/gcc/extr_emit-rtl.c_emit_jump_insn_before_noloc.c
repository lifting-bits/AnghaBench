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

/* Variables and functions */
#define  BARRIER 134 
#define  CALL_INSN 133 
#define  CODE_LABEL 132 
 int GET_CODE (int /*<<< orphan*/ ) ; 
#define  INSN 131 
#define  JUMP_INSN 130 
 int /*<<< orphan*/  NEXT_INSN (int /*<<< orphan*/ ) ; 
#define  NOTE 129 
 int /*<<< orphan*/  NULL_RTX ; 
#define  SEQUENCE 128 
 int /*<<< orphan*/  add_insn_before (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gcc_assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gcc_unreachable () ; 
 int /*<<< orphan*/  make_jump_insn_raw (int /*<<< orphan*/ ) ; 

rtx
emit_jump_insn_before_noloc (rtx x, rtx before)
{
  rtx insn, last = NULL_RTX;

  gcc_assert (before);

  switch (GET_CODE (x))
    {
    case INSN:
    case JUMP_INSN:
    case CALL_INSN:
    case CODE_LABEL:
    case BARRIER:
    case NOTE:
      insn = x;
      while (insn)
	{
	  rtx next = NEXT_INSN (insn);
	  add_insn_before (insn, before);
	  last = insn;
	  insn = next;
	}
      break;

#ifdef ENABLE_RTL_CHECKING
    case SEQUENCE:
      gcc_unreachable ();
      break;
#endif

    default:
      last = make_jump_insn_raw (x);
      add_insn_before (last, before);
      break;
    }

  return last;
}