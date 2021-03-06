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
struct zpool {TYPE_1__* driver; } ;
struct TYPE_2__ {int malloc_support_movable; } ;

/* Variables and functions */

bool zpool_malloc_support_movable(struct zpool *zpool)
{
	return zpool->driver->malloc_support_movable;
}