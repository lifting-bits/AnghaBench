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
struct uwb_dev_addr {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  mutex; struct uwb_dev_addr dev_addr; } ;
struct uwb_rc {TYPE_1__ uwb_dev; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  UWB_ADDR_DEV ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int uwb_rc_addr_set (struct uwb_rc*,struct uwb_dev_addr const*,int /*<<< orphan*/ ) ; 

int uwb_rc_dev_addr_set(struct uwb_rc *rc,
			const struct uwb_dev_addr *addr)
{
	int result = -EINVAL;
	mutex_lock(&rc->uwb_dev.mutex);
	result = uwb_rc_addr_set(rc, addr, UWB_ADDR_DEV);
	rc->uwb_dev.dev_addr = *addr;
	mutex_unlock(&rc->uwb_dev.mutex);
	return result;
}