#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int instruction; TYPE_1__* operands; } ;
struct TYPE_3__ {int imm; scalar_t__ present; } ;

/* Variables and functions */
 TYPE_2__ inst ; 

__attribute__((used)) static void
do_nop (void)
{
  if (inst.operands[0].present)
    {
      /* Architectural NOP hints are CPSR sets with no bits selected.  */
      inst.instruction &= 0xf0000000;
      inst.instruction |= 0x0320f000 + inst.operands[0].imm;
    }
}