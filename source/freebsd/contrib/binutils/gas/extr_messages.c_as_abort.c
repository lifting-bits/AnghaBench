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
 int /*<<< orphan*/  EXIT_FAILURE ; 
 char* _ (char*) ; 
 int /*<<< orphan*/  as_show_where () ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  xexit (int /*<<< orphan*/ ) ; 

void
as_abort (const char *file, int line, const char *fn)
{
  as_show_where ();
  if (fn)
    fprintf (stderr, _("Internal error, aborting at %s line %d in %s\n"),
	     file, line, fn);
  else
    fprintf (stderr, _("Internal error, aborting at %s line %d\n"),
	     file, line);
  fprintf (stderr, _("Please report this bug.\n"));
  xexit (EXIT_FAILURE);
}