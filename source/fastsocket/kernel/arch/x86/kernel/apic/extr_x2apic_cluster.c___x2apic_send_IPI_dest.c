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
 unsigned long __prepare_ICR (int /*<<< orphan*/ ,int,unsigned int) ; 
 int /*<<< orphan*/  native_x2apic_icr_write (unsigned long,unsigned int) ; 

__attribute__((used)) static void
 __x2apic_send_IPI_dest(unsigned int apicid, int vector, unsigned int dest)
{
	unsigned long cfg;

	cfg = __prepare_ICR(0, vector, dest);

	/*
	 * send the IPI.
	 */
	native_x2apic_icr_write(cfg, apicid);
}