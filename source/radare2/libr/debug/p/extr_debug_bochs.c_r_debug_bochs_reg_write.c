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
typedef  int /*<<< orphan*/  ut8 ;
typedef  int /*<<< orphan*/  RDebug ;

/* Variables and functions */

__attribute__((used)) static int r_debug_bochs_reg_write(RDebug *dbg, int type, const ut8 *buf, int size) {
	//eprintf("bochs_reg_write\n");
	return -1;
}