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
struct TYPE_3__ {int /*<<< orphan*/  param; } ;
typedef  TYPE_1__ X509_STORE ;

/* Variables and functions */
 int /*<<< orphan*/  X509_VERIFY_PARAM_set_depth (int /*<<< orphan*/ ,int) ; 

int X509_STORE_set_depth(X509_STORE *ctx, int depth)
{
    X509_VERIFY_PARAM_set_depth(ctx->param, depth);
    return 1;
}