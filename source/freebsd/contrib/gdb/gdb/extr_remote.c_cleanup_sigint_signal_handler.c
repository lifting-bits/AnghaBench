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
struct async_signal_handler {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SIGINT ; 
 int /*<<< orphan*/  delete_async_signal_handler (struct async_signal_handler**) ; 
 int /*<<< orphan*/  handle_sigint ; 
 scalar_t__ sigint_remote_token ; 
 scalar_t__ sigint_remote_twice_token ; 
 int /*<<< orphan*/  signal (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
cleanup_sigint_signal_handler (void *dummy)
{
  signal (SIGINT, handle_sigint);
  if (sigint_remote_twice_token)
    delete_async_signal_handler ((struct async_signal_handler **) & sigint_remote_twice_token);
  if (sigint_remote_token)
    delete_async_signal_handler ((struct async_signal_handler **) & sigint_remote_token);
}