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
 int /*<<< orphan*/  attron (int) ; 
 int check_arg_count (int,int) ; 
 int /*<<< orphan*/  report_count (int) ; 
 int /*<<< orphan*/  report_error (char*) ; 
 int /*<<< orphan*/  report_return (int /*<<< orphan*/ ) ; 
 scalar_t__ sscanf (char*,char*,int*) ; 

void
cmd_attron(int nargs, char **args)
{
	int attrib;

	if (check_arg_count(nargs, 1) == 1)
		return;

	if (sscanf(args[0], "%d", &attrib) == 0) {
		report_count(1);
	report_error("BAD ARGUMENT");
		return;
	}

	report_count(1);
	report_return(attron(attrib));
}