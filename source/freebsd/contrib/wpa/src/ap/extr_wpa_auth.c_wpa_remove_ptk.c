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
struct wpa_state_machine {int /*<<< orphan*/  wpa_auth; void* pairwise_set; int /*<<< orphan*/  addr; int /*<<< orphan*/  PTK; void* PTK_valid; } ;

/* Variables and functions */
 void* FALSE ; 
 int /*<<< orphan*/  MSG_DEBUG ; 
 int /*<<< orphan*/  WPA_ALG_NONE ; 
 int /*<<< orphan*/  eloop_cancel_timeout (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct wpa_state_machine*) ; 
 int /*<<< orphan*/  os_memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 scalar_t__ wpa_auth_set_key (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wpa_printf (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  wpa_rekey_ptk ; 

void wpa_remove_ptk(struct wpa_state_machine *sm)
{
	sm->PTK_valid = FALSE;
	os_memset(&sm->PTK, 0, sizeof(sm->PTK));
	if (wpa_auth_set_key(sm->wpa_auth, 0, WPA_ALG_NONE, sm->addr, 0, NULL,
			     0))
		wpa_printf(MSG_DEBUG,
			   "RSN: PTK removal from the driver failed");
	sm->pairwise_set = FALSE;
	eloop_cancel_timeout(wpa_rekey_ptk, sm->wpa_auth, sm);
}