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
typedef  scalar_t__ rtx ;

/* Variables and functions */
 scalar_t__ NEXT_INSN (scalar_t__) ; 
 int /*<<< orphan*/  NOTE_P (scalar_t__) ; 

rtx
next_nonnote_insn (rtx insn)
{
  while (insn)
    {
      insn = NEXT_INSN (insn);
      if (insn == 0 || !NOTE_P (insn))
	break;
    }

  return insn;
}