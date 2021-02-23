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

/* Variables and functions */
 int /*<<< orphan*/  MSG_INFO ; 
 int /*<<< orphan*/  wpa_printf (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static int wps_validate_e_snonce1(const u8 *nonce, int mandatory)
{
	if (nonce == NULL) {
		if (mandatory) {
			wpa_printf(MSG_INFO, "WPS-STRICT: E-SNonce1 "
				   "attribute missing");
			return -1;
		}
		return 0;
	}
	return 0;
}