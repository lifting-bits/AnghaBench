#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint32_t ;
typedef  TYPE_1__* ocs_os_handle_t ;
struct TYPE_3__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  pci_read_config (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

uint32_t
ocs_config_read32(ocs_os_handle_t os, uint32_t reg)
{
	return pci_read_config(os->dev, reg, 4);
}