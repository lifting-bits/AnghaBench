#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  mode_flags; } ;
struct kvm_vcpu {TYPE_1__ arch; } ;

/* Variables and functions */
 int /*<<< orphan*/  GUEST_PHY_EMUL ; 
 scalar_t__ is_physical_mode (struct kvm_vcpu*) ; 
 int /*<<< orphan*/  switch_to_physical_rid (struct kvm_vcpu*) ; 

void recover_if_physical_mode(struct kvm_vcpu *vcpu)
{
	if (is_physical_mode(vcpu))
		switch_to_physical_rid(vcpu);
	vcpu->arch.mode_flags &= ~GUEST_PHY_EMUL;
	return;
}