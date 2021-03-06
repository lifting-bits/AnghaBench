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
struct hostapd_data {int /*<<< orphan*/  drv_priv; TYPE_1__* driver; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* send_action_cancel_wait ) (int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void
hostapd_drv_send_action_cancel_wait(struct hostapd_data *hapd)
{
	if (!hapd->driver || !hapd->driver->send_action_cancel_wait ||
	    !hapd->drv_priv)
		return;
	hapd->driver->send_action_cancel_wait(hapd->drv_priv);
}