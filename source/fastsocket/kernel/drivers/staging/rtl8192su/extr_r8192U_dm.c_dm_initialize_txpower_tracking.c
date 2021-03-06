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
struct net_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  dm_InitializeTXPowerTracking_TSSI (struct net_device*) ; 

void dm_initialize_txpower_tracking(struct net_device *dev)
{
#if (defined RTL8190P)
	dm_InitializeTXPowerTracking_TSSI(dev);
#else
	// 2009/01/12 MH Enable for 92S series channel 1-14 CCK tx pwer setting for MP.
	//
	dm_InitializeTXPowerTracking_TSSI(dev);
#endif
}