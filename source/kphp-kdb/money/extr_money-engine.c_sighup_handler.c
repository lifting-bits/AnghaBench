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
 int /*<<< orphan*/  SIGHUP ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  signal (int /*<<< orphan*/ ,void (*) (int const)) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  sync_binlog (int) ; 

__attribute__((used)) static void sighup_handler (const int sig) {
  fprintf (stderr, "got SIGHUP.\n");
  sync_binlog (2);
  signal(SIGHUP, sighup_handler);
}