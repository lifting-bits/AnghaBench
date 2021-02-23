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
 int /*<<< orphan*/  LL_WARNING ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  serverLog (int /*<<< orphan*/ ,char*) ; 

void sentinelSimFailureCrash(void) {
    serverLog(LL_WARNING,
        "Sentinel CRASH because of SENTINEL simulate-failure");
    exit(99);
}