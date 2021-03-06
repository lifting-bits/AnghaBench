#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_1__* device_t ;
struct TYPE_3__ {char const* dev_desc; } ;

/* Variables and functions */
 char const* unknown_string ; 

const char *
device_get_desc(device_t dev)
{
	if (dev)
		return &(dev->dev_desc[0]);
	return (unknown_string);
}