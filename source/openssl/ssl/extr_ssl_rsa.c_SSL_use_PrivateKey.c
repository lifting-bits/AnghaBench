#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  cert; } ;
typedef  TYPE_1__ SSL ;
typedef  int /*<<< orphan*/  EVP_PKEY ;

/* Variables and functions */
 int /*<<< orphan*/  ERR_R_PASSED_NULL_PARAMETER ; 
 int /*<<< orphan*/  SSL_F_SSL_USE_PRIVATEKEY ; 
 int /*<<< orphan*/  SSLerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int ssl_set_pkey (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

int SSL_use_PrivateKey(SSL *ssl, EVP_PKEY *pkey)
{
    int ret;

    if (pkey == NULL) {
        SSLerr(SSL_F_SSL_USE_PRIVATEKEY, ERR_R_PASSED_NULL_PARAMETER);
        return 0;
    }
    ret = ssl_set_pkey(ssl->cert, pkey);
    return ret;
}