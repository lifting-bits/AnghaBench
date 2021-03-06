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
struct ofw_pwmbus_ivars {int /*<<< orphan*/  devinfo; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  M_DEVBUF ; 
 struct ofw_pwmbus_ivars* device_get_ivars (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (struct ofw_pwmbus_ivars*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ofw_bus_gen_destroy_devinfo (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
ofw_pwmbus_child_deleted(device_t dev, device_t child)
{
	struct ofw_pwmbus_ivars *ivars;

	ivars = device_get_ivars(child);
	if (ivars != NULL) {
		ofw_bus_gen_destroy_devinfo(&ivars->devinfo);
		free(ivars, M_DEVBUF);
	}
}