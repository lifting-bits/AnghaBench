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
 scalar_t__ nlm_setup_xlp_board (int /*<<< orphan*/ ) ; 

int nlm_board_info_setup(void)
{
	if (nlm_setup_xlp_board(0) != 0)
		return (-1);
	return (0);
}