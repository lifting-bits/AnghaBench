#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  seed48; } ;
typedef  TYPE_1__ fz_context ;

/* Variables and functions */
 double fz_erand48 (TYPE_1__*,int /*<<< orphan*/ ) ; 

double fz_drand48(fz_context *ctx)
{
	return fz_erand48(ctx, ctx->seed48);
}