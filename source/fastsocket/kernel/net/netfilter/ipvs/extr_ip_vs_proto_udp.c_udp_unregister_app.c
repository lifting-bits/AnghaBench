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
struct ip_vs_app {int /*<<< orphan*/  p_list; } ;
struct TYPE_2__ {int /*<<< orphan*/  appcnt; } ;

/* Variables and functions */
 int /*<<< orphan*/  atomic_dec (int /*<<< orphan*/ *) ; 
 TYPE_1__ ip_vs_protocol_udp ; 
 int /*<<< orphan*/  list_del (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  udp_app_lock ; 

__attribute__((used)) static void
udp_unregister_app(struct ip_vs_app *inc)
{
	spin_lock_bh(&udp_app_lock);
	atomic_dec(&ip_vs_protocol_udp.appcnt);
	list_del(&inc->p_list);
	spin_unlock_bh(&udp_app_lock);
}