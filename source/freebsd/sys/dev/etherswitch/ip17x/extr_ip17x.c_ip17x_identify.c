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
typedef  int /*<<< orphan*/  driver_t ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  BUS_ADD_CHILD (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/ * device_find_child (int /*<<< orphan*/ ,char*,int) ; 

__attribute__((used)) static void
ip17x_identify(driver_t *driver, device_t parent)
{
	if (device_find_child(parent, "ip17x", -1) == NULL)
	    BUS_ADD_CHILD(parent, 0, "ip17x", -1);
}