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
typedef  int /*<<< orphan*/  uint64_t ;
struct vm_exit {int /*<<< orphan*/  exitcode; scalar_t__ inst_length; int /*<<< orphan*/  rip; } ;
struct vm {int /*<<< orphan*/ * rendezvous_func; } ;

/* Variables and functions */
 int /*<<< orphan*/  KASSERT (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  VMEXIT_RENDEZVOUS ; 
 int /*<<< orphan*/  VM_EXITCODE_RENDEZVOUS ; 
 struct vm_exit* vm_exitinfo (struct vm*,int) ; 
 int /*<<< orphan*/  vmm_stat_incr (struct vm*,int,int /*<<< orphan*/ ,int) ; 

void
vm_exit_rendezvous(struct vm *vm, int vcpuid, uint64_t rip)
{
	struct vm_exit *vmexit;

	KASSERT(vm->rendezvous_func != NULL, ("rendezvous not in progress"));

	vmexit = vm_exitinfo(vm, vcpuid);
	vmexit->rip = rip;
	vmexit->inst_length = 0;
	vmexit->exitcode = VM_EXITCODE_RENDEZVOUS;
	vmm_stat_incr(vm, vcpuid, VMEXIT_RENDEZVOUS, 1);
}