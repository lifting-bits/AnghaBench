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
struct ahx {int dummy; } ;
typedef  int /*<<< orphan*/  fz_context ;

/* Variables and functions */
 int /*<<< orphan*/  fz_free (int /*<<< orphan*/ *,struct ahx*) ; 

__attribute__((used)) static void ahx_drop(fz_context *ctx, void *opaque)
{
	struct ahx *state = opaque;
	fz_free(ctx, state);
}