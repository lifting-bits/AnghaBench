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
typedef  int /*<<< orphan*/  vm_offset_t ;

/* Variables and functions */
 int /*<<< orphan*/  VM_KERNEL_SLIDE (int /*<<< orphan*/ ) ; 

vm_offset_t
ml_static_slide(
	vm_offset_t vaddr)
{
	return VM_KERNEL_SLIDE(vaddr);
}