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
struct ptrace_context {scalar_t__ stop_code; } ;

/* Variables and functions */

__attribute__((used)) static inline bool ptrace_event_pending(struct ptrace_context *ctx)
{
	return ctx->stop_code != 0;
}