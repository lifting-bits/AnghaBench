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
struct TYPE_2__ {int device_id; } ;
struct tb_switch {TYPE_1__ config; } ;

/* Variables and functions */
#define  PCI_DEVICE_ID_INTEL_FALCON_RIDGE_2C_BRIDGE 129 
#define  PCI_DEVICE_ID_INTEL_FALCON_RIDGE_4C_BRIDGE 128 

__attribute__((used)) static inline bool tb_switch_is_fr(const struct tb_switch *sw)
{
	switch (sw->config.device_id) {
	case PCI_DEVICE_ID_INTEL_FALCON_RIDGE_2C_BRIDGE:
	case PCI_DEVICE_ID_INTEL_FALCON_RIDGE_4C_BRIDGE:
		return true;
	default:
		return false;
	}
}