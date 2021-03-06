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
struct TYPE_5__ {int num; scalar_t__ iv; } ;
struct TYPE_4__ {int /*<<< orphan*/  ks3; int /*<<< orphan*/  ks2; int /*<<< orphan*/  ks1; } ;
typedef  TYPE_1__ PROV_TDES_CTX ;
typedef  TYPE_2__ PROV_CIPHER_CTX ;
typedef  int /*<<< orphan*/  DES_cblock ;

/* Variables and functions */
 int /*<<< orphan*/  DES_ede3_ofb64_encrypt (unsigned char const*,unsigned char*,long,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int*) ; 
 size_t MAXCHUNK ; 

__attribute__((used)) static int cipher_hw_tdes_ofb(PROV_CIPHER_CTX *ctx, unsigned char *out,
                              const unsigned char *in, size_t inl)
{
    PROV_TDES_CTX *tctx = (PROV_TDES_CTX *)ctx;
    int num = ctx->num;

    while (inl >= MAXCHUNK) {
        DES_ede3_ofb64_encrypt(in, out, (long)MAXCHUNK, &tctx->ks1, &tctx->ks2,
                               &tctx->ks3, (DES_cblock *)ctx->iv, &num);
        inl -= MAXCHUNK;
        in += MAXCHUNK;
        out += MAXCHUNK;
    }
    if (inl > 0) {
        DES_ede3_ofb64_encrypt(in, out, (long)inl, &tctx->ks1, &tctx->ks2,
                               &tctx->ks3, (DES_cblock *)ctx->iv, &num);
    }
    ctx->num = num;
    return 1;
}