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
struct TYPE_5__ {TYPE_1__* handshake; } ;
typedef  TYPE_2__ mbedtls_ssl_context ;
typedef  int /*<<< orphan*/  mbedtls_sha512_context ;
struct TYPE_4__ {int /*<<< orphan*/  fin_sha512; } ;

/* Variables and functions */
 int /*<<< orphan*/  MBEDTLS_SSL_DEBUG_BUF (int,char*,unsigned char*,int) ; 
 int /*<<< orphan*/  MBEDTLS_SSL_DEBUG_MSG (int,char*) ; 
 int /*<<< orphan*/  mbedtls_sha512_clone (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mbedtls_sha512_finish (int /*<<< orphan*/ *,unsigned char*) ; 
 int /*<<< orphan*/  mbedtls_sha512_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mbedtls_sha512_init (int /*<<< orphan*/ *) ; 

void ssl_calc_verify_tls_sha384( mbedtls_ssl_context *ssl, unsigned char hash[48] )
{
    mbedtls_sha512_context sha512;

    mbedtls_sha512_init( &sha512 );

    MBEDTLS_SSL_DEBUG_MSG( 2, ( "=> calc verify sha384" ) );

    mbedtls_sha512_clone( &sha512, &ssl->handshake->fin_sha512 );
    mbedtls_sha512_finish( &sha512, hash );

    MBEDTLS_SSL_DEBUG_BUF( 3, "calculated verify result", hash, 48 );
    MBEDTLS_SSL_DEBUG_MSG( 2, ( "<= calc verify" ) );

    mbedtls_sha512_free( &sha512 );

    return;
}