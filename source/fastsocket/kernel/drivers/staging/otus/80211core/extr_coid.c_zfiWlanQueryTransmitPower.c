#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  zdev_t ;
typedef  int /*<<< orphan*/  u32_t ;
struct TYPE_3__ {int /*<<< orphan*/  connPowerInHalfDbm; } ;
struct TYPE_4__ {TYPE_1__ sta; } ;

/* Variables and functions */
 TYPE_2__* wd ; 
 int /*<<< orphan*/  zfHpGetTransmitPower (int /*<<< orphan*/ *) ; 
 scalar_t__ zfStaIsConnected (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  zmw_get_wlan_dev (int /*<<< orphan*/ *) ; 

u32_t zfiWlanQueryTransmitPower(zdev_t* dev)
{
    u32_t ret = 0;

    zmw_get_wlan_dev(dev);

    if (zfStaIsConnected(dev)) {
        ret = wd->sta.connPowerInHalfDbm;
    } else {
        ret = zfHpGetTransmitPower(dev);
    }

    return ret;
}