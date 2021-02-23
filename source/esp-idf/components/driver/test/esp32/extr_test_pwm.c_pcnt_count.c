#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int pulse_gpio_num; int ctrl_gpio_num; int /*<<< orphan*/  counter_l_lim; int /*<<< orphan*/  counter_h_lim; int /*<<< orphan*/  hctrl_mode; int /*<<< orphan*/  lctrl_mode; int /*<<< orphan*/  neg_mode; int /*<<< orphan*/  pos_mode; int /*<<< orphan*/  unit; int /*<<< orphan*/  channel; } ;
typedef  TYPE_1__ pcnt_config_t ;
typedef  int int16_t ;

/* Variables and functions */
 int /*<<< orphan*/  HIGHEST_LIMIT ; 
 int /*<<< orphan*/  LOWEST_LIMIT ; 
 int /*<<< orphan*/  PCNT_CHANNEL_0 ; 
 int /*<<< orphan*/  PCNT_COUNT_DIS ; 
 int /*<<< orphan*/  PCNT_COUNT_INC ; 
 int /*<<< orphan*/  PCNT_MODE_KEEP ; 
 int /*<<< orphan*/  PCNT_MODE_REVERSE ; 
 int /*<<< orphan*/  PCNT_UNIT_0 ; 
 int /*<<< orphan*/  TEST_ESP_OK (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pcnt_counter_clear (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pcnt_counter_pause (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pcnt_counter_resume (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pcnt_get_counter_value (int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  pcnt_unit_config (TYPE_1__*) ; 
 int portTICK_RATE_MS ; 
 int /*<<< orphan*/  printf (char*,int) ; 
 int /*<<< orphan*/  vTaskDelay (int) ; 

__attribute__((used)) static int16_t pcnt_count(int pulse_gpio_num, int ctrl_gpio_num, int last_time)
{
    pcnt_config_t pcnt_config = {
        .pulse_gpio_num = pulse_gpio_num,
        .ctrl_gpio_num = ctrl_gpio_num,
        .channel = PCNT_CHANNEL_0,
        .unit = PCNT_UNIT_0,
        .pos_mode = PCNT_COUNT_INC,
        .neg_mode = PCNT_COUNT_DIS,
        .lctrl_mode = PCNT_MODE_REVERSE,
        .hctrl_mode = PCNT_MODE_KEEP,
        .counter_h_lim = HIGHEST_LIMIT,
        .counter_l_lim = LOWEST_LIMIT,
    };
    TEST_ESP_OK(pcnt_unit_config(&pcnt_config));
    int16_t test_counter;
    TEST_ESP_OK(pcnt_counter_pause(PCNT_UNIT_0));
    TEST_ESP_OK(pcnt_counter_clear(PCNT_UNIT_0));
    TEST_ESP_OK(pcnt_counter_resume(PCNT_UNIT_0));
    TEST_ESP_OK(pcnt_get_counter_value(PCNT_UNIT_0, &test_counter));
    printf("COUNT: %d\n", test_counter);
    vTaskDelay(last_time / portTICK_RATE_MS);
    TEST_ESP_OK(pcnt_get_counter_value(PCNT_UNIT_0, &test_counter));
    printf("COUNT: %d\n", test_counter);
    return test_counter;
}