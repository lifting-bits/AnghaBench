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
struct die_args {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  cpu_emergency_vmxoff () ; 

__attribute__((used)) static void vmxoff_nmi(int cpu, struct die_args *args)
{
	cpu_emergency_vmxoff();
}