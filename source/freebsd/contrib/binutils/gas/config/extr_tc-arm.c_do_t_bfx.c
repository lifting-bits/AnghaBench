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
struct TYPE_3__ {int imm; int reg; } ;

/* Variables and functions */
 int /*<<< orphan*/  _ (char*) ; 
 int /*<<< orphan*/  constraint (int,int /*<<< orphan*/ ) ; 
 TYPE_2__ inst ; 

__attribute__((used)) static void
do_t_bfx (void)
{
  constraint (inst.operands[2].imm + inst.operands[3].imm > 32,
	      _("bit-field extends past end of register"));
  inst.instruction |= inst.operands[0].reg << 8;
  inst.instruction |= inst.operands[1].reg << 16;
  inst.instruction |= (inst.operands[2].imm & 0x1c) << 10;
  inst.instruction |= (inst.operands[2].imm & 0x03) << 6;
  inst.instruction |= inst.operands[3].imm - 1;
}