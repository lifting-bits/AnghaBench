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
struct selinux_kernel_status {int policyload; int deny_unknown; int /*<<< orphan*/  sequence; } ;

/* Variables and functions */
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct selinux_kernel_status* page_address (scalar_t__) ; 
 int /*<<< orphan*/  security_get_allow_unknown () ; 
 int /*<<< orphan*/  selinux_status_lock ; 
 scalar_t__ selinux_status_page ; 
 int /*<<< orphan*/  smp_wmb () ; 

void selinux_status_update_policyload(int seqno)
{
	struct selinux_kernel_status   *status;

	mutex_lock(&selinux_status_lock);
	if (selinux_status_page) {
		status = page_address(selinux_status_page);

		status->sequence++;
		smp_wmb();

		status->policyload = seqno;
		status->deny_unknown = !security_get_allow_unknown();

		smp_wmb();
		status->sequence++;
	}
	mutex_unlock(&selinux_status_lock);
}