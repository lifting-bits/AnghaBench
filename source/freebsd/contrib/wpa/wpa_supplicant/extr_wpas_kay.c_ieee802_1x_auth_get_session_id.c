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
typedef  int /*<<< orphan*/  u8 ;
struct wpa_supplicant {int /*<<< orphan*/  eapol; } ;

/* Variables and functions */
 int /*<<< orphan*/  MSG_DEBUG ; 
 int /*<<< orphan*/ * eapol_sm_get_session_id (int /*<<< orphan*/ ,size_t*) ; 
 int /*<<< orphan*/  os_memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,size_t) ; 
 int /*<<< orphan*/  wpa_printf (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static int ieee802_1x_auth_get_session_id(struct wpa_supplicant *wpa_s,
					  const u8 *addr, u8 *sid, size_t *len)
{
	const u8 *session_id;
	size_t id_len, need_len;

	session_id = eapol_sm_get_session_id(wpa_s->eapol, &id_len);
	if (session_id == NULL) {
		wpa_printf(MSG_DEBUG,
			   "Failed to get SessionID from EAPOL state machines");
		return -1;
	}

	need_len = 1 + 2 * 32 /* random size */;
	if (need_len > id_len) {
		wpa_printf(MSG_DEBUG, "EAP Session-Id not long enough");
		return -1;
	}

	os_memcpy(sid, session_id, need_len);
	*len = need_len;

	return 0;
}