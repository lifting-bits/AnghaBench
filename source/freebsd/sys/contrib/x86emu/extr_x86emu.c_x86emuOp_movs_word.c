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
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  uint16_t ;
struct TYPE_2__ {int mode; int R_CX; int R_SI; int R_DI; int /*<<< orphan*/  R_ES; } ;
struct x86emu {TYPE_1__ x86; } ;

/* Variables and functions */
 scalar_t__ ACCESS_FLAG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  F_DF ; 
 int SYSMODE_PREFIX_DATA ; 
 int SYSMODE_PREFIX_REPE ; 
 int SYSMODE_PREFIX_REPNE ; 
 int fetch_data_long (struct x86emu*,int) ; 
 int fetch_data_word (struct x86emu*,int) ; 
 int /*<<< orphan*/  store_long (struct x86emu*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  store_word (struct x86emu*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
x86emuOp_movs_word(struct x86emu *emu)
{
	uint32_t val;
	int inc;
	uint32_t count;

	if (emu->x86.mode & SYSMODE_PREFIX_DATA)
		inc = 4;
	else
		inc = 2;

	if (ACCESS_FLAG(F_DF))	/* down */
		inc = -inc;

	count = 1;
	if (emu->x86.mode & (SYSMODE_PREFIX_REPE | SYSMODE_PREFIX_REPNE)) {
		/* dont care whether REPE or REPNE */
		/* move them until CX is ZERO. */
		count = emu->x86.R_CX;
		emu->x86.R_CX = 0;
		emu->x86.mode &= ~(SYSMODE_PREFIX_REPE | SYSMODE_PREFIX_REPNE);
	}
	while (count--) {
		if (emu->x86.mode & SYSMODE_PREFIX_DATA) {
			val = fetch_data_long(emu, emu->x86.R_SI);
			store_long(emu, emu->x86.R_ES, emu->x86.R_DI, val);
		} else {
			val = fetch_data_word(emu, emu->x86.R_SI);
			store_word(emu, emu->x86.R_ES, emu->x86.R_DI,
			    (uint16_t) val);
		}
		emu->x86.R_SI += inc;
		emu->x86.R_DI += inc;
	}
}