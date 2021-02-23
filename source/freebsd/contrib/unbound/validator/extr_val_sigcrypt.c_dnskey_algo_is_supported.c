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
struct ub_packed_rrset_key {int dummy; } ;

/* Variables and functions */
 int dnskey_algo_id_is_supported (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dnskey_get_algo (struct ub_packed_rrset_key*,size_t) ; 

int dnskey_algo_is_supported(struct ub_packed_rrset_key* dnskey_rrset,
        size_t dnskey_idx)
{
	return dnskey_algo_id_is_supported(dnskey_get_algo(dnskey_rrset, 
		dnskey_idx));
}