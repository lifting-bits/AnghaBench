#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  state_machine; } ;
struct TYPE_4__ {int /*<<< orphan*/  sci_status; TYPE_1__ parent; } ;
typedef  int /*<<< orphan*/  SCI_STATUS ;
typedef  int /*<<< orphan*/  SCI_BASE_REQUEST_T ;
typedef  TYPE_2__ SCIC_SDS_REQUEST_T ;

/* Variables and functions */
 int /*<<< orphan*/  SCI_BASE_REQUEST_STATE_COMPLETED ; 
 int /*<<< orphan*/  sci_base_state_machine_change_state (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static
SCI_STATUS scic_sds_stp_packet_request_started_completion_delay_complete_handler(
   SCI_BASE_REQUEST_T *request
)
{
   SCIC_SDS_REQUEST_T * this_request = (SCIC_SDS_REQUEST_T *)request;

   sci_base_state_machine_change_state(
      &this_request->parent.state_machine,
      SCI_BASE_REQUEST_STATE_COMPLETED
   );

   return this_request->sci_status;
}