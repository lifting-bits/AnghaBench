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
struct dcp_async_ctx {int /*<<< orphan*/  fallback; } ;
struct crypto_tfm {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  crypto_free_sync_skcipher (int /*<<< orphan*/ ) ; 
 struct dcp_async_ctx* crypto_tfm_ctx (struct crypto_tfm*) ; 

__attribute__((used)) static void mxs_dcp_aes_fallback_exit(struct crypto_tfm *tfm)
{
	struct dcp_async_ctx *actx = crypto_tfm_ctx(tfm);

	crypto_free_sync_skcipher(actx->fallback);
}