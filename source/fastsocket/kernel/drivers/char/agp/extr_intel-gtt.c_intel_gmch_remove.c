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
struct TYPE_2__ {int /*<<< orphan*/ * driver; scalar_t__ bridge_dev; scalar_t__ pcidev; scalar_t__ refcount; } ;

/* Variables and functions */
 TYPE_1__ intel_private ; 
 int /*<<< orphan*/  pci_dev_put (scalar_t__) ; 

void intel_gmch_remove(void)
{
	if (--intel_private.refcount)
		return;

	if (intel_private.pcidev)
		pci_dev_put(intel_private.pcidev);
	if (intel_private.bridge_dev)
		pci_dev_put(intel_private.bridge_dev);
	intel_private.driver = NULL;
}