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
typedef  int /*<<< orphan*/  X509_VERIFY_PARAM ;
struct TYPE_3__ {int /*<<< orphan*/  param; } ;
typedef  TYPE_1__ X509_STORE_CTX ;

/* Variables and functions */
 int X509_VERIFY_PARAM_inherit (int /*<<< orphan*/ ,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/ * X509_VERIFY_PARAM_lookup (char const*) ; 

int X509_STORE_CTX_set_default(X509_STORE_CTX *ctx, const char *name)
{
    const X509_VERIFY_PARAM *param;

    param = X509_VERIFY_PARAM_lookup(name);
    if (param == NULL)
        return 0;
    return X509_VERIFY_PARAM_inherit(ctx->param, param);
}