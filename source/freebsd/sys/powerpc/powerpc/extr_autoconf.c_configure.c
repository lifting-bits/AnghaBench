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

/* Variables and functions */
 scalar_t__ isa_bus_device ; 
 int /*<<< orphan*/  isa_probe_children (scalar_t__) ; 
 int /*<<< orphan*/  root_bus_configure () ; 

__attribute__((used)) static void
configure(void *dummy)
{

	root_bus_configure();
#ifdef DEV_ISA
	if (isa_bus_device)
		isa_probe_children(isa_bus_device);
#endif
}