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
struct gasket_dev {struct device* dev; } ;
struct device {int dummy; } ;

/* Variables and functions */

struct device *gasket_get_device(struct gasket_dev *dev)
{
	return dev->dev;
}