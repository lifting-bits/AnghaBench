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
typedef  int /*<<< orphan*/  EVP_MD_CTX ;

/* Variables and functions */
 int EVP_DigestFinal_ex (int /*<<< orphan*/ *,unsigned char*,unsigned int*) ; 
 int /*<<< orphan*/  EVP_MD_CTX_reset (int /*<<< orphan*/ *) ; 

int EVP_DigestFinal(EVP_MD_CTX *ctx, unsigned char *md, unsigned int *size)
{
    int ret;
    ret = EVP_DigestFinal_ex(ctx, md, size);
    EVP_MD_CTX_reset(ctx);
    return ret;
}