#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct wpa_supplicant {TYPE_1__* global; } ;
struct TYPE_2__ {int /*<<< orphan*/ * p2p; scalar_t__ p2p_disabled; } ;

/* Variables and functions */
 int p2p_ext_listen (int /*<<< orphan*/ *,unsigned int,unsigned int) ; 

int wpas_p2p_ext_listen(struct wpa_supplicant *wpa_s, unsigned int period,
			unsigned int interval)
{
	if (wpa_s->global->p2p_disabled || wpa_s->global->p2p == NULL)
		return -1;

	return p2p_ext_listen(wpa_s->global->p2p, period, interval);
}