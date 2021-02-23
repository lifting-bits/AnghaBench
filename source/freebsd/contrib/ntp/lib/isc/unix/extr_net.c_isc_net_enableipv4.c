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
 scalar_t__ ISC_R_DISABLED ; 
 scalar_t__ ISC_R_SUCCESS ; 
 int /*<<< orphan*/  initialize () ; 
 scalar_t__ ipv4_result ; 

void
isc_net_enableipv4(void) {
	initialize();
	if (ipv4_result == ISC_R_DISABLED)
		ipv4_result = ISC_R_SUCCESS;
}