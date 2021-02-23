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

/* Variables and functions */
 int /*<<< orphan*/  ctl_clear_bit (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ma_subclass_lock ; 
 int /*<<< orphan*/  ma_subclass_refcount ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

void measurement_alert_subclass_unregister(void)
{
	spin_lock(&ma_subclass_lock);
	ma_subclass_refcount--;
	if (!ma_subclass_refcount)
		ctl_clear_bit(0, 5);
	spin_unlock(&ma_subclass_lock);
}