#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  set_local_privacy_cback; int /*<<< orphan*/  privacy_enable; } ;
struct TYPE_5__ {TYPE_1__ ble_local_privacy; } ;
typedef  TYPE_2__ tBTA_DM_MSG ;

/* Variables and functions */
 int /*<<< orphan*/  BTM_BleConfigPrivacy (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void bta_dm_ble_config_local_privacy (tBTA_DM_MSG *p_data)
{
    BTM_BleConfigPrivacy (p_data->ble_local_privacy.privacy_enable, p_data->ble_local_privacy.set_local_privacy_cback);
}