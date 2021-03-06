#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  esp_gatt_if_t ;
typedef  int /*<<< orphan*/  esp_err_t ;
typedef  int /*<<< orphan*/  esp_ble_addr_type_t ;
typedef  int /*<<< orphan*/  esp_bd_addr_t ;
struct TYPE_7__ {int /*<<< orphan*/  act; int /*<<< orphan*/  pid; int /*<<< orphan*/  sig; } ;
typedef  TYPE_2__ btc_msg_t ;
struct TYPE_6__ {int is_direct; int /*<<< orphan*/  remote_addr_type; int /*<<< orphan*/  remote_bda; int /*<<< orphan*/  gattc_if; } ;
struct TYPE_8__ {TYPE_1__ open; } ;
typedef  TYPE_3__ btc_ble_gattc_args_t ;

/* Variables and functions */
 int /*<<< orphan*/  BTC_GATTC_ACT_OPEN ; 
 int /*<<< orphan*/  BTC_PID_GATTC ; 
 int /*<<< orphan*/  BTC_SIG_API_CALL ; 
 scalar_t__ BT_STATUS_SUCCESS ; 
 int /*<<< orphan*/  ESP_BD_ADDR_LEN ; 
 int /*<<< orphan*/  ESP_BLUEDROID_STATUS_CHECK (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ESP_BLUEDROID_STATUS_ENABLED ; 
 int /*<<< orphan*/  ESP_FAIL ; 
 int /*<<< orphan*/  ESP_OK ; 
 scalar_t__ btc_transfer_context (TYPE_2__*,TYPE_3__*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

esp_err_t esp_ble_gattc_open(esp_gatt_if_t gattc_if, esp_bd_addr_t remote_bda, esp_ble_addr_type_t remote_addr_type, bool is_direct)
{
    btc_msg_t msg;
    btc_ble_gattc_args_t arg;

    ESP_BLUEDROID_STATUS_CHECK(ESP_BLUEDROID_STATUS_ENABLED);

    msg.sig = BTC_SIG_API_CALL;
    msg.pid = BTC_PID_GATTC;
    msg.act = BTC_GATTC_ACT_OPEN;
    arg.open.gattc_if = gattc_if;
    memcpy(arg.open.remote_bda, remote_bda, ESP_BD_ADDR_LEN);
    arg.open.remote_addr_type = remote_addr_type;
    arg.open.is_direct = is_direct;

    return (btc_transfer_context(&msg, &arg, sizeof(btc_ble_gattc_args_t), NULL) == BT_STATUS_SUCCESS ? ESP_OK : ESP_FAIL);
}