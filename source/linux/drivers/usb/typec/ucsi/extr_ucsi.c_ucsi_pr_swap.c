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
struct ucsi_control {int dummy; } ;
struct TYPE_2__ {int pwr_dir; scalar_t__ pwr_op_mode; } ;
struct ucsi_connector {int /*<<< orphan*/  lock; TYPE_1__ status; int /*<<< orphan*/  complete; int /*<<< orphan*/  partner; } ;
struct typec_capability {int dummy; } ;
typedef  enum typec_role { ____Placeholder_typec_role } typec_role ;

/* Variables and functions */
 int ENOTCONN ; 
 int EPROTO ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  UCSI_CMD_SET_PDR (struct ucsi_control,struct ucsi_connector*,int) ; 
 scalar_t__ UCSI_CONSTAT_PWR_OPMODE_PD ; 
 int /*<<< orphan*/  UCSI_SWAP_TIMEOUT_MS ; 
 int /*<<< orphan*/  msecs_to_jiffies (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct ucsi_connector* to_ucsi_connector (struct typec_capability const*) ; 
 int /*<<< orphan*/  ucsi_reset_connector (struct ucsi_connector*,int) ; 
 int ucsi_role_cmd (struct ucsi_connector*,struct ucsi_control*) ; 
 int /*<<< orphan*/  wait_for_completion_timeout (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
ucsi_pr_swap(const struct typec_capability *cap, enum typec_role role)
{
	struct ucsi_connector *con = to_ucsi_connector(cap);
	struct ucsi_control ctrl;
	int ret = 0;

	mutex_lock(&con->lock);

	if (!con->partner) {
		ret = -ENOTCONN;
		goto out_unlock;
	}

	if (con->status.pwr_dir == role)
		goto out_unlock;

	UCSI_CMD_SET_PDR(ctrl, con, role);
	ret = ucsi_role_cmd(con, &ctrl);
	if (ret < 0)
		goto out_unlock;

	if (!wait_for_completion_timeout(&con->complete,
				msecs_to_jiffies(UCSI_SWAP_TIMEOUT_MS))) {
		ret = -ETIMEDOUT;
		goto out_unlock;
	}

	/* Something has gone wrong while swapping the role */
	if (con->status.pwr_op_mode != UCSI_CONSTAT_PWR_OPMODE_PD) {
		ucsi_reset_connector(con, true);
		ret = -EPROTO;
	}

out_unlock:
	mutex_unlock(&con->lock);

	return ret;
}