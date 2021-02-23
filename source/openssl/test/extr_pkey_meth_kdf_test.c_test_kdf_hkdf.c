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
typedef  int /*<<< orphan*/  out ;
typedef  int /*<<< orphan*/  expected ;
typedef  int /*<<< orphan*/  EVP_PKEY_CTX ;

/* Variables and functions */
 scalar_t__ EVP_PKEY_CTX_add1_hkdf_info (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  EVP_PKEY_CTX_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * EVP_PKEY_CTX_new_id (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ EVP_PKEY_CTX_set1_hkdf_key (int /*<<< orphan*/ *,char*,int) ; 
 scalar_t__ EVP_PKEY_CTX_set1_hkdf_salt (int /*<<< orphan*/ *,char*,int) ; 
 scalar_t__ EVP_PKEY_CTX_set_hkdf_md (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  EVP_PKEY_HKDF ; 
 scalar_t__ EVP_PKEY_derive (int /*<<< orphan*/ *,unsigned char*,size_t*) ; 
 scalar_t__ EVP_PKEY_derive_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  EVP_sha256 () ; 
 int /*<<< orphan*/  TEST_error (char*) ; 
 int /*<<< orphan*/  TEST_mem_eq (unsigned char*,int,unsigned char const*,int) ; 

__attribute__((used)) static int test_kdf_hkdf(void)
{
    int ret = 0;
    EVP_PKEY_CTX *pctx;
    unsigned char out[10];
    size_t outlen = sizeof(out);

    if ((pctx = EVP_PKEY_CTX_new_id(EVP_PKEY_HKDF, NULL)) == NULL) {
        TEST_error("EVP_PKEY_HKDF");
        goto err;
    }
    if (EVP_PKEY_derive_init(pctx) <= 0) {
        TEST_error("EVP_PKEY_derive_init");
        goto err;
    }
    if (EVP_PKEY_CTX_set_hkdf_md(pctx, EVP_sha256()) <= 0) {
        TEST_error("EVP_PKEY_CTX_set_hkdf_md");
        goto err;
    }
    if (EVP_PKEY_CTX_set1_hkdf_salt(pctx, "salt", 4) <= 0) {
        TEST_error("EVP_PKEY_CTX_set1_hkdf_salt");
        goto err;
    }
    if (EVP_PKEY_CTX_set1_hkdf_key(pctx, "secret", 6) <= 0) {
        TEST_error("EVP_PKEY_CTX_set1_hkdf_key");
        goto err;
    }
    if (EVP_PKEY_CTX_add1_hkdf_info(pctx, "label", 5) <= 0) {
        TEST_error("EVP_PKEY_CTX_set1_hkdf_info");
        goto err;
    }
    if (EVP_PKEY_derive(pctx, out, &outlen) <= 0) {
        TEST_error("EVP_PKEY_derive");
        goto err;
    }

    {
        const unsigned char expected[sizeof(out)] = {
            0x2a, 0xc4, 0x36, 0x9f, 0x52, 0x59, 0x96, 0xf8, 0xde, 0x13
        };
        if (!TEST_mem_eq(out, sizeof(out), expected, sizeof(expected))) {
            goto err;
        }
    }
    ret = 1;
err:
    EVP_PKEY_CTX_free(pctx);
    return ret;
}