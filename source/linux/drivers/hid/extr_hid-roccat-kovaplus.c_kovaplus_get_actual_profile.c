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
struct usb_device {int dummy; } ;
struct kovaplus_actual_profile {int actual_profile; } ;

/* Variables and functions */
 int /*<<< orphan*/  KOVAPLUS_COMMAND_ACTUAL_PROFILE ; 
 int roccat_common2_receive (struct usb_device*,int /*<<< orphan*/ ,struct kovaplus_actual_profile*,int) ; 

__attribute__((used)) static int kovaplus_get_actual_profile(struct usb_device *usb_dev)
{
	struct kovaplus_actual_profile buf;
	int retval;

	retval = roccat_common2_receive(usb_dev, KOVAPLUS_COMMAND_ACTUAL_PROFILE,
			&buf, sizeof(struct kovaplus_actual_profile));

	return retval ? retval : buf.actual_profile;
}