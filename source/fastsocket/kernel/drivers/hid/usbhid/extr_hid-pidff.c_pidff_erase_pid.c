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
struct pidff_device {int /*<<< orphan*/ * reports; int /*<<< orphan*/  hid; TYPE_1__* block_free; } ;
struct TYPE_2__ {int* value; } ;

/* Variables and functions */
 size_t PID_BLOCK_FREE ; 
 size_t PID_EFFECT_BLOCK_INDEX ; 
 int /*<<< orphan*/  USB_DIR_OUT ; 
 int /*<<< orphan*/  usbhid_submit_report (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void pidff_erase_pid(struct pidff_device *pidff, int pid_id)
{
	pidff->block_free[PID_EFFECT_BLOCK_INDEX].value[0] = pid_id;
	usbhid_submit_report(pidff->hid, pidff->reports[PID_BLOCK_FREE],
			  USB_DIR_OUT);
}