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
typedef  int /*<<< orphan*/  pem_password_cb ;
typedef  int /*<<< orphan*/  EVP_PKEY ;
typedef  int /*<<< orphan*/  EVP_CIPHER ;
typedef  int /*<<< orphan*/  BIO ;

/* Variables and functions */
 int do_pk8pkey (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int,int /*<<< orphan*/  const*,char*,int,int /*<<< orphan*/ *,void*) ; 

int i2d_PKCS8PrivateKey_bio(BIO *bp, EVP_PKEY *x, const EVP_CIPHER *enc,
                            char *kstr, int klen,
                            pem_password_cb *cb, void *u)
{
    return do_pk8pkey(bp, x, 1, -1, enc, kstr, klen, cb, u);
}