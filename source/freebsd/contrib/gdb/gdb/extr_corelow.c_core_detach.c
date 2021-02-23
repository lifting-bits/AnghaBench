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
 int /*<<< orphan*/  core_ops ; 
 int /*<<< orphan*/  error (char*) ; 
 int /*<<< orphan*/  printf_filtered (char*) ; 
 int /*<<< orphan*/  reinit_frame_cache () ; 
 int /*<<< orphan*/  unpush_target (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
core_detach (char *args, int from_tty)
{
  if (args)
    error ("Too many arguments");
  unpush_target (&core_ops);
  reinit_frame_cache ();
  if (from_tty)
    printf_filtered ("No core file now.\n");
}