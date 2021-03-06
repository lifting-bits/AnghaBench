#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct x86_emulate_ctxt {int dummy; } ;
struct TYPE_3__ {unsigned int hflags; } ;
struct TYPE_4__ {TYPE_1__ arch; } ;

/* Variables and functions */
 TYPE_2__* emul_to_vcpu (struct x86_emulate_ctxt*) ; 

__attribute__((used)) static void emulator_set_hflags(struct x86_emulate_ctxt *ctxt, unsigned emul_flags)
{
	emul_to_vcpu(ctxt)->arch.hflags = emul_flags;
}