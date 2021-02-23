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
 int /*<<< orphan*/  error (char*) ; 
 int /*<<< orphan*/  gr_clear_all_breakpoints () ; 
 int /*<<< orphan*/  pop_target () ; 
 int /*<<< orphan*/  puts_filtered (char*) ; 
 scalar_t__ sr_is_open () ; 

void
gr_detach (char *args, int from_tty)
{
  if (args)
    error ("Argument given to \"detach\" when remotely debugging.");

  if (sr_is_open ())
    gr_clear_all_breakpoints ();

  pop_target ();
  if (from_tty)
    puts_filtered ("Ending remote debugging.\n");

  return;
}