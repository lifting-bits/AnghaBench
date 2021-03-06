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
typedef  scalar_t__ vm_size_t ;
typedef  int vm_offset_t ;
typedef  int /*<<< orphan*/  mmu_t ;

/* Variables and functions */
 int PAGE_MASK ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  kva_free (int,scalar_t__) ; 
 scalar_t__ roundup2 (scalar_t__,int /*<<< orphan*/ ) ; 
 int trunc_page (int) ; 

void
moea64_unmapdev(mmu_t mmu, vm_offset_t va, vm_size_t size)
{
	vm_offset_t base, offset;

	base = trunc_page(va);
	offset = va & PAGE_MASK;
	size = roundup2(offset + size, PAGE_SIZE);

	kva_free(base, size);
}