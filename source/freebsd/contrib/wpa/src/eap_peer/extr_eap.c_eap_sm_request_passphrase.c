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

/* Variables and functions */
 int /*<<< orphan*/  WPA_CTRL_REQ_EAP_PASSPHRASE ; 
 int /*<<< orphan*/  eap_sm_request (struct eap_sm*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void eap_sm_request_passphrase(struct eap_sm *sm)
{
	eap_sm_request(sm, WPA_CTRL_REQ_EAP_PASSPHRASE, NULL, 0);
}