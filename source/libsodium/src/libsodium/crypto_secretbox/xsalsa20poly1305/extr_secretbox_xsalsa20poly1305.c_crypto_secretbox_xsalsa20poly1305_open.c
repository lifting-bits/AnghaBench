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
 scalar_t__ crypto_onetimeauth_poly1305_verify (unsigned char const*,unsigned char const*,unsigned long long,unsigned char*) ; 
 int /*<<< orphan*/  crypto_stream_xsalsa20 (unsigned char*,int,unsigned char const*,unsigned char const*) ; 
 int /*<<< orphan*/  crypto_stream_xsalsa20_xor (unsigned char*,unsigned char const*,unsigned long long,unsigned char const*,unsigned char const*) ; 

int
crypto_secretbox_xsalsa20poly1305_open(unsigned char *m, const unsigned char *c,
                                       unsigned long long clen,
                                       const unsigned char *n,
                                       const unsigned char *k)
{
    unsigned char subkey[32];
    int           i;

    if (clen < 32) {
        return -1;
    }
    crypto_stream_xsalsa20(subkey, 32, n, k);
    if (crypto_onetimeauth_poly1305_verify(c + 16, c + 32,
                                           clen - 32, subkey) != 0) {
        return -1;
    }
    crypto_stream_xsalsa20_xor(m, c, clen, n, k);
    for (i = 0; i < 32; ++i) {
        m[i] = 0;
    }
    return 0;
}