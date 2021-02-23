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
 int ctl_initialized ; 
 int /*<<< orphan*/  ctl_mtx ; 
 scalar_t__ malloc_mutex_init (int /*<<< orphan*/ *) ; 

bool
ctl_boot(void)
{

	if (malloc_mutex_init(&ctl_mtx))
		return (true);

	ctl_initialized = false;

	return (false);
}