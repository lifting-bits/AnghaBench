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
typedef  int /*<<< orphan*/  chtype ;

/* Variables and functions */
 int check_arg_count (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  inchstr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  report_count (int) ; 
 int /*<<< orphan*/  report_nstr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  report_return (int /*<<< orphan*/ ) ; 

void
cmd_inchstr(int nargs, char **args)
{
	chtype string[256];

	if (check_arg_count(nargs, 0) == 1)
		return;

	/* XXX call2 */
	report_count(2);
	report_return(inchstr(string));
	report_nstr(string);
}