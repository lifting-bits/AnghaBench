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
struct eap_sm {int dummy; } ;
struct eap_eke_data {int /*<<< orphan*/  msgs; int /*<<< orphan*/  peerid; int /*<<< orphan*/  sess; } ;

/* Variables and functions */
 int /*<<< orphan*/  bin_clear_free (struct eap_eke_data*,int) ; 
 int /*<<< orphan*/  eap_eke_session_clean (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  os_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wpabuf_free (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void eap_eke_reset(struct eap_sm *sm, void *priv)
{
	struct eap_eke_data *data = priv;
	eap_eke_session_clean(&data->sess);
	os_free(data->peerid);
	wpabuf_free(data->msgs);
	bin_clear_free(data, sizeof(*data));
}