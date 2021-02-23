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
typedef  int /*<<< orphan*/  vm_offset_t ;

/* Variables and functions */
 int /*<<< orphan*/  kernel_map ; 
 int /*<<< orphan*/  vm_map_min (int /*<<< orphan*/ ) ; 

vm_offset_t min_valid_stack_address(void)
{
	return (vm_offset_t)vm_map_min(kernel_map);
}