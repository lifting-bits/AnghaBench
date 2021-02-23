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
typedef  int /*<<< orphan*/  KDF_HKDF ;

/* Variables and functions */
 int /*<<< orphan*/  OPENSSL_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kdf_hkdf_reset (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void kdf_hkdf_free(void *vctx)
{
    KDF_HKDF *ctx = (KDF_HKDF *)vctx;

    kdf_hkdf_reset(ctx);
    OPENSSL_free(ctx);
}