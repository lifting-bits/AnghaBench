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
 int /*<<< orphan*/  dl_signal (int const,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kwrite (int,char const*,int) ; 
 int /*<<< orphan*/  sigterm_immediate_handler ; 
 int /*<<< orphan*/  turn_sigterm_on () ; 

__attribute__((used)) static void sigterm_handler (const int sig) {
  const char message[] = "SIGTERM handled.\n";
  kwrite (2, message, sizeof (message) - (size_t)1);

  //pending_signals |= (1 << sig);
  turn_sigterm_on();
  dl_signal (sig, sigterm_immediate_handler);
}