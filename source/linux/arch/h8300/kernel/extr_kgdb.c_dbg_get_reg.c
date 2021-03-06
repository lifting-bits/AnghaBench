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
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct pt_regs {int dummy; } ;
struct TYPE_2__ {char* name; int /*<<< orphan*/  size; int /*<<< orphan*/  offset; } ;

/* Variables and functions */
 int DBG_MAX_REG_NUM ; 
#define  GDB_CCR 129 
#define  GDB_EXR 128 
 TYPE_1__* dbg_reg_def ; 
 int /*<<< orphan*/  memcpy (void*,void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

char *dbg_get_reg(int regno, void *mem, struct pt_regs *regs)
{
	if (regno >= DBG_MAX_REG_NUM || regno < 0)
		return NULL;

	switch (regno) {
	case GDB_CCR:
#if defined(CONFIG_CPU_H8S)
	case GDB_EXR:
#endif
		*(u32 *)mem = *(u16 *)((void *)regs +
				       dbg_reg_def[regno].offset);
		break;
	default:
		if (dbg_reg_def[regno].offset >= 0)
			memcpy(mem, (void *)regs + dbg_reg_def[regno].offset,
			       dbg_reg_def[regno].size);
		else
			memset(mem, 0, dbg_reg_def[regno].size);
		break;
	}
	return dbg_reg_def[regno].name;
}