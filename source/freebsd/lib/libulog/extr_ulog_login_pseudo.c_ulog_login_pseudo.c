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
 int /*<<< orphan*/  ulog_exec_helper (int,char const* const*) ; 

void
ulog_login_pseudo(int fd, const char *host)
{
	char const * const args[4] = { "ulog-helper", "login", host, NULL };

	ulog_exec_helper(fd, args);
}