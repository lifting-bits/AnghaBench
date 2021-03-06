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
struct rpc_err {int dummy; } ;
struct rc_data {struct rpc_err rc_err; } ;
struct TYPE_3__ {scalar_t__ cl_private; } ;
typedef  TYPE_1__ CLIENT ;

/* Variables and functions */

__attribute__((used)) static void
clnt_reconnect_geterr(CLIENT *cl, struct rpc_err *errp)
{
	struct rc_data *rc = (struct rc_data *)cl->cl_private;

	*errp = rc->rc_err;
}