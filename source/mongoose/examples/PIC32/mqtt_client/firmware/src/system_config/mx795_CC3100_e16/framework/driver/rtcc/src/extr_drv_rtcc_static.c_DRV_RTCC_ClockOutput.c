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
 int /*<<< orphan*/  PLIB_RTCC_ClockOutputEnable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RTCC_ID_0 ; 

void DRV_RTCC_ClockOutput(void) {
  PLIB_RTCC_ClockOutputEnable(RTCC_ID_0);
}