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
struct vscsifrnt_info {int /*<<< orphan*/  wq_pause; scalar_t__ waiting_pause; scalar_t__ callers; } ;

/* Variables and functions */
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void scsifront_return(struct vscsifrnt_info *info)
{
	info->callers--;
	if (info->callers)
		return;

	if (!info->waiting_pause)
		return;

	info->waiting_pause = 0;
	wake_up(&info->wq_pause);
}