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
typedef  int /*<<< orphan*/  kvm_t ;

/* Variables and functions */
 int /*<<< orphan*/  ELFCLASS32 ; 
 int /*<<< orphan*/  EM_ARM ; 
 scalar_t__ _kvm_is_minidump (int /*<<< orphan*/ *) ; 
 scalar_t__ _kvm_probe_elf_kernel (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
_arm_minidump_probe(kvm_t *kd)
{

	return (_kvm_probe_elf_kernel(kd, ELFCLASS32, EM_ARM) &&
	    _kvm_is_minidump(kd));
}