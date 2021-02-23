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
typedef  int /*<<< orphan*/  OSSL_PARAM ;
typedef  int /*<<< orphan*/  KDF_HKDF ;

/* Variables and functions */
 int /*<<< orphan*/  OSSL_KDF_PARAM_SIZE ; 
 int /*<<< orphan*/ * OSSL_PARAM_locate (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int OSSL_PARAM_set_size_t (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kdf_hkdf_size (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int kdf_hkdf_get_ctx_params(void *vctx, OSSL_PARAM params[])
{
    KDF_HKDF *ctx = (KDF_HKDF *)vctx;
    OSSL_PARAM *p;

    if ((p = OSSL_PARAM_locate(params, OSSL_KDF_PARAM_SIZE)) != NULL)
        return OSSL_PARAM_set_size_t(p, kdf_hkdf_size(ctx));
    return -2;
}