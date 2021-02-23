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
struct TYPE_4__ {int /*<<< orphan*/  ec; } ;
struct TYPE_5__ {TYPE_1__ pkey; } ;
typedef  TYPE_2__ EVP_PKEY ;
typedef  int /*<<< orphan*/  BIO ;
typedef  int /*<<< orphan*/  ASN1_PCTX ;

/* Variables and functions */
 int /*<<< orphan*/  EC_KEY_PRINT_PRIVATE ; 
 int do_EC_KEY_print (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int eckey_priv_print(BIO *bp, const EVP_PKEY *pkey, int indent,
                            ASN1_PCTX *ctx)
{
    return do_EC_KEY_print(bp, pkey->pkey.ec, indent, EC_KEY_PRINT_PRIVATE);
}