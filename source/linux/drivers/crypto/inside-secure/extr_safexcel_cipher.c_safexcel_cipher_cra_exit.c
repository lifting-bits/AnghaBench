#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {TYPE_1__* ctxr; } ;
struct safexcel_cipher_ctx {TYPE_2__ base; int /*<<< orphan*/  key; } ;
struct crypto_tfm {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  data; } ;

/* Variables and functions */
 int ENOMEM ; 
 struct safexcel_cipher_ctx* crypto_tfm_ctx (struct crypto_tfm*) ; 
 int /*<<< orphan*/  memzero_explicit (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int safexcel_cipher_cra_exit(struct crypto_tfm *tfm)
{
	struct safexcel_cipher_ctx *ctx = crypto_tfm_ctx(tfm);

	memzero_explicit(ctx->key, sizeof(ctx->key));

	/* context not allocated, skip invalidation */
	if (!ctx->base.ctxr)
		return -ENOMEM;

	memzero_explicit(ctx->base.ctxr->data, sizeof(ctx->base.ctxr->data));
	return 0;
}