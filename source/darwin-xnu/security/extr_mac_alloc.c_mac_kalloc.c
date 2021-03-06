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
typedef  int /*<<< orphan*/  vm_size_t ;

/* Variables and functions */
 int M_WAITOK ; 
 void* kalloc (int /*<<< orphan*/ ) ; 
 void* kalloc_noblock (int /*<<< orphan*/ ) ; 

void *
mac_kalloc(vm_size_t size, int how)
{

	if (how == M_WAITOK)
		return kalloc(size);
	else
		return kalloc_noblock(size);
}