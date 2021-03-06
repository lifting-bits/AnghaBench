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
typedef  scalar_t__ u8 ;
typedef  int /*<<< orphan*/  u64 ;
typedef  size_t u16 ;
struct TYPE_2__ {size_t token_mask; struct hns_roce_cmd_context* context; } ;
struct hns_roce_dev {TYPE_1__ cmd; } ;
struct hns_roce_cmd_context {size_t token; int /*<<< orphan*/  done; int /*<<< orphan*/  out_param; int /*<<< orphan*/  result; } ;

/* Variables and functions */
 int /*<<< orphan*/  EIO ; 
 scalar_t__ HNS_ROCE_CMD_SUCCESS ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 

void hns_roce_cmd_event(struct hns_roce_dev *hr_dev, u16 token, u8 status,
			u64 out_param)
{
	struct hns_roce_cmd_context
		*context = &hr_dev->cmd.context[token & hr_dev->cmd.token_mask];

	if (token != context->token)
		return;

	context->result = (status == HNS_ROCE_CMD_SUCCESS) ? 0 : (-EIO);
	context->out_param = out_param;
	complete(&context->done);
}