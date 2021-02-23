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
struct TYPE_3__ {int reg; int /*<<< orphan*/  present; } ;

/* Variables and functions */
 int /*<<< orphan*/  BAD_OVERLAP ; 
 int /*<<< orphan*/  constraint (int,int /*<<< orphan*/ ) ; 
 TYPE_2__ inst ; 

__attribute__((used)) static void
do_t_strexd (void)
{
  if (!inst.operands[2].present)
    inst.operands[2].reg = inst.operands[1].reg + 1;

  constraint (inst.operands[0].reg == inst.operands[1].reg
	      || inst.operands[0].reg == inst.operands[2].reg
	      || inst.operands[0].reg == inst.operands[3].reg
	      || inst.operands[1].reg == inst.operands[2].reg,
	      BAD_OVERLAP);

  inst.instruction |= inst.operands[0].reg;
  inst.instruction |= inst.operands[1].reg << 12;
  inst.instruction |= inst.operands[2].reg << 8;
  inst.instruction |= inst.operands[3].reg << 16;
}