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
struct wps_parse_attr {int /*<<< orphan*/  authenticator; int /*<<< orphan*/ * version2; int /*<<< orphan*/  encr_settings_len; int /*<<< orphan*/  encr_settings; int /*<<< orphan*/  enrollee_nonce; int /*<<< orphan*/  msg_type; int /*<<< orphan*/  version; } ;
struct wpabuf {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MSG_INFO ; 
 int /*<<< orphan*/  wpa_printf (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ wps_parse_msg (struct wpabuf const*,struct wps_parse_attr*) ; 
 scalar_t__ wps_validate_authenticator (int /*<<< orphan*/ ,int) ; 
 scalar_t__ wps_validate_encr_settings (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 scalar_t__ wps_validate_enrollee_nonce (int /*<<< orphan*/ ,int) ; 
 scalar_t__ wps_validate_msg_type (int /*<<< orphan*/ ,int) ; 
 scalar_t__ wps_validate_version (int /*<<< orphan*/ ,int) ; 
 scalar_t__ wps_validate_version2 (int /*<<< orphan*/ *,int) ; 

int wps_validate_m8(const struct wpabuf *tlvs)
{
	struct wps_parse_attr attr;
	int wps2;

	if (tlvs == NULL) {
		wpa_printf(MSG_INFO, "WPS-STRICT: No TLVs in M8");
		return -1;
	}
	if (wps_parse_msg(tlvs, &attr) < 0) {
		wpa_printf(MSG_INFO, "WPS-STRICT: Failed to parse attributes "
			   "in M8");
		return -1;
	}

	wps2 = attr.version2 != NULL;
	if (wps_validate_version(attr.version, 1) ||
	    wps_validate_msg_type(attr.msg_type, 1) ||
	    wps_validate_enrollee_nonce(attr.enrollee_nonce, 1) ||
	    wps_validate_encr_settings(attr.encr_settings,
				       attr.encr_settings_len, 1) ||
	    wps_validate_version2(attr.version2, wps2) ||
	    wps_validate_authenticator(attr.authenticator, 1)) {
		wpa_printf(MSG_INFO, "WPS-STRICT: Invalid M8");
#ifdef WPS_STRICT_WPS2
		if (wps2)
			return -1;
#else /* WPS_STRICT_WPS2 */
		return -1;
#endif /* WPS_STRICT_WPS2 */
	}

	return 0;
}