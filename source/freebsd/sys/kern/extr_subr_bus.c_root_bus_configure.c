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

/* Variables and functions */
 int /*<<< orphan*/  BUS_PASS_DEFAULT ; 
 int /*<<< orphan*/  PDEBUG (char*) ; 
 int /*<<< orphan*/  bus_set_pass (int /*<<< orphan*/ ) ; 

void
root_bus_configure(void)
{

	PDEBUG(("."));

	/* Eventually this will be split up, but this is sufficient for now. */
	bus_set_pass(BUS_PASS_DEFAULT);
}