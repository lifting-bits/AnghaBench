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
typedef  int uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  DELAY (int) ; 
 scalar_t__ mp_naps ; 
 scalar_t__ mp_ncpus ; 

__attribute__((used)) static int
check_ap(void)
{
	uint32_t ms;

	for (ms = 0; ms < 2000; ++ms) {
		if ((mp_naps + 1) == mp_ncpus)
			return (0);		/* success */
		else
			DELAY(1000);
	}

	return (-2);
}