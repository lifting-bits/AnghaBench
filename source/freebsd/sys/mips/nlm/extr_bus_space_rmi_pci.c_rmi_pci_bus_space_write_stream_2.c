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
typedef  int /*<<< orphan*/  u_int16_t ;
typedef  scalar_t__ bus_space_handle_t ;
typedef  scalar_t__ bus_size_t ;

/* Variables and functions */
 int /*<<< orphan*/  mips_sync () ; 

__attribute__((used)) static void
rmi_pci_bus_space_write_stream_2(void *t, bus_space_handle_t handle,
    bus_size_t offset, u_int16_t value)
{
	mips_sync();
	*(volatile u_int16_t *)(handle + offset) = value;
}