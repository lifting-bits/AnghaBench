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
struct eap_tls_data {int /*<<< orphan*/  ssl; struct eap_tls_data* session_id; } ;
struct eap_sm {int dummy; } ;

/* Variables and functions */
 scalar_t__ eap_peer_tls_reauth_init (struct eap_sm*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  eap_tls_free_key (struct eap_tls_data*) ; 
 int /*<<< orphan*/  os_free (struct eap_tls_data*) ; 

__attribute__((used)) static void * eap_tls_init_for_reauth(struct eap_sm *sm, void *priv)
{
	struct eap_tls_data *data = priv;
	eap_tls_free_key(data);
	os_free(data->session_id);
	data->session_id = NULL;
	if (eap_peer_tls_reauth_init(sm, &data->ssl)) {
		os_free(data);
		return NULL;
	}
	return priv;
}