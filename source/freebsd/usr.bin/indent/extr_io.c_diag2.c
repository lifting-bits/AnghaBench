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
 int found_err ; 
 int /*<<< orphan*/  fprintf (scalar_t__,char*,...) ; 
 int line_no ; 
 scalar_t__ output ; 
 scalar_t__ stderr ; 
 scalar_t__ stdout ; 

void
diag2(int level, const char *msg)
{
    if (level)
	found_err = 1;
    if (output == stdout) {
	fprintf(stdout, "/**INDENT** %s@%d: ", level == 0 ? "Warning" : "Error", line_no);
	fprintf(stdout, "%s", msg);
	fprintf(stdout, " */\n");
    }
    else {
	fprintf(stderr, "%s@%d: ", level == 0 ? "Warning" : "Error", line_no);
	fprintf(stderr, "%s", msg);
	fprintf(stderr, "\n");
    }
}