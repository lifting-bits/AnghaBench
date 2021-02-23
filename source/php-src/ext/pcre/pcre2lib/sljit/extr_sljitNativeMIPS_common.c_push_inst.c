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
struct sljit_compiler {int delay_slot; int /*<<< orphan*/  size; } ;
typedef  int sljit_s32 ;
typedef  int sljit_ins ;

/* Variables and functions */
 int /*<<< orphan*/  FAIL_IF (int) ; 
 int MOVABLE_INS ; 
 int /*<<< orphan*/  SLJIT_ASSERT (int) ; 
 int SLJIT_SUCCESS ; 
 int UNMOVABLE_INS ; 
 scalar_t__ ensure_buf (struct sljit_compiler*,int) ; 

__attribute__((used)) static sljit_s32 push_inst(struct sljit_compiler *compiler, sljit_ins ins, sljit_s32 delay_slot)
{
	SLJIT_ASSERT(delay_slot == MOVABLE_INS || delay_slot >= UNMOVABLE_INS
		|| delay_slot == ((ins >> 11) & 0x1f) || delay_slot == ((ins >> 16) & 0x1f));
	sljit_ins *ptr = (sljit_ins*)ensure_buf(compiler, sizeof(sljit_ins));
	FAIL_IF(!ptr);
	*ptr = ins;
	compiler->size++;
	compiler->delay_slot = delay_slot;
	return SLJIT_SUCCESS;
}