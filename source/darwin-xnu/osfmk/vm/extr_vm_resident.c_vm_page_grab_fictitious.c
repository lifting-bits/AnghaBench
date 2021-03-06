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
typedef  int /*<<< orphan*/  vm_page_t ;

/* Variables and functions */
 int /*<<< orphan*/  vm_page_fictitious_addr ; 
 int /*<<< orphan*/  vm_page_grab_fictitious_common (int /*<<< orphan*/ ) ; 

vm_page_t
vm_page_grab_fictitious(void)
{
	return vm_page_grab_fictitious_common(vm_page_fictitious_addr);
}