#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct wpabuf {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  conn; } ;
struct eap_teap_data {int provisioning_allowed; int anon_provisioning; scalar_t__ test_outer_tlvs; int /*<<< orphan*/  teap_version; struct wpabuf* pending_phase2_req; scalar_t__ resuming; TYPE_1__ ssl; scalar_t__ provisioning; int /*<<< orphan*/  tls_cs; struct wpabuf* pending_resp; } ;
struct eap_sm {int /*<<< orphan*/  ssl_ctx; scalar_t__ waiting_ext_cert_check; } ;
struct eap_peer_config {scalar_t__ pending_ext_cert_check; } ;
struct eap_method_ret {void* decision; void* methodState; } ;
struct eap_hdr {int identifier; } ;
typedef  int /*<<< orphan*/  cipher ;

/* Variables and functions */
 void* DECISION_FAIL ; 
 int EAP_TEAP_FLAGS_OUTER_TLV_LEN ; 
 int EAP_TEAP_PROV_AUTH ; 
 int EAP_TLS_FLAGS_START ; 
 int /*<<< orphan*/  EAP_TYPE_TEAP ; 
 scalar_t__ EXT_CERT_CHECK_BAD ; 
 scalar_t__ EXT_CERT_CHECK_GOOD ; 
 void* METHOD_DONE ; 
 int /*<<< orphan*/  MSG_DEBUG ; 
 int /*<<< orphan*/  MSG_INFO ; 
 struct eap_peer_config* eap_get_config (struct eap_sm*) ; 
 struct wpabuf* eap_peer_tls_build_ack (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int eap_peer_tls_process_helper (struct eap_sm*,TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,struct wpabuf*,struct wpabuf**) ; 
 int* eap_peer_tls_process_init (struct eap_sm*,TYPE_1__*,int /*<<< orphan*/ ,struct eap_method_ret*,struct wpabuf const*,size_t*,int*) ; 
 struct wpabuf* eap_teap_add_dummy_outer_tlvs (struct eap_teap_data*,struct wpabuf*) ; 
 int eap_teap_decrypt (struct eap_sm*,struct eap_teap_data*,struct eap_method_ret*,int,struct wpabuf*,struct wpabuf**) ; 
 scalar_t__ eap_teap_derive_key_auth (struct eap_sm*,struct eap_teap_data*) ; 
 scalar_t__ eap_teap_process_start (struct eap_sm*,struct eap_teap_data*,int,int const*,size_t) ; 
 scalar_t__ os_strstr (char*,char*) ; 
 scalar_t__ tls_connection_established (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tls_connection_get_cipher_suite (int /*<<< orphan*/ ) ; 
 scalar_t__ tls_get_cipher (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  wpa_printf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  wpabuf_free (struct wpabuf*) ; 
 struct eap_hdr* wpabuf_head (struct wpabuf const*) ; 
 int wpabuf_len (struct wpabuf*) ; 
 int /*<<< orphan*/  wpabuf_set (struct wpabuf*,int const*,size_t) ; 

__attribute__((used)) static struct wpabuf * eap_teap_process(struct eap_sm *sm, void *priv,
					struct eap_method_ret *ret,
					const struct wpabuf *reqData)
{
	const struct eap_hdr *req;
	size_t left;
	int res;
	u8 flags, id;
	struct wpabuf *resp;
	const u8 *pos;
	struct eap_teap_data *data = priv;
	struct wpabuf msg;

	pos = eap_peer_tls_process_init(sm, &data->ssl, EAP_TYPE_TEAP, ret,
					reqData, &left, &flags);
	if (!pos)
		return NULL;

	req = wpabuf_head(reqData);
	id = req->identifier;

	if (flags & EAP_TLS_FLAGS_START) {
		if (eap_teap_process_start(sm, data, flags, pos, left) < 0)
			return NULL;

		/* Outer TLVs are not used in further packet processing and
		 * there cannot be TLS Data in this TEAP/Start message, so
		 * enforce that by ignoring whatever data might remain in the
		 * buffer. */
		left = 0;
	} else if (flags & EAP_TEAP_FLAGS_OUTER_TLV_LEN) {
		/* TODO: RFC 7170, Section 4.3.1 indicates that the unexpected
		 * Outer TLVs MUST be ignored instead of ignoring the full
		 * message. */
		wpa_printf(MSG_INFO,
			   "EAP-TEAP: Outer TLVs present in non-Start message -> ignore message");
		return NULL;
	}

	wpabuf_set(&msg, pos, left);

	resp = NULL;
	if (tls_connection_established(sm->ssl_ctx, data->ssl.conn) &&
	    !data->resuming) {
		/* Process tunneled (encrypted) phase 2 data. */
		res = eap_teap_decrypt(sm, data, ret, id, &msg, &resp);
		if (res < 0) {
			ret->methodState = METHOD_DONE;
			ret->decision = DECISION_FAIL;
			/*
			 * Ack possible Alert that may have caused failure in
			 * decryption.
			 */
			res = 1;
		}
	} else {
		if (sm->waiting_ext_cert_check && data->pending_resp) {
			struct eap_peer_config *config = eap_get_config(sm);

			if (config->pending_ext_cert_check ==
			    EXT_CERT_CHECK_GOOD) {
				wpa_printf(MSG_DEBUG,
					   "EAP-TEAP: External certificate check succeeded - continue handshake");
				resp = data->pending_resp;
				data->pending_resp = NULL;
				sm->waiting_ext_cert_check = 0;
				return resp;
			}

			if (config->pending_ext_cert_check ==
			    EXT_CERT_CHECK_BAD) {
				wpa_printf(MSG_DEBUG,
					   "EAP-TEAP: External certificate check failed - force authentication failure");
				ret->methodState = METHOD_DONE;
				ret->decision = DECISION_FAIL;
				sm->waiting_ext_cert_check = 0;
				return NULL;
			}

			wpa_printf(MSG_DEBUG,
				   "EAP-TEAP: Continuing to wait external server certificate validation");
			return NULL;
		}

		/* Continue processing TLS handshake (phase 1). */
		res = eap_peer_tls_process_helper(sm, &data->ssl,
						  EAP_TYPE_TEAP,
						  data->teap_version, id, &msg,
						  &resp);
		if (res < 0) {
			wpa_printf(MSG_DEBUG,
				   "EAP-TEAP: TLS processing failed");
			ret->methodState = METHOD_DONE;
			ret->decision = DECISION_FAIL;
			return resp;
		}

		if (sm->waiting_ext_cert_check) {
			wpa_printf(MSG_DEBUG,
				   "EAP-TEAP: Waiting external server certificate validation");
			wpabuf_free(data->pending_resp);
			data->pending_resp = resp;
			return NULL;
		}

		if (tls_connection_established(sm->ssl_ctx, data->ssl.conn)) {
			char cipher[80];

			wpa_printf(MSG_DEBUG,
				   "EAP-TEAP: TLS done, proceed to Phase 2");
			data->tls_cs =
				tls_connection_get_cipher_suite(data->ssl.conn);
			wpa_printf(MSG_DEBUG,
				   "EAP-TEAP: TLS cipher suite 0x%04x",
				   data->tls_cs);

			if (data->provisioning &&
			    (!(data->provisioning_allowed &
			       EAP_TEAP_PROV_AUTH) ||
			     tls_get_cipher(sm->ssl_ctx, data->ssl.conn,
					    cipher, sizeof(cipher)) < 0 ||
			     os_strstr(cipher, "ADH-") ||
			     os_strstr(cipher, "anon"))) {
				wpa_printf(MSG_DEBUG,
					   "EAP-TEAP: Using anonymous (unauthenticated) provisioning");
				data->anon_provisioning = 1;
			} else {
				data->anon_provisioning = 0;
			}
			data->resuming = 0;
			if (eap_teap_derive_key_auth(sm, data) < 0) {
				wpa_printf(MSG_DEBUG,
					   "EAP-TEAP: Could not derive keys");
				ret->methodState = METHOD_DONE;
				ret->decision = DECISION_FAIL;
				wpabuf_free(resp);
				return NULL;
			}
		}

		if (res == 2) {
			/*
			 * Application data included in the handshake message.
			 */
			wpabuf_free(data->pending_phase2_req);
			data->pending_phase2_req = resp;
			resp = NULL;
			res = eap_teap_decrypt(sm, data, ret, id, &msg, &resp);
		}
	}

	if (res == 1) {
		wpabuf_free(resp);
		return eap_peer_tls_build_ack(id, EAP_TYPE_TEAP,
					      data->teap_version);
	}

#ifdef CONFIG_TESTING_OPTIONS
	if (data->test_outer_tlvs && res == 0 && resp &&
	    (flags & EAP_TLS_FLAGS_START) && wpabuf_len(resp) >= 6)
		resp = eap_teap_add_dummy_outer_tlvs(data, resp);
#endif /* CONFIG_TESTING_OPTIONS */

	return resp;
}