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
typedef  int /*<<< orphan*/  message ;

/* Variables and functions */
 int /*<<< orphan*/  SIGUSR1 ; 
 int /*<<< orphan*/  force_reopen_logs ; 
 int /*<<< orphan*/  kwrite (int,char const*,int) ; 
 int /*<<< orphan*/  signal (int /*<<< orphan*/ ,void (*) (int const)) ; 

__attribute__((used)) static void sigusr1_handler (const int sig) {
  static const char message[] = "got SIGUSR1.\n";
  kwrite (2, message, sizeof (message) - (size_t)1);
/*
  sync_binlog (2);
*/
  force_reopen_logs++;
  signal (SIGUSR1, sigusr1_handler);
}