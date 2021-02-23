#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct skcipher_givcrypt_request {int dummy; } ;
struct eseqiv_ctx {int /*<<< orphan*/  lock; int /*<<< orphan*/  salt; } ;
struct crypto_ablkcipher {int dummy; } ;
struct TYPE_2__ {scalar_t__ givencrypt; } ;

/* Variables and functions */
 TYPE_1__* crypto_ablkcipher_crt (struct crypto_ablkcipher*) ; 
 struct eseqiv_ctx* crypto_ablkcipher_ctx (struct crypto_ablkcipher*) ; 
 int /*<<< orphan*/  crypto_ablkcipher_ivsize (struct crypto_ablkcipher*) ; 
 int /*<<< orphan*/  crypto_default_rng ; 
 int crypto_rng_get_bytes (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int eseqiv_givencrypt (struct skcipher_givcrypt_request*) ; 
 struct crypto_ablkcipher* skcipher_givcrypt_reqtfm (struct skcipher_givcrypt_request*) ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int eseqiv_givencrypt_first(struct skcipher_givcrypt_request *req)
{
	struct crypto_ablkcipher *geniv = skcipher_givcrypt_reqtfm(req);
	struct eseqiv_ctx *ctx = crypto_ablkcipher_ctx(geniv);
	int err = 0;

	spin_lock_bh(&ctx->lock);
	if (crypto_ablkcipher_crt(geniv)->givencrypt != eseqiv_givencrypt_first)
		goto unlock;

	crypto_ablkcipher_crt(geniv)->givencrypt = eseqiv_givencrypt;
	err = crypto_rng_get_bytes(crypto_default_rng, ctx->salt,
				   crypto_ablkcipher_ivsize(geniv));

unlock:
	spin_unlock_bh(&ctx->lock);

	if (err)
		return err;

	return eseqiv_givencrypt(req);
}