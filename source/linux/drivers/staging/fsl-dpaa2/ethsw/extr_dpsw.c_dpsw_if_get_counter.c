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
typedef  int /*<<< orphan*/  u64 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct fsl_mc_io {int dummy; } ;
struct fsl_mc_command {scalar_t__ params; int /*<<< orphan*/  header; int /*<<< orphan*/  member_0; } ;
struct dpsw_rsp_if_get_counter {int /*<<< orphan*/  counter; } ;
struct dpsw_cmd_if_get_counter {int /*<<< orphan*/  type; int /*<<< orphan*/  if_id; } ;
typedef  enum dpsw_counter { ____Placeholder_dpsw_counter } dpsw_counter ;

/* Variables and functions */
 int /*<<< orphan*/  COUNTER_TYPE ; 
 int /*<<< orphan*/  DPSW_CMDID_IF_GET_COUNTER ; 
 int /*<<< orphan*/  cpu_to_le16 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dpsw_set_field (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  le64_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mc_encode_cmd_header (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int mc_send_command (struct fsl_mc_io*,struct fsl_mc_command*) ; 

int dpsw_if_get_counter(struct fsl_mc_io *mc_io,
			u32 cmd_flags,
			u16 token,
			u16 if_id,
			enum dpsw_counter type,
			u64 *counter)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpsw_cmd_if_get_counter *cmd_params;
	struct dpsw_rsp_if_get_counter *rsp_params;
	int err;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPSW_CMDID_IF_GET_COUNTER,
					  cmd_flags,
					  token);
	cmd_params = (struct dpsw_cmd_if_get_counter *)cmd.params;
	cmd_params->if_id = cpu_to_le16(if_id);
	dpsw_set_field(cmd_params->type, COUNTER_TYPE, type);

	/* send command to mc*/
	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	/* retrieve response parameters */
	rsp_params = (struct dpsw_rsp_if_get_counter *)cmd.params;
	*counter = le64_to_cpu(rsp_params->counter);

	return 0;
}