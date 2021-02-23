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
struct wpa_driver_capa {int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  WPA_DRIVER_FLAGS_WIRED ; 
 int /*<<< orphan*/  os_memset (struct wpa_driver_capa*,int /*<<< orphan*/ ,int) ; 

int driver_wired_get_capa(void *priv, struct wpa_driver_capa *capa)
{
	os_memset(capa, 0, sizeof(*capa));
	capa->flags = WPA_DRIVER_FLAGS_WIRED;
	return 0;
}