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
typedef  TYPE_1__* hx509_verify_ctx ;
struct TYPE_3__ {int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  HX509_VERIFY_CTX_F_REQUIRE_RFC3280 ; 

void
hx509_verify_set_strict_rfc3280_verification(hx509_verify_ctx ctx, int boolean)
{
    if (boolean)
	ctx->flags |= HX509_VERIFY_CTX_F_REQUIRE_RFC3280;
    else
	ctx->flags &= ~HX509_VERIFY_CTX_F_REQUIRE_RFC3280;
}