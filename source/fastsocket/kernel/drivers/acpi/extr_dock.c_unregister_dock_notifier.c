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
struct notifier_block {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  atomic_notifier_chain_unregister (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int /*<<< orphan*/  dock_notifier_list ; 
 int /*<<< orphan*/  dock_station_count ; 

void unregister_dock_notifier(struct notifier_block *nb)
{
	if (!dock_station_count)
		return;

	atomic_notifier_chain_unregister(&dock_notifier_list, nb);
}