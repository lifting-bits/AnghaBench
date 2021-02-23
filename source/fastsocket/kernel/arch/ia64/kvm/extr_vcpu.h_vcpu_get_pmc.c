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
typedef  int /*<<< orphan*/  u64 ;
struct kvm_vcpu {int dummy; } ;

/* Variables and functions */
 scalar_t__ ia64_get_pmc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline u64 vcpu_get_pmc(struct kvm_vcpu *vcpu, u64 reg)
{
	/* NOTE: Reads from unimplemented PMC registers return zero */
	return ((u64)ia64_get_pmc(reg));
}