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
struct net_device {int mtu; } ;

/* Variables and functions */
 int EINVAL ; 
 int IEEE80211_MAX_DATA_LEN ; 

__attribute__((used)) static int ieee80211_change_mtu(struct net_device *dev, int new_mtu)
{
	if (new_mtu < 256 || new_mtu > IEEE80211_MAX_DATA_LEN)
		return -EINVAL;

	dev->mtu = new_mtu;
	return 0;
}