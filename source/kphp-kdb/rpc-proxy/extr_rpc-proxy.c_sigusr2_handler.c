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
 int /*<<< orphan*/  SIGUSR2 ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  need_reload_config ; 
 int /*<<< orphan*/  signal (int /*<<< orphan*/ ,void (*) (int const)) ; 
 int /*<<< orphan*/  stderr ; 
 scalar_t__ verbosity ; 

__attribute__((used)) static void sigusr2_handler (const int sig) {
  if (verbosity > 0) {
    fprintf (stderr, "got SIGUSR2, config reload scheduled.\n");
  }
  need_reload_config++;
  signal (SIGUSR2, sigusr2_handler);
}