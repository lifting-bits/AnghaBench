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
typedef  size_t uint32_t ;
struct alpine_serdes_eth_group_mode {int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 struct alpine_serdes_eth_group_mode* alpine_serdes_eth_group_mode ; 
 scalar_t__ mtx_initialized (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mtx_lock (int /*<<< orphan*/ *) ; 

void
alpine_serdes_eth_group_lock(uint32_t group)
{
	struct alpine_serdes_eth_group_mode *group_mode;

	group_mode = &alpine_serdes_eth_group_mode[group];

	if (mtx_initialized(&group_mode->lock) == 0)
		return;

	mtx_lock(&group_mode->lock);
}