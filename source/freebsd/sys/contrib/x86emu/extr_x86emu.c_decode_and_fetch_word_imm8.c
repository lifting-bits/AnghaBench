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
typedef  int /*<<< orphan*/  uint16_t ;
struct x86emu {int cur_mod; int /*<<< orphan*/  cur_offset; } ;

/* Variables and functions */
 int /*<<< orphan*/  decode_rl_address (struct x86emu*) ; 
 int /*<<< orphan*/ * decode_rl_word_register (struct x86emu*) ; 
 int /*<<< orphan*/  fetch_byte_imm (struct x86emu*) ; 
 int /*<<< orphan*/  fetch_data_word (struct x86emu*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static uint16_t
decode_and_fetch_word_imm8(struct x86emu *emu, uint8_t *imm)
{
	if (emu->cur_mod != 3) {
		emu->cur_offset = decode_rl_address(emu);
		*imm = fetch_byte_imm(emu);
		return fetch_data_word(emu, emu->cur_offset);
	} else {
		*imm = fetch_byte_imm(emu);
		return *decode_rl_word_register(emu);
	}
}