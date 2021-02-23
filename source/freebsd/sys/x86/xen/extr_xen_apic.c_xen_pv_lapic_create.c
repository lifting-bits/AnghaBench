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
typedef  int /*<<< orphan*/  u_int ;

/* Variables and functions */
 int /*<<< orphan*/  cpu_add (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void
xen_pv_lapic_create(u_int apic_id, int boot_cpu)
{
#ifdef SMP
	cpu_add(apic_id, boot_cpu);
#endif
}