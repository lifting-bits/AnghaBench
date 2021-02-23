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
 int /*<<< orphan*/  SIGINT ; 
 int /*<<< orphan*/  async_remote_interrupt ; 
 int /*<<< orphan*/  create_async_signal_handler (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  handle_remote_sigint ; 
 int /*<<< orphan*/  sigint_remote_token ; 
 int /*<<< orphan*/  signal (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
initialize_sigint_signal_handler (void)
{
  sigint_remote_token =
    create_async_signal_handler (async_remote_interrupt, NULL);
  signal (SIGINT, handle_remote_sigint);
}