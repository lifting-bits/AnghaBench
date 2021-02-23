#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int relax_inst; int instruction; int relax_size; } ;

/* Variables and functions */
 scalar_t__ FAIL ; 
 int /*<<< orphan*/  _IMM5 ; 
 int data_op2 (char**,int,int /*<<< orphan*/ ) ; 
 int end_of_line (char*) ; 
 TYPE_1__ inst ; 
 int reglow_required_here (char**,int) ; 
 int skip_past_comma (char**) ; 
 int /*<<< orphan*/  skip_whitespace (char*) ; 

__attribute__((used)) static void
do16_rdi5 (char *str)
{
  skip_whitespace (str);

  if (reglow_required_here (&str, 8) == (int) FAIL
      || skip_past_comma (&str) == (int) FAIL
      || data_op2 (&str, 3, _IMM5) == (int) FAIL
      || end_of_line (str) == (int) FAIL)
    return;
  else
    {
      inst.relax_inst |= (((inst.instruction >> 8) & 0xf) << 20)
        | (((inst.instruction >> 8) & 0xf) << 15) | (((inst.instruction >> 3) & 0x1f) << 10);
      inst.relax_size = 4;
    }
}