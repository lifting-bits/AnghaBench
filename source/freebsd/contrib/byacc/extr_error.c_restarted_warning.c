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
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*,int,char*) ; 
 char* input_file_name ; 
 int lineno ; 
 char* myname ; 
 int /*<<< orphan*/  stderr ; 

void
restarted_warning(void)
{
    fprintf(stderr, "%s: w - line %d of \"%s\", the start symbol has been \
redeclared\n", myname, lineno, input_file_name);
}