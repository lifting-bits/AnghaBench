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
typedef  int /*<<< orphan*/  u32 ;
struct snd_emu10k1_fx8010_code {int /*<<< orphan*/ * gpr_map; int /*<<< orphan*/  gpr_valid; } ;
struct snd_emu10k1 {scalar_t__ gpr_base; scalar_t__ audigy; } ;

/* Variables and functions */
 int EFAULT ; 
 scalar_t__ get_user (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snd_emu10k1_ptr_write (struct snd_emu10k1*,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  test_bit (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int snd_emu10k1_gpr_poke(struct snd_emu10k1 *emu,
				struct snd_emu10k1_fx8010_code *icode)
{
	int gpr;
	u32 val;

	for (gpr = 0; gpr < (emu->audigy ? 0x200 : 0x100); gpr++) {
		if (!test_bit(gpr, icode->gpr_valid))
			continue;
		if (get_user(val, &icode->gpr_map[gpr]))
			return -EFAULT;
		snd_emu10k1_ptr_write(emu, emu->gpr_base + gpr, 0, val);
	}
	return 0;
}