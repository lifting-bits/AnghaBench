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
struct skcipher_walk {unsigned int nbytes; } ;
struct skcipher_request {int dummy; } ;
struct crypto_skcipher {int dummy; } ;
struct cast5_ctx {int dummy; } ;

/* Variables and functions */
 unsigned int __cbc_decrypt (struct cast5_ctx*,struct skcipher_walk*) ; 
 int cast5_fpu_begin (int,struct skcipher_walk*,unsigned int) ; 
 int /*<<< orphan*/  cast5_fpu_end (int) ; 
 struct cast5_ctx* crypto_skcipher_ctx (struct crypto_skcipher*) ; 
 struct crypto_skcipher* crypto_skcipher_reqtfm (struct skcipher_request*) ; 
 int skcipher_walk_done (struct skcipher_walk*,unsigned int) ; 
 int skcipher_walk_virt (struct skcipher_walk*,struct skcipher_request*,int) ; 

__attribute__((used)) static int cbc_decrypt(struct skcipher_request *req)
{
	struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
	struct cast5_ctx *ctx = crypto_skcipher_ctx(tfm);
	bool fpu_enabled = false;
	struct skcipher_walk walk;
	unsigned int nbytes;
	int err;

	err = skcipher_walk_virt(&walk, req, false);

	while ((nbytes = walk.nbytes)) {
		fpu_enabled = cast5_fpu_begin(fpu_enabled, &walk, nbytes);
		nbytes = __cbc_decrypt(ctx, &walk);
		err = skcipher_walk_done(&walk, nbytes);
	}

	cast5_fpu_end(fpu_enabled);
	return err;
}