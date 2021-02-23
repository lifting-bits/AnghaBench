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
 int end_of_line (char*) ; 
 TYPE_1__ inst ; 
 int reglow_required_here (char**,int) ; 
 int /*<<< orphan*/  skip_whitespace (char*) ; 

__attribute__((used)) static void
do16_xrs (char *str)
{
  skip_whitespace (str);

  if (reglow_required_here (&str, 4) == (int) FAIL || end_of_line (str) == (int) FAIL)
    {
      return;
    }
  else
    {
      inst.relax_inst |= (((inst.instruction >> 8) & 0xf) << 10)
                      | (((inst.instruction >> 4) & 0xf) << 15);
      inst.relax_size = 4;
    }
}