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
typedef  int /*<<< orphan*/  uint16_t ;
struct x86emu {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  decode_and_fetch_word_disp (struct x86emu*,int /*<<< orphan*/ ) ; 

uint16_t
decode_and_fetch_word(struct x86emu *emu)
{
	return decode_and_fetch_word_disp(emu, 0);
}