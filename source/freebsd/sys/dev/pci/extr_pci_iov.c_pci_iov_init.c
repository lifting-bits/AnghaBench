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
typedef  int /*<<< orphan*/  uint16_t ;
typedef  int /*<<< orphan*/  nvlist_t ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  DRIVER_CONFIG_NAME ; 
 int PCI_IOV_INIT (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  PF_CONFIG_NAME ; 
 int /*<<< orphan*/ * nvlist_get_nvlist (int /*<<< orphan*/  const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
pci_iov_init(device_t dev, uint16_t num_vfs, const nvlist_t *config)
{
	const nvlist_t *device, *driver_config;

	device = nvlist_get_nvlist(config, PF_CONFIG_NAME);
	driver_config = nvlist_get_nvlist(device, DRIVER_CONFIG_NAME);
	return (PCI_IOV_INIT(dev, num_vfs, driver_config));
}