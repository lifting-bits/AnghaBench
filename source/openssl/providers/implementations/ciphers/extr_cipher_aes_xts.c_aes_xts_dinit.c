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

/* Variables and functions */
 int aes_xts_init (void*,unsigned char const*,size_t,unsigned char const*,size_t,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int aes_xts_dinit(void *vctx, const unsigned char *key, size_t keylen,
                         const unsigned char *iv, size_t ivlen)
{
    return aes_xts_init(vctx, key, keylen, iv, ivlen, 0);
}