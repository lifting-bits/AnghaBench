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
typedef  int /*<<< orphan*/  wifi_init_config_t ;
typedef  int /*<<< orphan*/  esp_netif_t ;

/* Variables and functions */
 int /*<<< orphan*/  ESP_ERROR_CHECK (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ESP_EVENT_ANY_ID ; 
 int /*<<< orphan*/  IP_EVENT ; 
 int /*<<< orphan*/  IP_EVENT_STA_GOT_IP ; 
 int /*<<< orphan*/  WIFI_EVENT ; 
 int /*<<< orphan*/  WIFI_INIT_CONFIG_DEFAULT () ; 
 int /*<<< orphan*/  WIFI_MODE_STA ; 
 int /*<<< orphan*/  WIFI_STORAGE_RAM ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  esp_event_handler_register (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  esp_event_loop_create_default () ; 
 int /*<<< orphan*/ * esp_netif_create_default_wifi_sta () ; 
 int /*<<< orphan*/  esp_netif_init () ; 
 int /*<<< orphan*/  esp_wifi_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  esp_wifi_set_mode (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  esp_wifi_set_storage (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  esp_wifi_start () ; 
 int /*<<< orphan*/  ip_event_handler ; 
 int /*<<< orphan*/  wifi_event_group ; 
 int /*<<< orphan*/  wifi_event_handler ; 
 int /*<<< orphan*/  xEventGroupCreate () ; 

__attribute__((used)) static void initialise_wifi(void)
{
    esp_netif_init();
    wifi_event_group = xEventGroupCreate();
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    esp_netif_t *sta_netif = esp_netif_create_default_wifi_sta();
    assert(sta_netif);
    ESP_ERROR_CHECK(esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &wifi_event_handler, NULL));
    ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &ip_event_handler, NULL));

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK( esp_wifi_init(&cfg) );
    ESP_ERROR_CHECK( esp_wifi_set_storage(WIFI_STORAGE_RAM) );
    ESP_ERROR_CHECK( esp_wifi_set_mode(WIFI_MODE_STA) );
    ESP_ERROR_CHECK( esp_wifi_start() );
}