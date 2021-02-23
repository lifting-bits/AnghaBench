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
 size_t* c ; 
 int /*<<< orphan*/  crypto_secretbox (size_t*,scalar_t__*,size_t,scalar_t__*,int /*<<< orphan*/ ) ; 
 size_t crypto_secretbox_NONCEBYTES ; 
 size_t crypto_secretbox_ZEROBYTES ; 
 int /*<<< orphan*/  crypto_secretbox_keygen (int /*<<< orphan*/ ) ; 
 scalar_t__ crypto_secretbox_open (scalar_t__*,size_t*,size_t,scalar_t__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  k ; 
 scalar_t__* m ; 
 scalar_t__* m2 ; 
 scalar_t__* n ; 
 int /*<<< orphan*/  printf (char*) ; 
 size_t rand () ; 
 int /*<<< orphan*/  randombytes_buf (scalar_t__*,size_t) ; 

int
main(void)
{
    size_t mlen;
    size_t i;
    int    caught;

    for (mlen = 0; mlen < 1000 && mlen + crypto_secretbox_ZEROBYTES < sizeof m;
         ++mlen) {
        crypto_secretbox_keygen(k);
        randombytes_buf(n, crypto_secretbox_NONCEBYTES);
        randombytes_buf(m + crypto_secretbox_ZEROBYTES, mlen);
        crypto_secretbox(c, m, mlen + crypto_secretbox_ZEROBYTES, n, k);
        caught = 0;
        while (caught < 10) {
            c[rand() % (mlen + crypto_secretbox_ZEROBYTES)] = rand();
            if (crypto_secretbox_open(m2, c, mlen + crypto_secretbox_ZEROBYTES,
                                      n, k) == 0) {
                for (i = 0; i < mlen + crypto_secretbox_ZEROBYTES; ++i) {
                    if (m2[i] != m[i]) {
                        printf("forgery\n");
                        return 100;
                    }
                }
            } else {
                ++caught;
            }
        }
    }
    return 0;
}