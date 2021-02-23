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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct sk_buff {int dummy; } ;
struct nlmsghdr {int dummy; } ;
struct nlattr {int dummy; } ;
struct net_device {TYPE_1__* dcbnl_ops; } ;
struct dcbmsg {int /*<<< orphan*/  cmd; int /*<<< orphan*/  dcb_family; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* getpfccfg ) (struct net_device*,int,int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  AF_UNSPEC ; 
 size_t DCB_ATTR_PFC_CFG ; 
 int /*<<< orphan*/  DCB_CMD_PFC_GCFG ; 
 int DCB_PFC_UP_ATTR_0 ; 
 int DCB_PFC_UP_ATTR_7 ; 
 size_t DCB_PFC_UP_ATTR_ALL ; 
 int /*<<< orphan*/  DCB_PFC_UP_ATTR_MAX ; 
 int EINVAL ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 struct dcbmsg* NLMSG_DATA (struct nlmsghdr*) ; 
 int /*<<< orphan*/  NLMSG_DEFAULT_SIZE ; 
 struct nlmsghdr* NLMSG_NEW (struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RTM_GETDCB ; 
 int /*<<< orphan*/  dcbnl_pfc_up_nest ; 
 int /*<<< orphan*/  init_net ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  nla_nest_cancel (struct sk_buff*,struct nlattr*) ; 
 int /*<<< orphan*/  nla_nest_end (struct sk_buff*,struct nlattr*) ; 
 struct nlattr* nla_nest_start (struct sk_buff*,size_t) ; 
 int nla_parse_nested (struct nlattr**,int /*<<< orphan*/ ,struct nlattr*,int /*<<< orphan*/ ) ; 
 int nla_put_u8 (struct sk_buff*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nlmsg_end (struct sk_buff*,struct nlmsghdr*) ; 
 struct sk_buff* nlmsg_new (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int rtnl_unicast (struct sk_buff*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct net_device*,int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int dcbnl_getpfccfg(struct net_device *netdev, struct nlattr **tb,
                           u32 pid, u32 seq, u16 flags)
{
	struct sk_buff *dcbnl_skb;
	struct nlmsghdr *nlh;
	struct dcbmsg *dcb;
	struct nlattr *data[DCB_PFC_UP_ATTR_MAX + 1], *nest;
	u8 value;
	int ret = -EINVAL;
	int i;
	int getall = 0;

	if (!tb[DCB_ATTR_PFC_CFG] || !netdev->dcbnl_ops->getpfccfg)
		return ret;

	ret = nla_parse_nested(data, DCB_PFC_UP_ATTR_MAX,
	                       tb[DCB_ATTR_PFC_CFG],
	                       dcbnl_pfc_up_nest);
	if (ret)
		goto err_out;

	dcbnl_skb = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
	if (!dcbnl_skb)
		goto err_out;

	nlh = NLMSG_NEW(dcbnl_skb, pid, seq, RTM_GETDCB, sizeof(*dcb), flags);

	dcb = NLMSG_DATA(nlh);
	dcb->dcb_family = AF_UNSPEC;
	dcb->cmd = DCB_CMD_PFC_GCFG;

	nest = nla_nest_start(dcbnl_skb, DCB_ATTR_PFC_CFG);
	if (!nest)
		goto err;

	if (data[DCB_PFC_UP_ATTR_ALL])
		getall = 1;

	for (i = DCB_PFC_UP_ATTR_0; i <= DCB_PFC_UP_ATTR_7; i++) {
		if (!getall && !data[i])
			continue;

		netdev->dcbnl_ops->getpfccfg(netdev, i - DCB_PFC_UP_ATTR_0,
		                             &value);
		ret = nla_put_u8(dcbnl_skb, i, value);

		if (ret) {
			nla_nest_cancel(dcbnl_skb, nest);
			goto err;
		}
	}
	nla_nest_end(dcbnl_skb, nest);

	nlmsg_end(dcbnl_skb, nlh);

	ret = rtnl_unicast(dcbnl_skb, &init_net, pid);
	if (ret)
		goto err_out;

	return 0;
nlmsg_failure:
err:
	kfree_skb(dcbnl_skb);
err_out:
	return -EINVAL;
}