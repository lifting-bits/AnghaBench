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
struct TYPE_4__ {int /*<<< orphan*/  p_select_cback; int /*<<< orphan*/  bg_conn_type; } ;
struct TYPE_5__ {TYPE_1__ ble_set_bd_conn_type; } ;
typedef  TYPE_2__ tBTA_DM_MSG ;

/* Variables and functions */
 int /*<<< orphan*/  BTM_BleSetBgConnType (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void bta_dm_ble_set_bg_conn_type (tBTA_DM_MSG *p_data)
{
    BTM_BleSetBgConnType(p_data->ble_set_bd_conn_type.bg_conn_type,
                         p_data->ble_set_bd_conn_type.p_select_cback);
}