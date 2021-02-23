#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
struct nhmsg {int /*<<< orphan*/  nh_family; } ;
struct TYPE_5__ {struct TYPE_5__ const* hdr; } ;
typedef  TYPE_1__ sd_netlink_message ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 struct nhmsg* NLMSG_DATA (TYPE_1__ const*) ; 
 int /*<<< orphan*/  assert_return (TYPE_1__ const*,int /*<<< orphan*/ ) ; 

int sd_rtnl_message_nexthop_get_family(const sd_netlink_message *m, uint8_t *family) {
        struct nhmsg *nhm;

        assert_return(m, -EINVAL);
        assert_return(m->hdr, -EINVAL);

        nhm = NLMSG_DATA(m->hdr);
        *family = nhm->nh_family ;

        return 0;
}