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
struct device {int /*<<< orphan*/  devt; } ;
typedef  int /*<<< orphan*/  dev_t ;

/* Variables and functions */

__attribute__((used)) static int __match_devt(struct device *dev, void *data)
{
	dev_t *devt = data;

	return dev->devt == *devt;
}