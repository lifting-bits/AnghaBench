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
 int /*<<< orphan*/  EVP_MD_CTX_md_data (int /*<<< orphan*/ *) ; 
 int SHA224_Update (int /*<<< orphan*/ ,void const*,size_t) ; 

__attribute__((used)) static int update224(EVP_MD_CTX *ctx, const void *data, size_t count)
{
    return SHA224_Update(EVP_MD_CTX_md_data(ctx), data, count);
}