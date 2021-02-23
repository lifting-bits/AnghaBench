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
typedef  int /*<<< orphan*/  zdev_t ;
typedef  int /*<<< orphan*/  u32_t ;
struct TYPE_2__ {int /*<<< orphan*/  modeMDKEnable; } ;

/* Variables and functions */
 TYPE_1__* wd ; 
 int /*<<< orphan*/  zm_debug_msg1 (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  zmw_get_wlan_dev (int /*<<< orphan*/ *) ; 

void zfiDKEnable(zdev_t *dev, u32_t enable)
{
	zmw_get_wlan_dev(dev);

	wd->modeMDKEnable = enable;
	zm_debug_msg1("modeMDKEnable = ", wd->modeMDKEnable);
}