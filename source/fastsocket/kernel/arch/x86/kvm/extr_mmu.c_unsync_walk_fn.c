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
struct kvm_vcpu {int dummy; } ;
struct kvm_mmu_page {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  kvm_mmu_update_parents_unsync (struct kvm_mmu_page*) ; 

__attribute__((used)) static int unsync_walk_fn(struct kvm_vcpu *vcpu, struct kvm_mmu_page *sp)
{
	kvm_mmu_update_parents_unsync(sp);
	return 1;
}