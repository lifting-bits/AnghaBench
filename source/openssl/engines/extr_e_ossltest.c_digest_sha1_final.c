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
 int SHA1_Final (unsigned char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SHA_DIGEST_LENGTH ; 
 int /*<<< orphan*/  data (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fill_known_data (unsigned char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int digest_sha1_final(EVP_MD_CTX *ctx, unsigned char *md)
{
    int ret;
    ret = SHA1_Final(md, data(ctx));

    if (ret > 0) {
        fill_known_data(md, SHA_DIGEST_LENGTH);
    }
    return ret;
}