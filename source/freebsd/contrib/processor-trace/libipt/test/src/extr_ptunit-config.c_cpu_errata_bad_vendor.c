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
struct ptunit_result {int dummy; } ;
struct pt_errata {int dummy; } ;
struct pt_cpu {int vendor; } ;
typedef  enum pt_cpu_vendor { ____Placeholder_pt_cpu_vendor } pt_cpu_vendor ;
typedef  int /*<<< orphan*/  cpu ;

/* Variables and functions */
 int /*<<< orphan*/  memset (struct pt_cpu*,int /*<<< orphan*/ ,int) ; 
 int pt_cpu_errata (struct pt_errata*,struct pt_cpu*) ; 
 int /*<<< orphan*/  pte_bad_cpu ; 
 int /*<<< orphan*/  ptu_int_eq (int,int /*<<< orphan*/ ) ; 
 struct ptunit_result ptu_passed () ; 

__attribute__((used)) static struct ptunit_result cpu_errata_bad_vendor(void)
{
	struct pt_errata errata;
	struct pt_cpu cpu;
	int errcode;

	memset(&cpu, 0, sizeof(cpu));
	cpu.vendor = (enum pt_cpu_vendor) 0xffff;

	errcode = pt_cpu_errata(&errata, &cpu);
	ptu_int_eq(errcode, -pte_bad_cpu);

	return ptu_passed();
}