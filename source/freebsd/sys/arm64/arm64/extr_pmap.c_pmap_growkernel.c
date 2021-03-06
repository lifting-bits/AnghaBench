#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_1__* vm_page_t ;
typedef  int vm_paddr_t ;
typedef  int vm_offset_t ;
typedef  int /*<<< orphan*/  pd_entry_t ;
struct TYPE_8__ {int /*<<< orphan*/  system_mtx; } ;
struct TYPE_7__ {int flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  KASSERT (int,char*) ; 
 int L1_SHIFT ; 
 int L1_TABLE ; 
 int L2_OFFSET ; 
 int L2_SHIFT ; 
 int L2_SIZE ; 
 int L2_TABLE ; 
 int /*<<< orphan*/  MA_OWNED ; 
 int PG_ZERO ; 
 int VM_ALLOC_INTERRUPT ; 
 int VM_ALLOC_NOOBJ ; 
 int VM_ALLOC_WIRED ; 
 int VM_ALLOC_ZERO ; 
 int VM_PAGE_TO_PHYS (TYPE_1__*) ; 
 int /*<<< orphan*/  dmb (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ishst ; 
 TYPE_3__* kernel_map ; 
 int /*<<< orphan*/  kernel_pmap ; 
 int kernel_vm_end ; 
 int /*<<< orphan*/  mtx_assert (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  panic (char*) ; 
 int /*<<< orphan*/ * pmap_l0 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/ * pmap_l0_to_l1 (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/ * pmap_l1_to_l2 (int /*<<< orphan*/ *,int) ; 
 scalar_t__ pmap_load (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pmap_store (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  pmap_zero_page (TYPE_1__*) ; 
 int roundup2 (int,int) ; 
 int vm_map_max (TYPE_3__*) ; 
 TYPE_1__* vm_page_alloc (int /*<<< orphan*/ *,int,int) ; 

void
pmap_growkernel(vm_offset_t addr)
{
	vm_paddr_t paddr;
	vm_page_t nkpg;
	pd_entry_t *l0, *l1, *l2;

	mtx_assert(&kernel_map->system_mtx, MA_OWNED);

	addr = roundup2(addr, L2_SIZE);
	if (addr - 1 >= vm_map_max(kernel_map))
		addr = vm_map_max(kernel_map);
	while (kernel_vm_end < addr) {
		l0 = pmap_l0(kernel_pmap, kernel_vm_end);
		KASSERT(pmap_load(l0) != 0,
		    ("pmap_growkernel: No level 0 kernel entry"));

		l1 = pmap_l0_to_l1(l0, kernel_vm_end);
		if (pmap_load(l1) == 0) {
			/* We need a new PDP entry */
			nkpg = vm_page_alloc(NULL, kernel_vm_end >> L1_SHIFT,
			    VM_ALLOC_INTERRUPT | VM_ALLOC_NOOBJ |
			    VM_ALLOC_WIRED | VM_ALLOC_ZERO);
			if (nkpg == NULL)
				panic("pmap_growkernel: no memory to grow kernel");
			if ((nkpg->flags & PG_ZERO) == 0)
				pmap_zero_page(nkpg);
			/* See the dmb() in _pmap_alloc_l3(). */
			dmb(ishst);
			paddr = VM_PAGE_TO_PHYS(nkpg);
			pmap_store(l1, paddr | L1_TABLE);
			continue; /* try again */
		}
		l2 = pmap_l1_to_l2(l1, kernel_vm_end);
		if (pmap_load(l2) != 0) {
			kernel_vm_end = (kernel_vm_end + L2_SIZE) & ~L2_OFFSET;
			if (kernel_vm_end - 1 >= vm_map_max(kernel_map)) {
				kernel_vm_end = vm_map_max(kernel_map);
				break;
			}
			continue;
		}

		nkpg = vm_page_alloc(NULL, kernel_vm_end >> L2_SHIFT,
		    VM_ALLOC_INTERRUPT | VM_ALLOC_NOOBJ | VM_ALLOC_WIRED |
		    VM_ALLOC_ZERO);
		if (nkpg == NULL)
			panic("pmap_growkernel: no memory to grow kernel");
		if ((nkpg->flags & PG_ZERO) == 0)
			pmap_zero_page(nkpg);
		/* See the dmb() in _pmap_alloc_l3(). */
		dmb(ishst);
		paddr = VM_PAGE_TO_PHYS(nkpg);
		pmap_store(l2, paddr | L2_TABLE);

		kernel_vm_end = (kernel_vm_end + L2_SIZE) & ~L2_OFFSET;
		if (kernel_vm_end - 1 >= vm_map_max(kernel_map)) {
			kernel_vm_end = vm_map_max(kernel_map);
			break;
		}
	}
}