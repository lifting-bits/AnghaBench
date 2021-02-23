#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int /*<<< orphan*/ * h; scalar_t__ buflen; scalar_t__ buf; } ;
typedef  TYPE_1__ BLAKE2S_CTX ;

/* Variables and functions */
 int /*<<< orphan*/  OPENSSL_cleanse (TYPE_1__*,int) ; 
 int /*<<< orphan*/  blake2s_compress (TYPE_1__*,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  blake2s_set_lastblock (TYPE_1__*) ; 
 int /*<<< orphan*/  memset (scalar_t__,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  store32 (unsigned char*,int /*<<< orphan*/ ) ; 

int BLAKE2s_Final(unsigned char *md, BLAKE2S_CTX *c)
{
    int i;

    blake2s_set_lastblock(c);
    /* Padding */
    memset(c->buf + c->buflen, 0, sizeof(c->buf) - c->buflen);
    blake2s_compress(c, c->buf, c->buflen);

    /* Output full hash to temp buffer */
    for (i = 0; i < 8; ++i) {
        store32(md + sizeof(c->h[i]) * i, c->h[i]);
    }

    OPENSSL_cleanse(c, sizeof(BLAKE2S_CTX));
    return 1;
}