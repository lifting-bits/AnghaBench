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
struct vm_area_struct {int /*<<< orphan*/  vm_mm; int /*<<< orphan*/ * vm_file; } ;

/* Variables and functions */
 int /*<<< orphan*/  fput (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct vm_area_struct*) ; 
 int /*<<< orphan*/  mmput (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
linux_cdev_handle_free(struct vm_area_struct *vmap)
{
	/* Drop reference on vm_file */
	if (vmap->vm_file != NULL)
		fput(vmap->vm_file);

	/* Drop reference on mm_struct */
	mmput(vmap->vm_mm);

	kfree(vmap);
}