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
typedef  int /*<<< orphan*/  u8 ;
struct des_ctx {unsigned int key_length; scalar_t__ expkey; scalar_t__ controlr_M; } ;
struct crypto_tfm {int dummy; } ;

/* Variables and functions */
 struct des_ctx* crypto_tfm_ctx (struct crypto_tfm*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,unsigned int) ; 

int des_setkey(struct crypto_tfm *tfm, const u8 *key,
                      unsigned int keylen)
{
        struct des_ctx *dctx = crypto_tfm_ctx(tfm);

        //printk("setkey in %s\n", __FILE__);

        dctx->controlr_M = 0;   // des
        dctx->key_length = keylen;

        memcpy ((u8 *) (dctx->expkey), key, keylen);

        return 0;
}