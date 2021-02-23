#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
struct TYPE_13__ {void* arg; int /*<<< orphan*/  cb; } ;
typedef  TYPE_1__ uint8_t ;
struct TYPE_14__ {int /*<<< orphan*/  os; int /*<<< orphan*/  sli; } ;
typedef  TYPE_2__ ocs_hw_t ;
typedef  scalar_t__ ocs_hw_rtn_e ;
typedef  int /*<<< orphan*/  ocs_hw_host_stat_cb_t ;
typedef  TYPE_1__ ocs_hw_host_stat_cb_arg_t ;

/* Variables and functions */
 int /*<<< orphan*/  OCS_CMD_NOWAIT ; 
 scalar_t__ OCS_HW_RTN_ERROR ; 
 scalar_t__ OCS_HW_RTN_NO_MEMORY ; 
 scalar_t__ OCS_HW_RTN_SUCCESS ; 
 int /*<<< orphan*/  OCS_M_ZERO ; 
 int SLI4_BMBX_SIZE ; 
 int /*<<< orphan*/  ocs_free (int /*<<< orphan*/ ,TYPE_1__*,int) ; 
 int /*<<< orphan*/  ocs_hw_cb_host_stat ; 
 scalar_t__ ocs_hw_command (TYPE_2__*,TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  ocs_log_err (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  ocs_log_test (int /*<<< orphan*/ ,char*) ; 
 TYPE_1__* ocs_malloc (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 scalar_t__ sli_cmd_read_status (int /*<<< orphan*/ *,TYPE_1__*,int,TYPE_1__) ; 

ocs_hw_rtn_e
ocs_hw_get_host_stats(ocs_hw_t *hw, uint8_t cc, ocs_hw_host_stat_cb_t cb, void *arg)
{
	ocs_hw_rtn_e rc = OCS_HW_RTN_ERROR;
	ocs_hw_host_stat_cb_arg_t *cb_arg;
	uint8_t *mbxdata;

	mbxdata = ocs_malloc(hw->os, SLI4_BMBX_SIZE, OCS_M_ZERO);
	if (mbxdata == NULL) {
		ocs_log_err(hw->os, "failed to malloc mbox");
		return OCS_HW_RTN_NO_MEMORY;
	}

	cb_arg = ocs_malloc(hw->os, sizeof(ocs_hw_host_stat_cb_arg_t), 0);
	if (cb_arg == NULL) {
		ocs_log_err(hw->os, "failed to malloc cb_arg");
		ocs_free(hw->os, mbxdata, SLI4_BMBX_SIZE);
		return OCS_HW_RTN_NO_MEMORY;
	 }

	 cb_arg->cb = cb;
	 cb_arg->arg = arg;

	 /* Send the HW command to get the host stats */
	if (sli_cmd_read_status(&hw->sli, mbxdata, SLI4_BMBX_SIZE, cc)) {
		 rc = ocs_hw_command(hw, mbxdata, OCS_CMD_NOWAIT, ocs_hw_cb_host_stat, cb_arg);
	}

	if (rc != OCS_HW_RTN_SUCCESS) {
		ocs_log_test(hw->os, "READ_HOST_STATS failed\n");
		ocs_free(hw->os, mbxdata, SLI4_BMBX_SIZE);
		ocs_free(hw->os, cb_arg, sizeof(ocs_hw_host_stat_cb_arg_t));
	}

	return rc;
}