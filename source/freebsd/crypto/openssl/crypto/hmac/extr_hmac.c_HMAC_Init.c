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
typedef  int /*<<< orphan*/  HMAC_CTX ;
typedef  int /*<<< orphan*/  EVP_MD ;

/* Variables and functions */
 int /*<<< orphan*/  HMAC_CTX_reset (int /*<<< orphan*/ *) ; 
 int HMAC_Init_ex (int /*<<< orphan*/ *,void const*,int,int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 

int HMAC_Init(HMAC_CTX *ctx, const void *key, int len, const EVP_MD *md)
{
    if (key && md)
        HMAC_CTX_reset(ctx);
    return HMAC_Init_ex(ctx, key, len, md, NULL);
}