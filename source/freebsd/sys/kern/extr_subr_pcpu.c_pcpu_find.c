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
typedef  size_t u_int ;
struct pcpu {int dummy; } ;

/* Variables and functions */
 struct pcpu** cpuid_to_pcpu ; 

struct pcpu *
pcpu_find(u_int cpuid)
{

	return (cpuid_to_pcpu[cpuid]);
}