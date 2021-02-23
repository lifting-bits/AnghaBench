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
struct vr_type {scalar_t__ vr_vid; scalar_t__ vr_did; int /*<<< orphan*/ * vr_name; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 scalar_t__ pci_get_device (int /*<<< orphan*/ ) ; 
 scalar_t__ pci_get_vendor (int /*<<< orphan*/ ) ; 
 struct vr_type* vr_devs ; 

__attribute__((used)) static const struct vr_type *
vr_match(device_t dev)
{
	const struct vr_type	*t = vr_devs;

	for (t = vr_devs; t->vr_name != NULL; t++)
		if ((pci_get_vendor(dev) == t->vr_vid) &&
		    (pci_get_device(dev) == t->vr_did))
			return (t);
	return (NULL);
}