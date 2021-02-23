#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint32_t ;
struct TYPE_6__ {int /*<<< orphan*/  virt; } ;
struct TYPE_7__ {int /*<<< orphan*/  os; TYPE_1__ bmbx; } ;
typedef  TYPE_2__ sli4_t ;
typedef  int /*<<< orphan*/  sli4_queue_t ;
typedef  int int32_t ;

/* Variables and functions */
 int /*<<< orphan*/  SLI4_BMBX_SIZE ; 
 int /*<<< orphan*/  ocs_log_crit (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  ocs_log_err (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ sli_bmbx_command (TYPE_2__*) ; 
 int /*<<< orphan*/  sli_cmd_common_modify_eq_delay (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ sli_res_sli_config (int /*<<< orphan*/ ) ; 

int32_t
sli_eq_modify_delay(sli4_t *sli4, sli4_queue_t *eq, uint32_t num_eq, uint32_t shift, uint32_t delay_mult)
{

	sli_cmd_common_modify_eq_delay(sli4, sli4->bmbx.virt, SLI4_BMBX_SIZE, eq, num_eq, shift, delay_mult);

	if (sli_bmbx_command(sli4)) {
		ocs_log_crit(sli4->os, "bootstrap mailbox write fail (MODIFY EQ DELAY)\n");
		return -1;
	}
	if (sli_res_sli_config(sli4->bmbx.virt)) {
		ocs_log_err(sli4->os, "bad status MODIFY EQ DELAY\n");
		return -1;
	}

	return 0;
}