#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {int /*<<< orphan*/  mask; } ;
struct TYPE_8__ {int /*<<< orphan*/  mask; } ;
struct TYPE_7__ {int /*<<< orphan*/  mask; } ;
struct TYPE_6__ {int /*<<< orphan*/  mask; } ;
struct TYPE_10__ {TYPE_4__ program_new_psw; TYPE_3__ io_new_psw; TYPE_2__ svc_new_psw; TYPE_1__ external_new_psw; } ;

/* Variables and functions */
 int /*<<< orphan*/  PSW_MASK_MCHECK ; 
 TYPE_5__ S390_lowcore ; 
 int /*<<< orphan*/  __ctl_set_bit (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  local_mcck_enable () ; 

void restore_processor_state(void)
{
	S390_lowcore.external_new_psw.mask |= PSW_MASK_MCHECK;
	S390_lowcore.svc_new_psw.mask |= PSW_MASK_MCHECK;
	S390_lowcore.io_new_psw.mask |= PSW_MASK_MCHECK;
	S390_lowcore.program_new_psw.mask |= PSW_MASK_MCHECK;
	/* Enable lowcore protection */
	__ctl_set_bit(0,28);
	local_mcck_enable();
}