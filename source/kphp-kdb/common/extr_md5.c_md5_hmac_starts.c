#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  sum ;
struct TYPE_5__ {unsigned char* ipad; unsigned char* opad; } ;
typedef  TYPE_1__ md5_context ;

/* Variables and functions */
 int /*<<< orphan*/  md5 (unsigned char*,int,unsigned char*) ; 
 int /*<<< orphan*/  md5_starts (TYPE_1__*) ; 
 int /*<<< orphan*/  md5_update (TYPE_1__*,unsigned char*,int) ; 
 int /*<<< orphan*/  memset (unsigned char*,int,int) ; 

void md5_hmac_starts( md5_context *ctx, unsigned char *key, int keylen )
{
    int i;
    unsigned char sum[16];

    if( keylen > 64 )
    {
        md5( key, keylen, sum );
        keylen = 16;
        key = sum;
    }

    memset( ctx->ipad, 0x36, 64 );
    memset( ctx->opad, 0x5C, 64 );

    for( i = 0; i < keylen; i++ )
    {
        ctx->ipad[i] = (unsigned char)( ctx->ipad[i] ^ key[i] );
        ctx->opad[i] = (unsigned char)( ctx->opad[i] ^ key[i] );
    }

    md5_starts( ctx );
    md5_update( ctx, ctx->ipad, 64 );

    memset( sum, 0, sizeof( sum ) );
}