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
typedef  int /*<<< orphan*/  OSSL_PROVIDER ;
typedef  int /*<<< orphan*/  OSSL_ALGORITHM ;

/* Variables and functions */
#define  OSSL_OP_CIPHER 131 
#define  OSSL_OP_DIGEST 130 
#define  OSSL_OP_KDF 129 
#define  OSSL_OP_MAC 128 
 int /*<<< orphan*/  const* fips_ciphers ; 
 int /*<<< orphan*/  const* fips_digests ; 
 int /*<<< orphan*/  const* fips_kdfs ; 
 int /*<<< orphan*/  const* fips_macs ; 

__attribute__((used)) static const OSSL_ALGORITHM *fips_query(OSSL_PROVIDER *prov,
                                         int operation_id,
                                         int *no_cache)
{
    *no_cache = 0;
    switch (operation_id) {
    case OSSL_OP_DIGEST:
        return fips_digests;
    case OSSL_OP_CIPHER:
        return fips_ciphers;
    case OSSL_OP_MAC:
        return fips_macs;
    case OSSL_OP_KDF:
        return fips_kdfs;
    }
    return NULL;
}