#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {struct TYPE_4__* tz_abbr; } ;
typedef  TYPE_1__ timelib_time ;

/* Variables and functions */
 int /*<<< orphan*/  TIMELIB_TIME_FREE (TYPE_1__*) ; 

void timelib_time_dtor(timelib_time* t)
{
	TIMELIB_TIME_FREE(t->tz_abbr);
	TIMELIB_TIME_FREE(t);
}