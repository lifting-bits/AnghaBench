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
struct ufs_hba {int /*<<< orphan*/  clk_scaling_lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  ufshcd_scsi_unblock_requests (struct ufs_hba*) ; 
 int /*<<< orphan*/  up_write (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void ufshcd_clock_scaling_unprepare(struct ufs_hba *hba)
{
	up_write(&hba->clk_scaling_lock);
	ufshcd_scsi_unblock_requests(hba);
}