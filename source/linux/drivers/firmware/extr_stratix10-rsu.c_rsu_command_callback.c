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
struct stratix10_svc_client {int /*<<< orphan*/  dev; struct stratix10_rsu_priv* priv; } ;
struct stratix10_svc_cb_data {scalar_t__ status; } ;
struct stratix10_rsu_priv {int /*<<< orphan*/  completion; } ;

/* Variables and functions */
 scalar_t__ BIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SVC_STATUS_RSU_OK ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,scalar_t__) ; 

__attribute__((used)) static void rsu_command_callback(struct stratix10_svc_client *client,
				 struct stratix10_svc_cb_data *data)
{
	struct stratix10_rsu_priv *priv = client->priv;

	if (data->status != BIT(SVC_STATUS_RSU_OK))
		dev_err(client->dev, "RSU returned status is %i\n",
			data->status);
	complete(&priv->completion);
}