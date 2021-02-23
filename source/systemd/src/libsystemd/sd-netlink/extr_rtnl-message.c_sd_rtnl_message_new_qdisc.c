#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_6__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint16_t ;
struct tcmsg {int tcm_family; int tcm_ifindex; } ;
struct TYPE_7__ {TYPE_6__* hdr; } ;
typedef  TYPE_1__ sd_netlink_message ;
typedef  int /*<<< orphan*/  sd_netlink ;
struct TYPE_8__ {int nlmsg_flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 struct tcmsg* NLMSG_DATA (TYPE_6__*) ; 
 int NLM_F_CREATE ; 
 int NLM_F_EXCL ; 
 scalar_t__ RTM_NEWQDISC ; 
 int /*<<< orphan*/  assert_return (TYPE_1__**,int /*<<< orphan*/ ) ; 
 int message_new (int /*<<< orphan*/ *,TYPE_1__**,scalar_t__) ; 
 TYPE_1__** rtnl_message_type_is_qdisc (scalar_t__) ; 

int sd_rtnl_message_new_qdisc(sd_netlink *rtnl, sd_netlink_message **ret, uint16_t nlmsg_type, int tcm_family, int tcm_ifindex) {
        struct tcmsg *tcm;
        int r;

        assert_return(rtnl_message_type_is_qdisc(nlmsg_type), -EINVAL);
        assert_return(ret, -EINVAL);

        r = message_new(rtnl, ret, nlmsg_type);
        if (r < 0)
                return r;

        if (nlmsg_type == RTM_NEWQDISC)
                (*ret)->hdr->nlmsg_flags |= NLM_F_CREATE | NLM_F_EXCL;

        tcm = NLMSG_DATA((*ret)->hdr);
        tcm->tcm_family = tcm_family;
        tcm->tcm_ifindex = tcm_ifindex;

        return 0;
}