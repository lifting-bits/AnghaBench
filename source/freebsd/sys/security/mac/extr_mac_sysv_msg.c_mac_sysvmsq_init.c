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
struct msqid_kernel {int /*<<< orphan*/ * label; } ;

/* Variables and functions */
 int MPC_OBJECT_SYSVMSQ ; 
 int mac_labeled ; 
 int /*<<< orphan*/ * mac_sysv_msgqueue_label_alloc () ; 

void
mac_sysvmsq_init(struct msqid_kernel *msqkptr)
{

	if (mac_labeled & MPC_OBJECT_SYSVMSQ)
		msqkptr->label = mac_sysv_msgqueue_label_alloc();
	else
		msqkptr->label = NULL;
}