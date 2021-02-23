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
 int ISA_PNP_PROBE (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  device_get_parent (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  device_quiet (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  essc_ids ; 

__attribute__((used)) static int
esscontrol_probe(device_t dev)
{
	int i;

	i = ISA_PNP_PROBE(device_get_parent(dev), dev, essc_ids);
	if (i == 0)
		device_quiet(dev);
	return i;
}