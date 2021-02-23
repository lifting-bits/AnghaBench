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
struct TYPE_3__ {int /*<<< orphan*/  gcm; } ;
typedef  TYPE_1__ PROV_GCM_CTX ;

/* Variables and functions */
 scalar_t__ CRYPTO_gcm128_aad (int /*<<< orphan*/ *,unsigned char const*,size_t) ; 

int gcm_aad_update(PROV_GCM_CTX *ctx, const unsigned char *aad, size_t aad_len)
{
    return CRYPTO_gcm128_aad(&ctx->gcm, aad, aad_len) == 0;
}