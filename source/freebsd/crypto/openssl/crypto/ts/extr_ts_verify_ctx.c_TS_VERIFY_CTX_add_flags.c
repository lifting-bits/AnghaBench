#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int flags; } ;
typedef  TYPE_1__ TS_VERIFY_CTX ;

/* Variables and functions */

int TS_VERIFY_CTX_add_flags(TS_VERIFY_CTX *ctx, int f)
{
    ctx->flags |= f;
    return ctx->flags;
}