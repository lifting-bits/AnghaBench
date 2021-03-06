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
struct mm_struct {int dummy; } ;
typedef  int /*<<< orphan*/  pud_t ;
typedef  int /*<<< orphan*/  pte_t ;
typedef  int /*<<< orphan*/  pmd_t ;
typedef  int /*<<< orphan*/  pgd_t ;

/* Variables and functions */
 unsigned long ADD_ROUND (unsigned long,int /*<<< orphan*/ ) ; 
 int PAGE_MASK ; 
 unsigned long PAGE_SIZE ; 
 int /*<<< orphan*/  PGDIR_SIZE ; 
 int /*<<< orphan*/  PMD_SIZE ; 
 int /*<<< orphan*/  PUD_SIZE ; 
 struct mm_struct init_mm ; 
 int /*<<< orphan*/  map_memory (unsigned long,int,unsigned long,int,int,int) ; 
 int /*<<< orphan*/  os_protect_memory (void*,unsigned long,int,int,int) ; 
 int os_unmap_memory (void*,unsigned long) ; 
 int /*<<< orphan*/  panic (char*,int) ; 
 scalar_t__ pgd_newpage (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pgd_offset (struct mm_struct*,unsigned long) ; 
 int /*<<< orphan*/  pgd_present (int /*<<< orphan*/ ) ; 
 scalar_t__ pmd_newpage (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pmd_offset (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  pmd_present (int /*<<< orphan*/ ) ; 
 scalar_t__ pte_newpage (int /*<<< orphan*/ ) ; 
 scalar_t__ pte_newprot (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pte_offset_kernel (int /*<<< orphan*/ *,unsigned long) ; 
 scalar_t__ pte_present (int /*<<< orphan*/ ) ; 
 int pte_val (int /*<<< orphan*/ ) ; 
 scalar_t__ pud_newpage (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pud_offset (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  pud_present (int /*<<< orphan*/ ) ; 

int flush_tlb_kernel_range_common(unsigned long start, unsigned long end)
{
	struct mm_struct *mm;
	pgd_t *pgd;
	pud_t *pud;
	pmd_t *pmd;
	pte_t *pte;
	unsigned long addr, last;
	int updated = 0, err;

	mm = &init_mm;
	for (addr = start; addr < end;) {
		pgd = pgd_offset(mm, addr);
		if (!pgd_present(*pgd)) {
			last = ADD_ROUND(addr, PGDIR_SIZE);
			if (last > end)
				last = end;
			if (pgd_newpage(*pgd)) {
				updated = 1;
				err = os_unmap_memory((void *) addr,
						      last - addr);
				if (err < 0)
					panic("munmap failed, errno = %d\n",
					      -err);
			}
			addr = last;
			continue;
		}

		pud = pud_offset(pgd, addr);
		if (!pud_present(*pud)) {
			last = ADD_ROUND(addr, PUD_SIZE);
			if (last > end)
				last = end;
			if (pud_newpage(*pud)) {
				updated = 1;
				err = os_unmap_memory((void *) addr,
						      last - addr);
				if (err < 0)
					panic("munmap failed, errno = %d\n",
					      -err);
			}
			addr = last;
			continue;
		}

		pmd = pmd_offset(pud, addr);
		if (!pmd_present(*pmd)) {
			last = ADD_ROUND(addr, PMD_SIZE);
			if (last > end)
				last = end;
			if (pmd_newpage(*pmd)) {
				updated = 1;
				err = os_unmap_memory((void *) addr,
						      last - addr);
				if (err < 0)
					panic("munmap failed, errno = %d\n",
					      -err);
			}
			addr = last;
			continue;
		}

		pte = pte_offset_kernel(pmd, addr);
		if (!pte_present(*pte) || pte_newpage(*pte)) {
			updated = 1;
			err = os_unmap_memory((void *) addr,
					      PAGE_SIZE);
			if (err < 0)
				panic("munmap failed, errno = %d\n",
				      -err);
			if (pte_present(*pte))
				map_memory(addr,
					   pte_val(*pte) & PAGE_MASK,
					   PAGE_SIZE, 1, 1, 1);
		}
		else if (pte_newprot(*pte)) {
			updated = 1;
			os_protect_memory((void *) addr, PAGE_SIZE, 1, 1, 1);
		}
		addr += PAGE_SIZE;
	}
	return updated;
}