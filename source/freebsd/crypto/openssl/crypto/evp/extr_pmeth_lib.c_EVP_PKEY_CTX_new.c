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
typedef  int /*<<< orphan*/  EVP_PKEY_CTX ;
typedef  int /*<<< orphan*/  EVP_PKEY ;
typedef  int /*<<< orphan*/  ENGINE ;

/* Variables and functions */
 int /*<<< orphan*/ * int_ctx_new (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 

EVP_PKEY_CTX *EVP_PKEY_CTX_new(EVP_PKEY *pkey, ENGINE *e)
{
    return int_ctx_new(pkey, e, -1);
}