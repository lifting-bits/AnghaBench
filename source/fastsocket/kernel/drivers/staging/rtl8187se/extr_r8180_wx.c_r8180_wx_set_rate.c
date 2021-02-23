#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  union iwreq_data {int dummy; } iwreq_data ;
struct r8180_priv {int /*<<< orphan*/  wx_sem; TYPE_1__* ieee80211; } ;
struct net_device {int dummy; } ;
struct iw_request_info {int dummy; } ;
struct TYPE_2__ {scalar_t__ bHwRadioOff; } ;

/* Variables and functions */
 int /*<<< orphan*/  down (int /*<<< orphan*/ *) ; 
 struct r8180_priv* ieee80211_priv (struct net_device*) ; 
 int ieee80211_wx_set_rate (TYPE_1__*,struct iw_request_info*,union iwreq_data*,char*) ; 
 int /*<<< orphan*/  up (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int r8180_wx_set_rate(struct net_device *dev,
			     struct iw_request_info *info,
			     union iwreq_data *wrqu, char *extra)
{
	int ret;
	struct r8180_priv *priv = ieee80211_priv(dev);


	if(priv->ieee80211->bHwRadioOff)
		return 0;

	down(&priv->wx_sem);

	ret = ieee80211_wx_set_rate(priv->ieee80211,info,wrqu,extra);

	up(&priv->wx_sem);

	return ret;
}