#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  vm_import_quantum; void* vm_arg; int /*<<< orphan*/ * vm_releasefn; int /*<<< orphan*/ * vm_importfn; } ;
typedef  TYPE_1__ vmem_t ;
typedef  int /*<<< orphan*/  vmem_size_t ;
typedef  int /*<<< orphan*/  vmem_release_t ;
typedef  int /*<<< orphan*/  vmem_import_t ;

/* Variables and functions */
 int /*<<< orphan*/  VMEM_LOCK (TYPE_1__*) ; 
 int /*<<< orphan*/  VMEM_UNLOCK (TYPE_1__*) ; 

void
vmem_set_import(vmem_t *vm, vmem_import_t *importfn,
     vmem_release_t *releasefn, void *arg, vmem_size_t import_quantum)
{

	VMEM_LOCK(vm);
	vm->vm_importfn = importfn;
	vm->vm_releasefn = releasefn;
	vm->vm_arg = arg;
	vm->vm_import_quantum = import_quantum;
	VMEM_UNLOCK(vm);
}