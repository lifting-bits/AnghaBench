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
 scalar_t__ CALL_INSN ; 
 scalar_t__ GET_CODE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  INSN_P (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PATTERN (int /*<<< orphan*/ ) ; 
 int is_load_insn1 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool
is_load_insn (rtx insn)
{
  if (!insn || !INSN_P (insn))
    return false;

  if (GET_CODE (insn) == CALL_INSN)
    return false;

  return is_load_insn1 (PATTERN (insn));
}