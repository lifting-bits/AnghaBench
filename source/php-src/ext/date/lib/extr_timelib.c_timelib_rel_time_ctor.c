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
typedef  int /*<<< orphan*/  timelib_rel_time ;

/* Variables and functions */
 int /*<<< orphan*/ * timelib_calloc (int,int) ; 

timelib_rel_time* timelib_rel_time_ctor(void)
{
	timelib_rel_time *t;
	t = timelib_calloc(1, sizeof(timelib_rel_time));

	return t;
}