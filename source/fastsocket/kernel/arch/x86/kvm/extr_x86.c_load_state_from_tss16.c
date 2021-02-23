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
struct tss_segment_16 {int flag; int /*<<< orphan*/  ds; int /*<<< orphan*/  ss; int /*<<< orphan*/  cs; int /*<<< orphan*/  es; int /*<<< orphan*/  ldt; int /*<<< orphan*/  di; int /*<<< orphan*/  si; int /*<<< orphan*/  bp; int /*<<< orphan*/  sp; int /*<<< orphan*/  bx; int /*<<< orphan*/  dx; int /*<<< orphan*/  cx; int /*<<< orphan*/  ax; int /*<<< orphan*/  ip; } ;
struct kvm_vcpu {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* set_rflags ) (struct kvm_vcpu*,int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  VCPU_REGS_RAX ; 
 int /*<<< orphan*/  VCPU_REGS_RBP ; 
 int /*<<< orphan*/  VCPU_REGS_RBX ; 
 int /*<<< orphan*/  VCPU_REGS_RCX ; 
 int /*<<< orphan*/  VCPU_REGS_RDI ; 
 int /*<<< orphan*/  VCPU_REGS_RDX ; 
 int /*<<< orphan*/  VCPU_REGS_RSI ; 
 int /*<<< orphan*/  VCPU_REGS_RSP ; 
 int /*<<< orphan*/  VCPU_SREG_CS ; 
 int /*<<< orphan*/  VCPU_SREG_DS ; 
 int /*<<< orphan*/  VCPU_SREG_ES ; 
 int /*<<< orphan*/  VCPU_SREG_LDTR ; 
 int /*<<< orphan*/  VCPU_SREG_SS ; 
 scalar_t__ kvm_load_segment_descriptor (struct kvm_vcpu*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kvm_load_segment_selector (struct kvm_vcpu*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kvm_register_write (struct kvm_vcpu*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kvm_rip_write (struct kvm_vcpu*,int /*<<< orphan*/ ) ; 
 TYPE_1__* kvm_x86_ops ; 
 int /*<<< orphan*/  stub1 (struct kvm_vcpu*,int) ; 

__attribute__((used)) static int load_state_from_tss16(struct kvm_vcpu *vcpu,
				 struct tss_segment_16 *tss)
{
	kvm_rip_write(vcpu, tss->ip);
	kvm_x86_ops->set_rflags(vcpu, tss->flag | 2);
	kvm_register_write(vcpu, VCPU_REGS_RAX, tss->ax);
	kvm_register_write(vcpu, VCPU_REGS_RCX, tss->cx);
	kvm_register_write(vcpu, VCPU_REGS_RDX, tss->dx);
	kvm_register_write(vcpu, VCPU_REGS_RBX, tss->bx);
	kvm_register_write(vcpu, VCPU_REGS_RSP, tss->sp);
	kvm_register_write(vcpu, VCPU_REGS_RBP, tss->bp);
	kvm_register_write(vcpu, VCPU_REGS_RSI, tss->si);
	kvm_register_write(vcpu, VCPU_REGS_RDI, tss->di);

	/*
	 * SDM says that segment selectors are loaded before segment
	 * descriptors
	 */
	kvm_load_segment_selector(vcpu, tss->ldt, VCPU_SREG_LDTR);
	kvm_load_segment_selector(vcpu, tss->es, VCPU_SREG_ES);
	kvm_load_segment_selector(vcpu, tss->cs, VCPU_SREG_CS);
	kvm_load_segment_selector(vcpu, tss->ss, VCPU_SREG_SS);
	kvm_load_segment_selector(vcpu, tss->ds, VCPU_SREG_DS);

	/*
	 * Now load segment descriptors. If fault happenes at this stage
	 * it is handled in a context of new task
	 */
	if (kvm_load_segment_descriptor(vcpu, tss->ldt, VCPU_SREG_LDTR))
		return 1;

	if (kvm_load_segment_descriptor(vcpu, tss->es, VCPU_SREG_ES))
		return 1;

	if (kvm_load_segment_descriptor(vcpu, tss->cs, VCPU_SREG_CS))
		return 1;

	if (kvm_load_segment_descriptor(vcpu, tss->ss, VCPU_SREG_SS))
		return 1;

	if (kvm_load_segment_descriptor(vcpu, tss->ds, VCPU_SREG_DS))
		return 1;
	return 0;
}