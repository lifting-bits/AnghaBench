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
 int /*<<< orphan*/  myfunc2 (size_t) ; 
 scalar_t__ prevent_inline ; 
 int /*<<< orphan*/  vfork () ; 

void
myfunc1(size_t origcalls, volatile size_t ncalls)
{
	if (ncalls > 1)
		myfunc1(origcalls, ncalls - 1);
	else
		myfunc2(origcalls);

	if (prevent_inline)
		vfork();
}