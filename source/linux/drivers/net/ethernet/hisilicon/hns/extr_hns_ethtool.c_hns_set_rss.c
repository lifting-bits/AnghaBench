#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
struct net_device {int dummy; } ;
struct hns_nic_priv {TYPE_2__* ae_handle; int /*<<< orphan*/  enet_ver; } ;
struct hnae_ae_ops {int (* set_rss ) (TYPE_2__*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const) ;} ;
struct TYPE_4__ {TYPE_1__* dev; } ;
struct TYPE_3__ {struct hnae_ae_ops* ops; } ;

/* Variables and functions */
 scalar_t__ AE_IS_VER1 (int /*<<< orphan*/ ) ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  const ETH_RSS_HASH_NO_CHANGE ; 
 int /*<<< orphan*/  const ETH_RSS_HASH_TOP ; 
 int /*<<< orphan*/  netdev_err (struct net_device*,char*) ; 
 struct hns_nic_priv* netdev_priv (struct net_device*) ; 
 int stub1 (TYPE_2__*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const) ; 

__attribute__((used)) static int
hns_set_rss(struct net_device *netdev, const u32 *indir, const u8 *key,
	    const u8 hfunc)
{
	struct hns_nic_priv *priv = netdev_priv(netdev);
	struct hnae_ae_ops *ops;

	if (AE_IS_VER1(priv->enet_ver)) {
		netdev_err(netdev,
			   "RSS feature is not supported on this hardware\n");
		return -EOPNOTSUPP;
	}

	ops = priv->ae_handle->dev->ops;

	if (hfunc != ETH_RSS_HASH_NO_CHANGE && hfunc != ETH_RSS_HASH_TOP) {
		netdev_err(netdev, "Invalid hfunc!\n");
		return -EOPNOTSUPP;
	}

	return ops->set_rss(priv->ae_handle, indir, key, hfunc);
}