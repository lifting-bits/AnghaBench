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
 int assertion_file_time (char const*,int,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char,int) ; 

int
assertion_file_atime_recent(const char *file, int line, const char *pathname)
{
	return assertion_file_time(file, line, pathname, 0, 0, 'a', 1);
}