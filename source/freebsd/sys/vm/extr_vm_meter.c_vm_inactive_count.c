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
typedef  int /*<<< orphan*/  u_int ;

/* Variables and functions */
 int /*<<< orphan*/  PQ_INACTIVE ; 
 int /*<<< orphan*/  vm_pagequeue_count (int /*<<< orphan*/ ) ; 

u_int
vm_inactive_count(void)
{

	return (vm_pagequeue_count(PQ_INACTIVE));
}