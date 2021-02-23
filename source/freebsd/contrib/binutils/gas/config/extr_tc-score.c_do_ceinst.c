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
 scalar_t__ FAIL ; 
 int /*<<< orphan*/  REG_TYPE_SCORE ; 
 int /*<<< orphan*/  _IMM25 ; 
 int /*<<< orphan*/  _IMM5 ; 
 int data_op2 (char**,int,int /*<<< orphan*/ ) ; 
 int end_of_line (char*) ; 
 int reg_required_here (char**,int,int /*<<< orphan*/ ) ; 
 int skip_past_comma (char**) ; 
 int /*<<< orphan*/  skip_whitespace (char*) ; 

__attribute__((used)) static void
do_ceinst (char *str)
{
  char *strbak;

  strbak = str;
  skip_whitespace (str);

  if (data_op2 (&str, 20, _IMM5) == (int) FAIL
      || skip_past_comma (&str) == (int) FAIL
      || reg_required_here (&str, 15, REG_TYPE_SCORE) == (int) FAIL
      || skip_past_comma (&str) == (int) FAIL
      || reg_required_here (&str, 10, REG_TYPE_SCORE) == (int) FAIL
      || skip_past_comma (&str) == (int) FAIL
      || data_op2 (&str, 5, _IMM5) == (int) FAIL
      || skip_past_comma (&str) == (int) FAIL
      || data_op2 (&str, 0, _IMM5) == (int) FAIL
      || end_of_line (str) == (int) FAIL)
    {
      return;
    }
  else
    {
      str = strbak;
      if (data_op2 (&str, 0, _IMM25) == (int) FAIL)
	return;
    }
}