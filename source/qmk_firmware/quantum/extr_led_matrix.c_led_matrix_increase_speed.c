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
struct TYPE_2__ {int /*<<< orphan*/  raw; int /*<<< orphan*/  speed; } ;

/* Variables and functions */
 int /*<<< orphan*/  eeconfig_update_led_matrix (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  increment (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 
 TYPE_1__ led_matrix_config ; 

void led_matrix_increase_speed(void) {
    led_matrix_config.speed = increment(led_matrix_config.speed, 1, 0, 3);
    eeconfig_update_led_matrix(led_matrix_config.raw);  // EECONFIG needs to be increased to support this
}