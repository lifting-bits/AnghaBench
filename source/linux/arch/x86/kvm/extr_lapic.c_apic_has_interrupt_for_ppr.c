#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct kvm_lapic {TYPE_2__* vcpu; } ;
struct TYPE_6__ {int (* sync_pir_to_irr ) (TYPE_2__*) ;} ;
struct TYPE_4__ {scalar_t__ apicv_active; } ;
struct TYPE_5__ {TYPE_1__ arch; } ;

/* Variables and functions */
 int apic_find_highest_irr (struct kvm_lapic*) ; 
 TYPE_3__* kvm_x86_ops ; 
 int stub1 (TYPE_2__*) ; 

__attribute__((used)) static int apic_has_interrupt_for_ppr(struct kvm_lapic *apic, u32 ppr)
{
	int highest_irr;
	if (apic->vcpu->arch.apicv_active)
		highest_irr = kvm_x86_ops->sync_pir_to_irr(apic->vcpu);
	else
		highest_irr = apic_find_highest_irr(apic);
	if (highest_irr == -1 || (highest_irr & 0xF0) <= ppr)
		return -1;
	return highest_irr;
}