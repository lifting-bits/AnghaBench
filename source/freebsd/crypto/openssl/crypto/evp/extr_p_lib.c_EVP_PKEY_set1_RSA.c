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
typedef  int /*<<< orphan*/  RSA ;
typedef  int /*<<< orphan*/  EVP_PKEY ;

/* Variables and functions */
 int EVP_PKEY_assign_RSA (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RSA_up_ref (int /*<<< orphan*/ *) ; 

int EVP_PKEY_set1_RSA(EVP_PKEY *pkey, RSA *key)
{
    int ret = EVP_PKEY_assign_RSA(pkey, key);
    if (ret)
        RSA_up_ref(key);
    return ret;
}