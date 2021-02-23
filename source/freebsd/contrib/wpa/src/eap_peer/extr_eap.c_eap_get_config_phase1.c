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
struct eap_peer_config {char const* phase1; } ;

/* Variables and functions */
 struct eap_peer_config* eap_get_config (struct eap_sm*) ; 

const char * eap_get_config_phase1(struct eap_sm *sm)
{
	struct eap_peer_config *config = eap_get_config(sm);
	if (config == NULL)
		return NULL;
	return config->phase1;
}