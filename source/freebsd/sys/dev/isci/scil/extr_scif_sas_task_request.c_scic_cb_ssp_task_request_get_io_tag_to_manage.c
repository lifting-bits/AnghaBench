#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  U16 ;
struct TYPE_5__ {int /*<<< orphan*/  associated_object; } ;
struct TYPE_6__ {TYPE_1__ parent; } ;
struct TYPE_7__ {TYPE_2__ parent; } ;
struct TYPE_8__ {int /*<<< orphan*/  io_tag_to_manage; TYPE_3__ parent; } ;
typedef  TYPE_4__ SCIF_SAS_TASK_REQUEST_T ;

/* Variables and functions */
 int /*<<< orphan*/  scif_cb_task_request_get_io_tag_to_manage (int /*<<< orphan*/ ) ; 

U16 scic_cb_ssp_task_request_get_io_tag_to_manage(
   void * scic_user_task_request
)
{
   SCIF_SAS_TASK_REQUEST_T * fw_task = (SCIF_SAS_TASK_REQUEST_T*)
                                       scic_user_task_request;

   fw_task->io_tag_to_manage
      = scif_cb_task_request_get_io_tag_to_manage(
           fw_task->parent.parent.parent.associated_object
        );

   return fw_task->io_tag_to_manage;
}