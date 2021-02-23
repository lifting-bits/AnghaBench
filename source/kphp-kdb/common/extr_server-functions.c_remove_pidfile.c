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
 int /*<<< orphan*/  kprintf (char*,char const*) ; 
 scalar_t__ unlink (char const*) ; 

void remove_pidfile (const char *pid_file) {
  if (pid_file == NULL)
    return;

  if (unlink(pid_file) != 0) {
    kprintf ("Could not remove the pid file %s.\n", pid_file);
  }

}