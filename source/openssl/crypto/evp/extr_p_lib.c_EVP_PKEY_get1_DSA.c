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
typedef  int /*<<< orphan*/  EVP_PKEY ;
typedef  int /*<<< orphan*/  DSA ;

/* Variables and functions */
 int /*<<< orphan*/  DSA_up_ref (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * EVP_PKEY_get0_DSA (int /*<<< orphan*/ *) ; 

DSA *EVP_PKEY_get1_DSA(EVP_PKEY *pkey)
{
    DSA *ret = EVP_PKEY_get0_DSA(pkey);
    if (ret != NULL)
        DSA_up_ref(ret);
    return ret;
}