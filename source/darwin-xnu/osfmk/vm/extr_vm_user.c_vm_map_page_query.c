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
typedef  scalar_t__ vm_map_t ;
typedef  int /*<<< orphan*/  kern_return_t ;

/* Variables and functions */
 int /*<<< orphan*/  KERN_INVALID_ARGUMENT ; 
 int /*<<< orphan*/  PAGE_MASK ; 
 scalar_t__ VM_MAP_NULL ; 
 int /*<<< orphan*/  vm_map_page_query_internal (scalar_t__,int /*<<< orphan*/ ,int*,int*) ; 
 int /*<<< orphan*/  vm_map_trunc_page (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

kern_return_t
vm_map_page_query(
	vm_map_t		map,
	vm_offset_t		offset,
	int			*disposition,
	int			*ref_count)
{
	if (VM_MAP_NULL == map)
		return KERN_INVALID_ARGUMENT;

	return vm_map_page_query_internal(
		map,
		vm_map_trunc_page(offset, PAGE_MASK),
		disposition, ref_count);
}