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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint32_t ;
struct x86emu {scalar_t__ cur_rh; int cur_mod; } ;

/* Variables and functions */
 int /*<<< orphan*/  decode_rl_address (struct x86emu*) ; 
 int /*<<< orphan*/ * decode_rl_byte_register (struct x86emu*) ; 
 int /*<<< orphan*/  fetch_byte_imm (struct x86emu*) ; 
 int /*<<< orphan*/  fetch_decode_modrm (struct x86emu*) ; 
 int /*<<< orphan*/  store_data_byte (struct x86emu*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  x86emu_halt_sys (struct x86emu*) ; 

__attribute__((used)) static void
x86emuOp_mov_byte_RM_IMM(struct x86emu *emu)
{
	uint8_t *destreg;
	uint32_t destoffset;
	uint8_t imm;

	fetch_decode_modrm(emu);
	if (emu->cur_rh != 0)
		x86emu_halt_sys(emu);
	if (emu->cur_mod != 3) {
		destoffset = decode_rl_address(emu);
		imm = fetch_byte_imm(emu);
		store_data_byte(emu, destoffset, imm);
	} else {
		destreg = decode_rl_byte_register(emu);
		imm = fetch_byte_imm(emu);
		*destreg = imm;
	}
}