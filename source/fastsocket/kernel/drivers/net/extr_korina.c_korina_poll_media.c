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
struct net_device {int dummy; } ;
struct korina_private {int /*<<< orphan*/  media_check_timer; } ;

/* Variables and functions */
 scalar_t__ HZ ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  korina_check_media (struct net_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 
 struct korina_private* netdev_priv (struct net_device*) ; 

__attribute__((used)) static void korina_poll_media(unsigned long data)
{
	struct net_device *dev = (struct net_device *) data;
	struct korina_private *lp = netdev_priv(dev);

	korina_check_media(dev, 0);
	mod_timer(&lp->media_check_timer, jiffies + HZ);
}