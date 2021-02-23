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
struct dtoa_context {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  jv_mem_free (struct dtoa_context*) ; 
 int /*<<< orphan*/  jvp_dtoa_context_free (struct dtoa_context*) ; 

__attribute__((used)) static void tsd_dtoa_ctx_dtor(struct dtoa_context *ctx) {
  if (ctx) {
    jvp_dtoa_context_free(ctx);
    jv_mem_free(ctx);
  }
}