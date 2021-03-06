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
struct drm_device {int /*<<< orphan*/  pdev; } ;

/* Variables and functions */
 int drm_vblank_init (struct drm_device*,int) ; 
 int /*<<< orphan*/  pci_set_master (int /*<<< orphan*/ ) ; 

int r128_driver_load(struct drm_device *dev, unsigned long flags)
{
	pci_set_master(dev->pdev);
	return drm_vblank_init(dev, 1);
}