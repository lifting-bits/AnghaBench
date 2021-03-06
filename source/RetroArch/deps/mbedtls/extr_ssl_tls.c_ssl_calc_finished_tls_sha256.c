#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  padbuf ;
struct TYPE_11__ {int /*<<< orphan*/  master; } ;
typedef  TYPE_2__ mbedtls_ssl_session ;
struct TYPE_12__ {TYPE_1__* handshake; TYPE_2__* session; TYPE_2__* session_negotiate; } ;
typedef  TYPE_3__ mbedtls_ssl_context ;
struct TYPE_13__ {scalar_t__ state; } ;
typedef  TYPE_4__ mbedtls_sha256_context ;
struct TYPE_10__ {int /*<<< orphan*/  (* tls_prf ) (int /*<<< orphan*/ ,int,char const*,unsigned char*,int,unsigned char*,int) ;int /*<<< orphan*/  fin_sha256; } ;

/* Variables and functions */
 int /*<<< orphan*/  MBEDTLS_SSL_DEBUG_BUF (int,char*,unsigned char*,int) ; 
 int /*<<< orphan*/  MBEDTLS_SSL_DEBUG_MSG (int,char*) ; 
 int MBEDTLS_SSL_IS_CLIENT ; 
 int /*<<< orphan*/  mbedtls_sha256_clone (TYPE_4__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mbedtls_sha256_finish (TYPE_4__*,unsigned char*) ; 
 int /*<<< orphan*/  mbedtls_sha256_free (TYPE_4__*) ; 
 int /*<<< orphan*/  mbedtls_sha256_init (TYPE_4__*) ; 
 int /*<<< orphan*/  mbedtls_zeroize (unsigned char*,int) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,int,char const*,unsigned char*,int,unsigned char*,int) ; 

__attribute__((used)) static void ssl_calc_finished_tls_sha256(
                mbedtls_ssl_context *ssl, unsigned char *buf, int from )
{
    int len = 12;
    const char *sender;
    mbedtls_sha256_context sha256;
    unsigned char padbuf[32];

    mbedtls_ssl_session *session = ssl->session_negotiate;
    if( !session )
        session = ssl->session;

    mbedtls_sha256_init( &sha256 );

    MBEDTLS_SSL_DEBUG_MSG( 2, ( "=> calc  finished tls sha256" ) );

    mbedtls_sha256_clone( &sha256, &ssl->handshake->fin_sha256 );

    /*
     * TLSv1.2:
     *   hash = PRF( master, finished_label,
     *               Hash( handshake ) )[0.11]
     */

#if !defined(MBEDTLS_SHA256_ALT)
    MBEDTLS_SSL_DEBUG_BUF( 4, "finished sha2 state", (unsigned char *)
                   sha256.state, sizeof( sha256.state ) );
#endif

    sender = ( from == MBEDTLS_SSL_IS_CLIENT )
             ? "client finished"
             : "server finished";

    mbedtls_sha256_finish( &sha256, padbuf );

    ssl->handshake->tls_prf( session->master, 48, sender,
                             padbuf, 32, buf, len );

    MBEDTLS_SSL_DEBUG_BUF( 3, "calc finished result", buf, len );

    mbedtls_sha256_free( &sha256 );

    mbedtls_zeroize(  padbuf, sizeof(  padbuf ) );

    MBEDTLS_SSL_DEBUG_MSG( 2, ( "<= calc  finished" ) );
}