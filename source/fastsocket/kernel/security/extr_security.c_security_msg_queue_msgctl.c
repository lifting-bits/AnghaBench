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
struct msg_queue {int dummy; } ;
struct TYPE_2__ {int (* msg_queue_msgctl ) (struct msg_queue*,int) ;} ;

/* Variables and functions */
 TYPE_1__* security_ops ; 
 int stub1 (struct msg_queue*,int) ; 

int security_msg_queue_msgctl(struct msg_queue *msq, int cmd)
{
	return security_ops->msg_queue_msgctl(msq, cmd);
}