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
typedef  int u16 ;

/* Variables and functions */
 int /*<<< orphan*/  MSG_INFO ; 
 int WPA_GET_BE16 (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  wpa_printf (int /*<<< orphan*/ ,char*,...) ; 

__attribute__((used)) static int wps_validate_assoc_state(const u8 *assoc_state, int mandatory)
{
	u16 val;
	if (assoc_state == NULL) {
		if (mandatory) {
			wpa_printf(MSG_INFO, "WPS-STRICT: Association State "
				   "attribute missing");
			return -1;
		}
		return 0;
	}
	val = WPA_GET_BE16(assoc_state);
	if (val > 4) {
		wpa_printf(MSG_INFO, "WPS-STRICT: Invalid Association State "
			   "attribute value 0x%04x", val);
		return -1;
	}
	return 0;
}