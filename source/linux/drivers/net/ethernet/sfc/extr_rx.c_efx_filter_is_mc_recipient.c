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
typedef  int u8 ;
struct efx_filter_spec {int flags; scalar_t__ dmaq_id; int match_flags; scalar_t__ ether_type; int /*<<< orphan*/ * loc_host; int /*<<< orphan*/  loc_mac; } ;

/* Variables and functions */
 int EFX_FILTER_FLAG_RX ; 
 int EFX_FILTER_MATCH_ETHER_TYPE ; 
 int EFX_FILTER_MATCH_LOC_HOST ; 
 int EFX_FILTER_MATCH_LOC_MAC ; 
 int EFX_FILTER_MATCH_LOC_MAC_IG ; 
 scalar_t__ EFX_FILTER_RX_DMAQ_ID_DROP ; 
 int /*<<< orphan*/  ETH_P_IP ; 
 int /*<<< orphan*/  ETH_P_IPV6 ; 
 scalar_t__ htons (int /*<<< orphan*/ ) ; 
 scalar_t__ ipv4_is_multicast (int /*<<< orphan*/ ) ; 
 scalar_t__ is_multicast_ether_addr (int /*<<< orphan*/ ) ; 

bool efx_filter_is_mc_recipient(const struct efx_filter_spec *spec)
{
	if (!(spec->flags & EFX_FILTER_FLAG_RX) ||
	    spec->dmaq_id == EFX_FILTER_RX_DMAQ_ID_DROP)
		return false;

	if (spec->match_flags &
	    (EFX_FILTER_MATCH_LOC_MAC | EFX_FILTER_MATCH_LOC_MAC_IG) &&
	    is_multicast_ether_addr(spec->loc_mac))
		return true;

	if ((spec->match_flags &
	     (EFX_FILTER_MATCH_ETHER_TYPE | EFX_FILTER_MATCH_LOC_HOST)) ==
	    (EFX_FILTER_MATCH_ETHER_TYPE | EFX_FILTER_MATCH_LOC_HOST)) {
		if (spec->ether_type == htons(ETH_P_IP) &&
		    ipv4_is_multicast(spec->loc_host[0]))
			return true;
		if (spec->ether_type == htons(ETH_P_IPV6) &&
		    ((const u8 *)spec->loc_host)[0] == 0xff)
			return true;
	}

	return false;
}