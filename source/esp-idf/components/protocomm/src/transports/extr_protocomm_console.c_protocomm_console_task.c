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
typedef  char uint8_t ;
struct TYPE_4__ {scalar_t__ type; } ;
typedef  TYPE_1__ uart_event_t ;
typedef  int /*<<< orphan*/  linebuf ;
typedef  scalar_t__ esp_err_t ;
struct TYPE_5__ {int max_cmdline_args; int max_cmdline_length; } ;
typedef  TYPE_2__ esp_console_config_t ;
typedef  int TickType_t ;
typedef  int /*<<< orphan*/  QueueHandle_t ;

/* Variables and functions */
 int /*<<< orphan*/  ESP_LOGD (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  ESP_LOGE (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  ESP_LOGI (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  TAG ; 
 scalar_t__ UART_DATA ; 
 int /*<<< orphan*/  esp_console_deinit () ; 
 int /*<<< orphan*/  esp_console_init (TYPE_2__*) ; 
 int /*<<< orphan*/  esp_console_register_help_command () ; 
 scalar_t__ esp_console_run (char*,int*) ; 
 int /*<<< orphan*/  memset (char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/ * pc_console ; 
 scalar_t__ pdPASS ; 
 int portTICK_RATE_MS ; 
 scalar_t__ stopped () ; 
 int /*<<< orphan*/  uart_driver_install (int,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ uart_read_bytes (int,char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uart_write_bytes (int,char*,int) ; 
 int /*<<< orphan*/  vTaskDelete (int /*<<< orphan*/ *) ; 
 scalar_t__ xQueueReceive (int /*<<< orphan*/ ,void*,int) ; 

__attribute__((used)) static void protocomm_console_task(void *arg)
{
    int uart_num = (int) arg;
    uint8_t linebuf[256];
    int i, cmd_ret;
    esp_err_t ret;
    QueueHandle_t uart_queue;
    uart_event_t event;

    ESP_LOGD(TAG, "Initializing UART on port %d", uart_num);
    uart_driver_install(uart_num, 256, 0, 8, &uart_queue, 0);
    /* Initialize the console */
    esp_console_config_t console_config = {
            .max_cmdline_args = 8,
            .max_cmdline_length = 256,
    };

    esp_console_init(&console_config);
    esp_console_register_help_command();

    while (!stopped()) {
        uart_write_bytes(uart_num, "\n>> ", 4);
        memset(linebuf, 0, sizeof(linebuf));
        i = 0;
        do {
            ret = xQueueReceive(uart_queue, (void * )&event, (TickType_t) 10/portTICK_RATE_MS);
            if (ret != pdPASS) {
                if (stopped()) {
                    break;
                } else {
                    continue;
                }
            }
            if (event.type == UART_DATA) {
                while (uart_read_bytes(uart_num, (uint8_t *) &linebuf[i], 1, 0)) {
                    if (linebuf[i] == '\r') {
                        uart_write_bytes(uart_num, "\r\n", 2);
                    } else {
                        uart_write_bytes(uart_num, (char *) &linebuf[i], 1);
                    }
                    i++;
                }
            }
        } while ((i < 255) && linebuf[i-1] != '\r');
        if (stopped()) {
            break;
        }
        ret = esp_console_run((char *) linebuf, &cmd_ret);
        if (ret < 0) {
            ESP_LOGE(TAG, "Console dispatcher error\n");
            break;
        }
    }

    pc_console = NULL;
    esp_console_deinit();

    ESP_LOGI(TAG, "Console stopped");
    vTaskDelete(NULL);
}