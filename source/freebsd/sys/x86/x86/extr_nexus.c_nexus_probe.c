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
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int BUS_PROBE_GENERIC ; 
 int /*<<< orphan*/  device_quiet (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
nexus_probe(device_t dev)
{

	device_quiet(dev);	/* suppress attach message for neatness */
	return (BUS_PROBE_GENERIC);
}