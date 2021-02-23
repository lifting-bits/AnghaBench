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
struct TYPE_2__ {int /*<<< orphan*/  length; } ;
union iwreq_data {TYPE_1__ data; } ;
struct r8192_priv {int /*<<< orphan*/  wx_sem; int /*<<< orphan*/  ieee80211; } ;
struct net_device {int dummy; } ;
struct iw_request_info {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  down (int /*<<< orphan*/ *) ; 
 struct r8192_priv* ieee80211_priv (struct net_device*) ; 
 int ieee80211_wx_set_gen_ie (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  up (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int r8192_wx_set_gen_ie(struct net_device *dev,
                                        struct iw_request_info *info,
                                        union iwreq_data *data, char *extra)
{
	   //printk("====>%s(), len:%d\n", __FUNCTION__, data->length);
	int ret=0;
        struct r8192_priv *priv = ieee80211_priv(dev);
        down(&priv->wx_sem);
#if 1
        ret = ieee80211_wx_set_gen_ie(priv->ieee80211, extra, data->data.length);
#endif
        up(&priv->wx_sem);
	//printk("<======%s(), ret:%d\n", __FUNCTION__, ret);
        return ret;


}