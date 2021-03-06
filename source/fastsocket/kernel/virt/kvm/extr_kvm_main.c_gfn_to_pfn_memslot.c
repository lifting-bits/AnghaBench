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
struct kvm_memory_slot {int dummy; } ;
struct kvm {int dummy; } ;
typedef  int /*<<< orphan*/  pfn_t ;
typedef  int /*<<< orphan*/  gfn_t ;

/* Variables and functions */
 unsigned long gfn_to_hva_memslot (struct kvm_memory_slot*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hva_to_pfn (struct kvm*,unsigned long) ; 

pfn_t gfn_to_pfn_memslot(struct kvm *kvm,
			 struct kvm_memory_slot *slot, gfn_t gfn)
{
	unsigned long addr = gfn_to_hva_memslot(slot, gfn);
	return hva_to_pfn(kvm, addr);
}