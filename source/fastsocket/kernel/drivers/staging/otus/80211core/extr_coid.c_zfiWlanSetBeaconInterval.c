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
typedef  scalar_t__ u8_t ;
typedef  void* u16_t ;
struct TYPE_3__ {void* beaconInterval; } ;
struct TYPE_4__ {TYPE_1__ ws; void* beaconInterval; } ;

/* Variables and functions */
 TYPE_2__* wd ; 
 int /*<<< orphan*/  zmw_declare_for_critical_section () ; 
 int /*<<< orphan*/  zmw_enter_critical_section (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  zmw_get_wlan_dev (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  zmw_leave_critical_section (int /*<<< orphan*/ *) ; 

void zfiWlanSetBeaconInterval(zdev_t* dev,
                              u16_t  beaconInterval,
                              u8_t   bImmediate)
{
    zmw_get_wlan_dev(dev);

    zmw_declare_for_critical_section();

    if ( bImmediate )
    {
        zmw_enter_critical_section(dev);
        wd->beaconInterval = beaconInterval;
        zmw_leave_critical_section(dev);

        /* update beacon interval here */
    }
    else
    {
        zmw_enter_critical_section(dev);
        wd->ws.beaconInterval = beaconInterval;
        zmw_leave_critical_section(dev);
    }
}