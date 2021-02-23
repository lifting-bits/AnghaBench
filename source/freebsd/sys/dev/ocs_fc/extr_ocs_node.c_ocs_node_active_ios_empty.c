#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  active_ios_lock; int /*<<< orphan*/  active_ios; } ;
typedef  TYPE_1__ ocs_node_t ;

/* Variables and functions */
 int ocs_list_empty (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ocs_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ocs_unlock (int /*<<< orphan*/ *) ; 

int
ocs_node_active_ios_empty(ocs_node_t *node)
{
	int empty;

	ocs_lock(&node->active_ios_lock);
		empty = ocs_list_empty(&node->active_ios);
	ocs_unlock(&node->active_ios_lock);
	return empty;
}