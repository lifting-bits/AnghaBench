#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct kaweth_device {int suspend_lowmem_ctrl; TYPE_2__* dev; int /*<<< orphan*/  lowmem_work; int /*<<< orphan*/  irq_urb; } ;
typedef  int /*<<< orphan*/  gfp_t ;
struct TYPE_4__ {int /*<<< orphan*/  devpath; TYPE_1__* bus; } ;
struct TYPE_3__ {int /*<<< orphan*/  bus_name; } ;

/* Variables and functions */
 int ENOMEM ; 
 int HZ ; 
 int /*<<< orphan*/  err (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  schedule_delayed_work (int /*<<< orphan*/ *,int) ; 
 scalar_t__ unlikely (int) ; 
 int usb_submit_urb (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void kaweth_resubmit_int_urb(struct kaweth_device *kaweth, gfp_t mf)
{
	int status;

	status = usb_submit_urb (kaweth->irq_urb, mf);
	if (unlikely(status == -ENOMEM)) {
		kaweth->suspend_lowmem_ctrl = 1;
		schedule_delayed_work(&kaweth->lowmem_work, HZ/4);
	} else {
		kaweth->suspend_lowmem_ctrl = 0;
	}

	if (status)
		err ("can't resubmit intr, %s-%s, status %d",
				kaweth->dev->bus->bus_name,
				kaweth->dev->devpath, status);
}