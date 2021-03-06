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
struct rt2x00_dev {int dummy; } ;

/* Variables and functions */
 int rt2800_efuse_detect (struct rt2x00_dev*) ; 
 int rt2800usb_autorun_detect (struct rt2x00_dev*) ; 

__attribute__((used)) static int rt2800usb_efuse_detect(struct rt2x00_dev *rt2x00dev)
{
	int retval;

	retval = rt2800usb_autorun_detect(rt2x00dev);
	if (retval < 0)
		return retval;
	if (retval)
		return 1;
	return rt2800_efuse_detect(rt2x00dev);
}