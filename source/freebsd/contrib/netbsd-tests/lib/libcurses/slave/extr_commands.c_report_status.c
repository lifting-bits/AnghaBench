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
 int /*<<< orphan*/  report_message (int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  ret_string ; 

void
report_status(const char *status)
{
	report_message(ret_string, status);
}