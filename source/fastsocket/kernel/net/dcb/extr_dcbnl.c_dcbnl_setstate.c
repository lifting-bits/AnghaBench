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
struct nlattr {int dummy; } ;
struct net_device {TYPE_1__* dcbnl_ops; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* setstate ) (struct net_device*,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 size_t DCB_ATTR_STATE ; 
 int /*<<< orphan*/  DCB_CMD_SSTATE ; 
 int EINVAL ; 
 int /*<<< orphan*/  RTM_SETDCB ; 
 int dcbnl_reply (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nla_get_u8 (struct nlattr*) ; 
 int /*<<< orphan*/  stub1 (struct net_device*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int dcbnl_setstate(struct net_device *netdev, struct nlattr **tb,
                          u32 pid, u32 seq, u16 flags)
{
	int ret = -EINVAL;
	u8 value;

	if (!tb[DCB_ATTR_STATE] || !netdev->dcbnl_ops->setstate)
		return ret;

	value = nla_get_u8(tb[DCB_ATTR_STATE]);

	ret = dcbnl_reply(netdev->dcbnl_ops->setstate(netdev, value),
	                  RTM_SETDCB, DCB_CMD_SSTATE, DCB_ATTR_STATE,
	                  pid, seq, flags);

	return ret;
}