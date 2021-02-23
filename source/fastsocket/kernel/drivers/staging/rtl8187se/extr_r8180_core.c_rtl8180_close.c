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
struct r8180_priv {int /*<<< orphan*/  wx_sem; } ;
struct net_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  down (int /*<<< orphan*/ *) ; 
 struct r8180_priv* ieee80211_priv (struct net_device*) ; 
 int rtl8180_down (struct net_device*) ; 
 int /*<<< orphan*/  up (int /*<<< orphan*/ *) ; 

int rtl8180_close(struct net_device *dev)
{
	struct r8180_priv *priv = ieee80211_priv(dev);
	int ret;

	down(&priv->wx_sem);
	ret = rtl8180_down(dev);
	up(&priv->wx_sem);

	return ret;
}