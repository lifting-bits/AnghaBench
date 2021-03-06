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
typedef  scalar_t__ u32 ;
struct vgic_irq {int pending_latch; int /*<<< orphan*/  irq_lock; } ;
struct kvm_vcpu {int /*<<< orphan*/  kvm; } ;
typedef  int /*<<< orphan*/  gpa_t ;

/* Variables and functions */
 scalar_t__ VGIC_ADDR_TO_INTID (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  raw_spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  raw_spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 scalar_t__ test_bit (int,unsigned long*) ; 
 struct vgic_irq* vgic_get_irq (int /*<<< orphan*/ ,struct kvm_vcpu*,scalar_t__) ; 
 int /*<<< orphan*/  vgic_put_irq (int /*<<< orphan*/ ,struct vgic_irq*) ; 
 int /*<<< orphan*/  vgic_queue_irq_unlock (int /*<<< orphan*/ ,struct vgic_irq*,unsigned long) ; 

__attribute__((used)) static int vgic_v3_uaccess_write_pending(struct kvm_vcpu *vcpu,
					 gpa_t addr, unsigned int len,
					 unsigned long val)
{
	u32 intid = VGIC_ADDR_TO_INTID(addr, 1);
	int i;
	unsigned long flags;

	for (i = 0; i < len * 8; i++) {
		struct vgic_irq *irq = vgic_get_irq(vcpu->kvm, vcpu, intid + i);

		raw_spin_lock_irqsave(&irq->irq_lock, flags);
		if (test_bit(i, &val)) {
			/*
			 * pending_latch is set irrespective of irq type
			 * (level or edge) to avoid dependency that VM should
			 * restore irq config before pending info.
			 */
			irq->pending_latch = true;
			vgic_queue_irq_unlock(vcpu->kvm, irq, flags);
		} else {
			irq->pending_latch = false;
			raw_spin_unlock_irqrestore(&irq->irq_lock, flags);
		}

		vgic_put_irq(vcpu->kvm, irq);
	}

	return 0;
}