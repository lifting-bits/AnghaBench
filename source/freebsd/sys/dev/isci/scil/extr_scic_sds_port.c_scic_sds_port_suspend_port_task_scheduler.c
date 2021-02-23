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
typedef  int /*<<< orphan*/  U32 ;
typedef  int /*<<< orphan*/  SCIC_SDS_PORT_T ;

/* Variables and functions */
 int /*<<< orphan*/  SCU_PTSxCR_GEN_BIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SUSPEND ; 
 int /*<<< orphan*/  control ; 
 int /*<<< orphan*/  scu_port_task_scheduler_read (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  scu_port_task_scheduler_write (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void scic_sds_port_suspend_port_task_scheduler(
   SCIC_SDS_PORT_T *this_port
)
{
   U32 pts_control_value;

   pts_control_value = scu_port_task_scheduler_read(this_port, control);
   pts_control_value |= SCU_PTSxCR_GEN_BIT(SUSPEND);
   scu_port_task_scheduler_write(this_port, control, pts_control_value);
}