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
struct tlsv1_credentials {int dummy; } ;
struct tls_connection_params {int flags; int /*<<< orphan*/  private_key_blob_len; int /*<<< orphan*/  private_key_blob; int /*<<< orphan*/  private_key_passwd; int /*<<< orphan*/  private_key; int /*<<< orphan*/  client_cert_blob_len; int /*<<< orphan*/  client_cert_blob; int /*<<< orphan*/  client_cert; int /*<<< orphan*/  ca_path; int /*<<< orphan*/  ca_cert_blob_len; int /*<<< orphan*/  ca_cert_blob; int /*<<< orphan*/  ca_cert; } ;
struct tls_connection {int /*<<< orphan*/ * client; } ;

/* Variables and functions */
 int /*<<< orphan*/  MSG_INFO ; 
 int TLS_CONN_DISABLE_TIME_CHECKS ; 
 scalar_t__ tlsv1_client_set_cred (int /*<<< orphan*/ *,struct tlsv1_credentials*) ; 
 int /*<<< orphan*/  tlsv1_client_set_time_checks (int /*<<< orphan*/ *,int) ; 
 struct tlsv1_credentials* tlsv1_cred_alloc () ; 
 int /*<<< orphan*/  tlsv1_cred_free (struct tlsv1_credentials*) ; 
 scalar_t__ tlsv1_set_ca_cert (struct tlsv1_credentials*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ tlsv1_set_cert (struct tlsv1_credentials*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ tlsv1_set_private_key (struct tlsv1_credentials*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wpa_printf (int /*<<< orphan*/ ,char*) ; 

int tls_connection_set_params(void *tls_ctx, struct tls_connection *conn,
			      const struct tls_connection_params *params)
{
#ifdef CONFIG_TLS_INTERNAL_CLIENT
	struct tlsv1_credentials *cred;

	if (conn->client == NULL)
		return -1;

	cred = tlsv1_cred_alloc();
	if (cred == NULL)
		return -1;

	if (tlsv1_set_ca_cert(cred, params->ca_cert,
			      params->ca_cert_blob, params->ca_cert_blob_len,
			      params->ca_path)) {
		wpa_printf(MSG_INFO, "TLS: Failed to configure trusted CA "
			   "certificates");
		tlsv1_cred_free(cred);
		return -1;
	}

	if (tlsv1_set_cert(cred, params->client_cert,
			   params->client_cert_blob,
			   params->client_cert_blob_len)) {
		wpa_printf(MSG_INFO, "TLS: Failed to configure client "
			   "certificate");
		tlsv1_cred_free(cred);
		return -1;
	}

	if (tlsv1_set_private_key(cred, params->private_key,
				  params->private_key_passwd,
				  params->private_key_blob,
				  params->private_key_blob_len)) {
		wpa_printf(MSG_INFO, "TLS: Failed to load private key");
		tlsv1_cred_free(cred);
		return -1;
	}

	if (tlsv1_client_set_cred(conn->client, cred) < 0) {
		tlsv1_cred_free(cred);
		return -1;
	}

	tlsv1_client_set_time_checks(
		conn->client, !(params->flags & TLS_CONN_DISABLE_TIME_CHECKS));

	return 0;
#else /* CONFIG_TLS_INTERNAL_CLIENT */
	return -1;
#endif /* CONFIG_TLS_INTERNAL_CLIENT */
}