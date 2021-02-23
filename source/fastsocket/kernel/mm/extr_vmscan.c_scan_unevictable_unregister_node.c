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
struct node {int /*<<< orphan*/  sysdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  attr_scan_unevictable_pages ; 
 int /*<<< orphan*/  sysdev_remove_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

void scan_unevictable_unregister_node(struct node *node)
{
	sysdev_remove_file(&node->sysdev, &attr_scan_unevictable_pages);
}