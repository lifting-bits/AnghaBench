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
struct vm {int maxcpus; int /*<<< orphan*/  rendezvous_mtx; int /*<<< orphan*/  (* rendezvous_func ) (struct vm*,int,int /*<<< orphan*/ ) ;int /*<<< orphan*/  rendezvous_done_cpus; int /*<<< orphan*/  rendezvous_req_cpus; int /*<<< orphan*/  rendezvous_arg; int /*<<< orphan*/  active_cpus; } ;

/* Variables and functions */
 int /*<<< orphan*/  CPU_AND (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ CPU_CMP (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ CPU_ISSET (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CPU_SET (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  KASSERT (int,char*) ; 
 int /*<<< orphan*/  RENDEZVOUS_CTR0 (struct vm*,int,char*) ; 
 int /*<<< orphan*/  VCPU_CTR0 (struct vm*,int,char*) ; 
 int /*<<< orphan*/  mtx_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mtx_sleep (int /*<<< orphan*/  (*) (struct vm*,int,int /*<<< orphan*/ ),int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtx_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct vm*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wakeup (int /*<<< orphan*/  (*) (struct vm*,int,int /*<<< orphan*/ )) ; 

__attribute__((used)) static void
vm_handle_rendezvous(struct vm *vm, int vcpuid)
{

	KASSERT(vcpuid == -1 || (vcpuid >= 0 && vcpuid < vm->maxcpus),
	    ("vm_handle_rendezvous: invalid vcpuid %d", vcpuid));

	mtx_lock(&vm->rendezvous_mtx);
	while (vm->rendezvous_func != NULL) {
		/* 'rendezvous_req_cpus' must be a subset of 'active_cpus' */
		CPU_AND(&vm->rendezvous_req_cpus, &vm->active_cpus);

		if (vcpuid != -1 &&
		    CPU_ISSET(vcpuid, &vm->rendezvous_req_cpus) &&
		    !CPU_ISSET(vcpuid, &vm->rendezvous_done_cpus)) {
			VCPU_CTR0(vm, vcpuid, "Calling rendezvous func");
			(*vm->rendezvous_func)(vm, vcpuid, vm->rendezvous_arg);
			CPU_SET(vcpuid, &vm->rendezvous_done_cpus);
		}
		if (CPU_CMP(&vm->rendezvous_req_cpus,
		    &vm->rendezvous_done_cpus) == 0) {
			VCPU_CTR0(vm, vcpuid, "Rendezvous completed");
			vm->rendezvous_func = NULL;
			wakeup(&vm->rendezvous_func);
			break;
		}
		RENDEZVOUS_CTR0(vm, vcpuid, "Wait for rendezvous completion");
		mtx_sleep(&vm->rendezvous_func, &vm->rendezvous_mtx, 0,
		    "vmrndv", 0);
	}
	mtx_unlock(&vm->rendezvous_mtx);
}