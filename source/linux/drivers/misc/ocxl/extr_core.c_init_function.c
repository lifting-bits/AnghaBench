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
struct pci_dev {int dummy; } ;
struct ocxl_fn {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int ENOMEM ; 
 struct ocxl_fn* ERR_PTR (int) ; 
 struct ocxl_fn* alloc_function () ; 
 int configure_function (struct ocxl_fn*,struct pci_dev*) ; 
 int /*<<< orphan*/  deconfigure_function (struct ocxl_fn*) ; 
 int device_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  free_function (struct ocxl_fn*) ; 
 int /*<<< orphan*/  put_device (int /*<<< orphan*/ *) ; 

__attribute__((used)) static struct ocxl_fn *init_function(struct pci_dev *dev)
{
	struct ocxl_fn *fn;
	int rc;

	fn = alloc_function();
	if (!fn)
		return ERR_PTR(-ENOMEM);

	rc = configure_function(fn, dev);
	if (rc) {
		free_function(fn);
		return ERR_PTR(rc);
	}

	rc = device_register(&fn->dev);
	if (rc) {
		deconfigure_function(fn);
		put_device(&fn->dev);
		return ERR_PTR(rc);
	}
	return fn;
}