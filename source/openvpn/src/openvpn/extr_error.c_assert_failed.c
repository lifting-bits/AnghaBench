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
 int /*<<< orphan*/  M_FATAL ; 
 int /*<<< orphan*/  _exit (int) ; 
 int /*<<< orphan*/  msg (int /*<<< orphan*/ ,char*,char const*,int,...) ; 

void
assert_failed(const char *filename, int line, const char *condition)
{
    if (condition)
    {
        msg(M_FATAL, "Assertion failed at %s:%d (%s)", filename, line, condition);
    }
    else
    {
        msg(M_FATAL, "Assertion failed at %s:%d", filename, line);
    }
    _exit(1);
}