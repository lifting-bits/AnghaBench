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
struct cpu_group {int dummy; } ;

/* Variables and functions */
 struct cpu_group* smp_topo_none () ; 

struct cpu_group *
platform_smp_topo(void)
{

	return (smp_topo_none());
}