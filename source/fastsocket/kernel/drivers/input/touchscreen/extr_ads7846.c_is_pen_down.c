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
struct device {int dummy; } ;
struct ads7846 {int pendown; } ;

/* Variables and functions */
 struct ads7846* dev_get_drvdata (struct device*) ; 

__attribute__((used)) static int is_pen_down(struct device *dev)
{
	struct ads7846	*ts = dev_get_drvdata(dev);

	return ts->pendown;
}