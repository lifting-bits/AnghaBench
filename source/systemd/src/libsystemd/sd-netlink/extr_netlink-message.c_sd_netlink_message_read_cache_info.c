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
struct ifa_cacheinfo {int dummy; } ;
typedef  int /*<<< orphan*/  sd_netlink_message ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 int EIO ; 
 int /*<<< orphan*/  NETLINK_TYPE_CACHE_INFO ; 
 int /*<<< orphan*/  assert_return (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (struct ifa_cacheinfo*,void*,int) ; 
 int message_attribute_has_type (int /*<<< orphan*/ *,int /*<<< orphan*/ *,unsigned short,int /*<<< orphan*/ ) ; 
 int netlink_message_read_internal (int /*<<< orphan*/ *,unsigned short,void**,int /*<<< orphan*/ *) ; 

int sd_netlink_message_read_cache_info(sd_netlink_message *m, unsigned short type, struct ifa_cacheinfo *info) {
        int r;
        void *attr_data;

        assert_return(m, -EINVAL);

        r = message_attribute_has_type(m, NULL, type, NETLINK_TYPE_CACHE_INFO);
        if (r < 0)
                return r;

        r = netlink_message_read_internal(m, type, &attr_data, NULL);
        if (r < 0)
                return r;
        else if ((size_t)r < sizeof(struct ifa_cacheinfo))
                return -EIO;

        if (info)
                memcpy(info, attr_data, sizeof(struct ifa_cacheinfo));

        return 0;
}