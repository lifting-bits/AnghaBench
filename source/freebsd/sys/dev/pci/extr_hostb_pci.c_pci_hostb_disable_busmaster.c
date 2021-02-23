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
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  device_get_nameunit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  device_printf (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int pci_disable_busmaster (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
pci_hostb_disable_busmaster(device_t dev, device_t child)
{

	device_printf(dev, "child %s requested pci_disable_busmaster\n",
	    device_get_nameunit(child));
	return (pci_disable_busmaster(dev));
}