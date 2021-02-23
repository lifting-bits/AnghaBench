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
typedef  scalar_t__ uint32_t ;
struct skynet_context {int /*<<< orphan*/ * logfile; } ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 scalar_t__ ATOM_CAS_POINTER (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  skynet_context_release (struct skynet_context*) ; 
 struct skynet_context* skynet_handle_grab (scalar_t__) ; 
 int /*<<< orphan*/  skynet_log_close (struct skynet_context*,int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ tohandle (struct skynet_context*,char const*) ; 

__attribute__((used)) static const char *
cmd_logoff(struct skynet_context * context, const char * param) {
	uint32_t handle = tohandle(context, param);
	if (handle == 0)
		return NULL;
	struct skynet_context * ctx = skynet_handle_grab(handle);
	if (ctx == NULL)
		return NULL;
	FILE * f = ctx->logfile;
	if (f) {
		// logfile may close in other thread
		if (ATOM_CAS_POINTER(&ctx->logfile, f, NULL)) {
			skynet_log_close(context, f, handle);
		}
	}
	skynet_context_release(ctx);
	return NULL;
}