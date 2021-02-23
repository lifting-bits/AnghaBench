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

/* Variables and functions */
 int /*<<< orphan*/  SLIST_INIT (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  free_gtask ; 
 int /*<<< orphan*/  in6m_free_list ; 
 int /*<<< orphan*/  in6m_release_task ; 
 int /*<<< orphan*/  taskqgroup_config_gtask_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static void in6m_init(void)
{
	SLIST_INIT(&in6m_free_list);
	taskqgroup_config_gtask_init(NULL, &free_gtask, in6m_release_task, "in6m release task");
}