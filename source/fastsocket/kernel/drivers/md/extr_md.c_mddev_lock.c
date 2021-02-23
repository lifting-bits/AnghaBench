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
struct mddev {int /*<<< orphan*/  reconfig_mutex; } ;

/* Variables and functions */
 int mutex_lock_interruptible (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline int mddev_lock(struct mddev * mddev)
{
	return mutex_lock_interruptible(&mddev->reconfig_mutex);
}