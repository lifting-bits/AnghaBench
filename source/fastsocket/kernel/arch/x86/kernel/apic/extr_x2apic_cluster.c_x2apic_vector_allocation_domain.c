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
struct cpumask {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  cpumask_clear (struct cpumask*) ; 
 int /*<<< orphan*/  cpumask_set_cpu (int,struct cpumask*) ; 

__attribute__((used)) static void x2apic_vector_allocation_domain(int cpu, struct cpumask *retmask)
{
	cpumask_clear(retmask);
	cpumask_set_cpu(cpu, retmask);
}