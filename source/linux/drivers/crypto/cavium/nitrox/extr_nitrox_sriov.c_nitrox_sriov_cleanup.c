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
struct nitrox_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  nitrox_mbox_cleanup (struct nitrox_device*) ; 
 int /*<<< orphan*/  nitrox_sriov_unregister_interrupts (struct nitrox_device*) ; 

__attribute__((used)) static void nitrox_sriov_cleanup(struct nitrox_device *ndev)
{
	/* unregister interrupts for PF in SR-IOV */
	nitrox_sriov_unregister_interrupts(ndev);
	nitrox_mbox_cleanup(ndev);
}