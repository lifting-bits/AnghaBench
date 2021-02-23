#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  key; int /*<<< orphan*/  ctx; } ;
struct TYPE_5__ {int /*<<< orphan*/ * ctr_crypt; int /*<<< orphan*/  ige_crypt; int /*<<< orphan*/  cbc_crypt; TYPE_1__ u; } ;
typedef  TYPE_2__ vk_aes_ctx_t ;

/* Variables and functions */
 int /*<<< orphan*/  AES_set_decrypt_key (unsigned char*,int,int /*<<< orphan*/ *) ; 
 scalar_t__ aesni256_is_supported () ; 
 int /*<<< orphan*/  aesni256_set_decrypt_key (int /*<<< orphan*/ *,unsigned char*) ; 
 int /*<<< orphan*/  vk_aesni_cbc_decrypt ; 
 int /*<<< orphan*/  vk_aesni_ige_decrypt ; 
 int /*<<< orphan*/  vk_ssl_aes_cbc_decrypt ; 
 int /*<<< orphan*/  vk_ssl_aes_ige_decrypt ; 

void vk_aes_set_decrypt_key (vk_aes_ctx_t *ctx, unsigned char *key, int bits) {
  if (aesni256_is_supported () && bits == 256) {
    aesni256_set_decrypt_key (&ctx->u.ctx, key);
    ctx->cbc_crypt = vk_aesni_cbc_decrypt;
    ctx->ige_crypt = vk_aesni_ige_decrypt;
  } else {
    AES_set_decrypt_key (key, bits, &ctx->u.key);
    ctx->cbc_crypt = vk_ssl_aes_cbc_decrypt;
    ctx->ige_crypt = vk_ssl_aes_ige_decrypt;
  }
  ctx->ctr_crypt = NULL; /* NOTICE: vk_aes_set_encrypt_key should be used for CTR decryption */
}