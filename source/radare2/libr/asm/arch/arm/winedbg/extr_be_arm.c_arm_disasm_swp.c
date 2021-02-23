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
typedef  int ut32 ;
struct winedbg_arm_insn {int /*<<< orphan*/  str_asm; } ;

/* Variables and functions */
 int /*<<< orphan*/  get_cond (int) ; 
 size_t get_nibble (int,int) ; 
 int /*<<< orphan*/  r_str_appendf (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * tbl_regs ; 

__attribute__((used)) static ut32 arm_disasm_swp(struct winedbg_arm_insn *arminsn, ut32 inst) {
	short byte = (inst >> 22) & 0x01;

	arminsn->str_asm = r_str_appendf (arminsn->str_asm, "swp%s%s %s, %s, [%s]", get_cond (inst), byte ? "b" : "",
			tbl_regs[get_nibble (inst, 3)], tbl_regs[get_nibble (inst, 0)],
			tbl_regs[get_nibble (inst, 4)]);
	return 0;
}