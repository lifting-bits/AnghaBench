#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  acd; } ;
typedef  TYPE_1__ sd_ipv4ll ;
typedef  int /*<<< orphan*/  sd_event ;
typedef  int /*<<< orphan*/  int64_t ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  assert_return (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int sd_ipv4acd_attach_event (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

int sd_ipv4ll_attach_event(sd_ipv4ll *ll, sd_event *event, int64_t priority) {
        assert_return(ll, -EINVAL);

        return sd_ipv4acd_attach_event(ll->acd, event, priority);
}