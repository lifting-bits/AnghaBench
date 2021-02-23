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
struct wpa_supplicant {scalar_t__ p2p_mgmt; } ;

/* Variables and functions */
 int /*<<< orphan*/  wpas_dbus_signal_blob_added (struct wpa_supplicant*,char const*) ; 

void wpas_notify_blob_added(struct wpa_supplicant *wpa_s, const char *name)
{
	if (wpa_s->p2p_mgmt)
		return;

	wpas_dbus_signal_blob_added(wpa_s, name);
}