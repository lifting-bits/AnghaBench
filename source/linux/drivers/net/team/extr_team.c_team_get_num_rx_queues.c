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
 unsigned int TEAM_DEFAULT_NUM_RX_QUEUES ; 

__attribute__((used)) static unsigned int team_get_num_rx_queues(void)
{
	return TEAM_DEFAULT_NUM_RX_QUEUES;
}