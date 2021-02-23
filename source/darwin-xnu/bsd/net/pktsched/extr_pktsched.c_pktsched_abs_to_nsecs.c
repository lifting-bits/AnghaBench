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
typedef  int /*<<< orphan*/  u_int64_t ;

/* Variables and functions */
 int /*<<< orphan*/  absolutetime_to_nanoseconds (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

u_int64_t
pktsched_abs_to_nsecs(u_int64_t abstime)
{
	u_int64_t nsecs;

	absolutetime_to_nanoseconds(abstime, &nsecs);
	return (nsecs);
}