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
typedef  int /*<<< orphan*/  SHA1_CTX ;

/* Variables and functions */
 int /*<<< orphan*/  SHA1Final (unsigned char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SHA1Init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SHA1Update (int /*<<< orphan*/ *,unsigned char*,size_t) ; 

void sha1hex(char *digest, char *script, size_t len) {
    SHA1_CTX ctx;
    unsigned char hash[20];
    char *cset = "0123456789abcdef";
    int j;

    SHA1Init(&ctx);
    SHA1Update(&ctx,(unsigned char*)script,len);
    SHA1Final(hash,&ctx);

    for (j = 0; j < 20; j++) {
        digest[j*2] = cset[((hash[j]&0xF0)>>4)];
        digest[j*2+1] = cset[(hash[j]&0xF)];
    }
    digest[40] = '\0';
}