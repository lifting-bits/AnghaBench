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
typedef  int /*<<< orphan*/  spa_t ;

/* Variables and functions */
 int /*<<< orphan*/  spa_syncing_txg (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  summary_add_data (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

void
spa_log_summary_add_flushed_metaslab(spa_t *spa)
{
	summary_add_data(spa, spa_syncing_txg(spa), 1, 0);
}