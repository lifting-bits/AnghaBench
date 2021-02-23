#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  vmem_t ;
typedef  scalar_t__ vm_size_t ;
typedef  int vm_prot_t ;
typedef  TYPE_1__* vm_page_t ;
typedef  int /*<<< orphan*/  vm_paddr_t ;
typedef  scalar_t__ vm_offset_t ;
typedef  int /*<<< orphan*/  vm_object_t ;
typedef  int /*<<< orphan*/  vm_memattr_t ;
struct TYPE_8__ {int /*<<< orphan*/ * vmd_kernel_arena; } ;
struct TYPE_7__ {int flags; int /*<<< orphan*/  valid; } ;

/* Variables and functions */
 int /*<<< orphan*/  KASSERT (int,char*) ; 
 int M_BESTFIT ; 
 int M_EXEC ; 
 int M_NOWAIT ; 
 int M_WAITOK ; 
 int M_ZERO ; 
 scalar_t__ PAGE_SIZE ; 
 int PG_ZERO ; 
 int PMAP_ENTER_WIRED ; 
 int VM_ALLOC_NOBUSY ; 
 int VM_ALLOC_NOWAIT ; 
 int VM_ALLOC_WAITFAIL ; 
 int VM_ALLOC_WAITOK ; 
 int VM_ALLOC_WIRED ; 
 scalar_t__ VM_MIN_KERNEL_ADDRESS ; 
 int /*<<< orphan*/  VM_OBJECT_WLOCK (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  VM_OBJECT_WUNLOCK (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  VM_PAGE_BITS_ALL ; 
 int VM_PROT_ALL ; 
 int VM_PROT_RW ; 
 int /*<<< orphan*/  atop (scalar_t__) ; 
 int /*<<< orphan*/  kernel_object ; 
 int /*<<< orphan*/  kernel_pmap ; 
 int /*<<< orphan*/  kmem_unback (int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 int malloc2vm_flags (int) ; 
 int /*<<< orphan*/  pmap_enter (int /*<<< orphan*/ ,scalar_t__,TYPE_1__*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pmap_zero_page (TYPE_1__*) ; 
 scalar_t__ round_page (scalar_t__) ; 
 TYPE_4__* vm_dom ; 
 TYPE_1__* vm_page_alloc_contig_domain (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vm_page_reclaim_contig_domain (int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 
 int vm_phys_domain (TYPE_1__*) ; 
 int /*<<< orphan*/  vm_wait_domain (int) ; 
 scalar_t__ vmem_alloc (int /*<<< orphan*/ *,scalar_t__,int,scalar_t__*) ; 
 int /*<<< orphan*/  vmem_free (int /*<<< orphan*/ *,scalar_t__,scalar_t__) ; 

__attribute__((used)) static vm_offset_t
kmem_alloc_attr_domain(int domain, vm_size_t size, int flags, vm_paddr_t low,
    vm_paddr_t high, vm_memattr_t memattr)
{
	vmem_t *vmem;
	vm_object_t object = kernel_object;
	vm_offset_t addr, i, offset;
	vm_page_t m;
	int pflags, tries;
	vm_prot_t prot;

	size = round_page(size);
	vmem = vm_dom[domain].vmd_kernel_arena;
	if (vmem_alloc(vmem, size, M_BESTFIT | flags, &addr))
		return (0);
	offset = addr - VM_MIN_KERNEL_ADDRESS;
	pflags = malloc2vm_flags(flags) | VM_ALLOC_NOBUSY | VM_ALLOC_WIRED;
	pflags &= ~(VM_ALLOC_NOWAIT | VM_ALLOC_WAITOK | VM_ALLOC_WAITFAIL);
	pflags |= VM_ALLOC_NOWAIT;
	prot = (flags & M_EXEC) != 0 ? VM_PROT_ALL : VM_PROT_RW;
	VM_OBJECT_WLOCK(object);
	for (i = 0; i < size; i += PAGE_SIZE) {
		tries = 0;
retry:
		m = vm_page_alloc_contig_domain(object, atop(offset + i),
		    domain, pflags, 1, low, high, PAGE_SIZE, 0, memattr);
		if (m == NULL) {
			VM_OBJECT_WUNLOCK(object);
			if (tries < ((flags & M_NOWAIT) != 0 ? 1 : 3)) {
				if (!vm_page_reclaim_contig_domain(domain,
				    pflags, 1, low, high, PAGE_SIZE, 0) &&
				    (flags & M_WAITOK) != 0)
					vm_wait_domain(domain);
				VM_OBJECT_WLOCK(object);
				tries++;
				goto retry;
			}
			kmem_unback(object, addr, i);
			vmem_free(vmem, addr, size);
			return (0);
		}
		KASSERT(vm_phys_domain(m) == domain,
		    ("kmem_alloc_attr_domain: Domain mismatch %d != %d",
		    vm_phys_domain(m), domain));
		if ((flags & M_ZERO) && (m->flags & PG_ZERO) == 0)
			pmap_zero_page(m);
		m->valid = VM_PAGE_BITS_ALL;
		pmap_enter(kernel_pmap, addr + i, m, prot,
		    prot | PMAP_ENTER_WIRED, 0);
	}
	VM_OBJECT_WUNLOCK(object);
	return (addr);
}