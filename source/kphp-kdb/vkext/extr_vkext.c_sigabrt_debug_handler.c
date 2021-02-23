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
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  print_backtrace () ; 
 int /*<<< orphan*/  write (int,char*,int) ; 

void sigabrt_debug_handler (const int sig) {
  write (2, "SIGABRT caught, terminating program\n", 36);
  print_backtrace ();
  exit (EXIT_FAILURE);
}