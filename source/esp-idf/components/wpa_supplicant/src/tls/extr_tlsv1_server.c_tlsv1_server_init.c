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
typedef  int /*<<< orphan*/  u16 ;
struct tlsv1_server {size_t num_cipher_suites; int /*<<< orphan*/ * cipher_suites; int /*<<< orphan*/  verify; int /*<<< orphan*/  state; struct tlsv1_credentials* cred; } ;
struct tlsv1_credentials {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CLIENT_HELLO ; 
 int /*<<< orphan*/  MSG_DEBUG ; 
 int /*<<< orphan*/  TLS_RSA_WITH_3DES_EDE_CBC_SHA ; 
 int /*<<< orphan*/  TLS_RSA_WITH_AES_128_CBC_SHA ; 
 int /*<<< orphan*/  TLS_RSA_WITH_AES_256_CBC_SHA ; 
 int /*<<< orphan*/  TLS_RSA_WITH_RC4_128_MD5 ; 
 int /*<<< orphan*/  TLS_RSA_WITH_RC4_128_SHA ; 
 int /*<<< orphan*/  os_free (struct tlsv1_server*) ; 
 scalar_t__ os_zalloc (int) ; 
 scalar_t__ tls_verify_hash_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wpa_printf (int /*<<< orphan*/ ,char*) ; 

struct tlsv1_server * tlsv1_server_init(struct tlsv1_credentials *cred)
{
	struct tlsv1_server *conn;
	size_t count;
	u16 *suites;

	conn = (struct tlsv1_server *)os_zalloc(sizeof(*conn));
	if (conn == NULL)
		return NULL;

	conn->cred = cred;

	conn->state = CLIENT_HELLO;

	if (tls_verify_hash_init(&conn->verify) < 0) {
		wpa_printf(MSG_DEBUG, "TLSv1: Failed to initialize verify "
			   "hash");
		os_free(conn);
		return NULL;
	}

	count = 0;
	suites = conn->cipher_suites;
	suites[count++] = TLS_RSA_WITH_AES_256_CBC_SHA;
	suites[count++] = TLS_RSA_WITH_AES_128_CBC_SHA;
#ifdef CONFIG_DES3
	suites[count++] = TLS_RSA_WITH_3DES_EDE_CBC_SHA;
#endif
	suites[count++] = TLS_RSA_WITH_RC4_128_SHA;
	suites[count++] = TLS_RSA_WITH_RC4_128_MD5;
	conn->num_cipher_suites = count;

	return conn;
}