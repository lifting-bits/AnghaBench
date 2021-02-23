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
 int /*<<< orphan*/  EAP_EMSK_LEN ; 
 int /*<<< orphan*/  EAP_TEAP_SIMCK_LEN ; 
 int /*<<< orphan*/  MSG_DEBUG ; 
 scalar_t__ eap_teap_tls_prf (int /*<<< orphan*/  const*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wpa_hexdump_key (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

int eap_teap_derive_eap_emsk(const u8 *simck, u8 *emsk)
{
	/*
	 * RFC 7170, Section 5.4: EAP Master Session Key Generation
	 * EMSK = TLS-PRF(S-IMCK[j],
	 *        "Extended Session Key Generating Function", 64)
	 */

	if (eap_teap_tls_prf(simck, EAP_TEAP_SIMCK_LEN,
			     "Extended Session Key Generating Function",
			     (u8 *) "", 0, emsk, EAP_EMSK_LEN) < 0)
		return -1;
	wpa_hexdump_key(MSG_DEBUG, "EAP-TEAP: Derived key (EMSK)",
			emsk, EAP_EMSK_LEN);
	return 0;
}