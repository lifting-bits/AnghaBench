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
typedef  int /*<<< orphan*/  uint64_t ;
struct svm_softc {int /*<<< orphan*/  vm; } ;
typedef  int /*<<< orphan*/  register_t ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  VCPU_CTR1 (int /*<<< orphan*/ ,int,char*,int) ; 
 int VM_REG_GUEST_INTR_SHADOW ; 
 int /*<<< orphan*/  svm_get_guest_regctx (struct svm_softc*,int) ; 
 int svm_get_intr_shadow (struct svm_softc*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * swctx_regptr (int /*<<< orphan*/ ,int) ; 
 scalar_t__ vmcb_read (struct svm_softc*,int,int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int
svm_getreg(void *arg, int vcpu, int ident, uint64_t *val)
{
	struct svm_softc *svm_sc;
	register_t *reg;

	svm_sc = arg;

	if (ident == VM_REG_GUEST_INTR_SHADOW) {
		return (svm_get_intr_shadow(svm_sc, vcpu, val));
	}

	if (vmcb_read(svm_sc, vcpu, ident, val) == 0) {
		return (0);
	}

	reg = swctx_regptr(svm_get_guest_regctx(svm_sc, vcpu), ident);

	if (reg != NULL) {
		*val = *reg;
		return (0);
	}

	VCPU_CTR1(svm_sc->vm, vcpu, "svm_getreg: unknown register %#x", ident);
	return (EINVAL);
}