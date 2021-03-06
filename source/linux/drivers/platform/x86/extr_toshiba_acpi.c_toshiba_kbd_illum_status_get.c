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
typedef  scalar_t__ u32 ;
struct toshiba_acpi_dev {int dummy; } ;

/* Variables and functions */
 int EIO ; 
 int ENODEV ; 
 int /*<<< orphan*/  SCI_KBD_ILLUM_STATUS ; 
 scalar_t__ TOS_FAILURE ; 
 scalar_t__ TOS_NOT_SUPPORTED ; 
 scalar_t__ TOS_SUCCESS ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  sci_close (struct toshiba_acpi_dev*) ; 
 int /*<<< orphan*/  sci_open (struct toshiba_acpi_dev*) ; 
 scalar_t__ sci_read (struct toshiba_acpi_dev*,int /*<<< orphan*/ ,scalar_t__*) ; 

__attribute__((used)) static int toshiba_kbd_illum_status_get(struct toshiba_acpi_dev *dev, u32 *time)
{
	u32 result;

	if (!sci_open(dev))
		return -EIO;

	result = sci_read(dev, SCI_KBD_ILLUM_STATUS, time);
	sci_close(dev);
	if (result == TOS_FAILURE)
		pr_err("ACPI call to get KBD backlight status failed\n");
	else if (result == TOS_NOT_SUPPORTED)
		return -ENODEV;

	return result == TOS_SUCCESS ? 0 : -EIO;
}