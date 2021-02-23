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
typedef  int /*<<< orphan*/  SCIC_SDS_CONTROLLER_T ;

/* Variables and functions */
 int /*<<< orphan*/  scic_sds_controller_power_control_timer_start (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  scic_sds_controller_power_control_timer_stop (int /*<<< orphan*/ *) ; 

__attribute__((used)) static
void scic_sds_controller_power_control_timer_restart(
   SCIC_SDS_CONTROLLER_T *this_controller
)
{
   scic_sds_controller_power_control_timer_stop(this_controller);
   scic_sds_controller_power_control_timer_start(this_controller);
}