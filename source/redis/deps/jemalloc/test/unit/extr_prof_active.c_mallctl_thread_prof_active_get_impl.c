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
 int /*<<< orphan*/  mallctl_bool_get (char*,int,char const*,int) ; 

__attribute__((used)) static void
mallctl_thread_prof_active_get_impl(bool thread_prof_active_old_expected,
    const char *func, int line) {
	mallctl_bool_get("thread.prof.active", thread_prof_active_old_expected,
	    func, line);
}