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
typedef  int u_long ;
typedef  int /*<<< orphan*/  SCR ;
typedef  int /*<<< orphan*/  OPTION ;

/* Variables and functions */
 int /*<<< orphan*/  O_LINES ; 
 int O_VAL (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

int
f_window(
	SCR *sp,
	OPTION *op,
	char *str,
	u_long *valp)
{
	if (*valp >= O_VAL(sp, O_LINES) - 1 &&
	    (*valp = O_VAL(sp, O_LINES) - 1) == 0)
		*valp = 1;
	return (0);
}