#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int flags; } ;
typedef  TYPE_1__ aarch64_opcode ;
typedef  int aarch64_insn ;

/* Variables and functions */

__attribute__((used)) static inline aarch64_insn
get_optional_operand_default_value (const aarch64_opcode *opcode)
{
  return (opcode->flags >> 15) & 0x1f;
}