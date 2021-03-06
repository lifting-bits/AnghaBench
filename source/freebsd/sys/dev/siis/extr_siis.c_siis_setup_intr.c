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
struct siis_controller {TYPE_1__* interrupt; } ;
struct resource {int dummy; } ;
typedef  int /*<<< orphan*/  driver_intr_t ;
typedef  int /*<<< orphan*/  driver_filter_t ;
typedef  int /*<<< orphan*/  device_t ;
struct TYPE_2__ {void* argument; int /*<<< orphan*/ * function; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  device_get_ivars (int /*<<< orphan*/ ) ; 
 struct siis_controller* device_get_softc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*) ; 

__attribute__((used)) static int
siis_setup_intr(device_t dev, device_t child, struct resource *irq, 
		   int flags, driver_filter_t *filter, driver_intr_t *function, 
		   void *argument, void **cookiep)
{
	struct siis_controller *ctlr = device_get_softc(dev);
	int unit = (intptr_t)device_get_ivars(child);

	if (filter != NULL) {
		printf("siis.c: we cannot use a filter here\n");
		return (EINVAL);
	}
	ctlr->interrupt[unit].function = function;
	ctlr->interrupt[unit].argument = argument;
	return (0);
}