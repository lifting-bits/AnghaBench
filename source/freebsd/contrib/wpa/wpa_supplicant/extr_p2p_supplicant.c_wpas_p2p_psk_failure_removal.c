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
struct wpa_supplicant {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  P2P_GROUP_REMOVAL_PSK_FAILURE ; 
 int /*<<< orphan*/  wpas_p2p_group_delete (struct wpa_supplicant*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void wpas_p2p_psk_failure_removal(void *eloop_ctx, void *timeout_ctx)
{
	struct wpa_supplicant *wpa_s = eloop_ctx;
	wpas_p2p_group_delete(wpa_s, P2P_GROUP_REMOVAL_PSK_FAILURE);
}