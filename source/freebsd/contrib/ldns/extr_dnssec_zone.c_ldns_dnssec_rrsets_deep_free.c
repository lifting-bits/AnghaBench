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
typedef  int /*<<< orphan*/  ldns_dnssec_rrsets ;

/* Variables and functions */
 int /*<<< orphan*/  ldns_dnssec_rrsets_free_internal (int /*<<< orphan*/ *,int) ; 

void
ldns_dnssec_rrsets_deep_free(ldns_dnssec_rrsets *rrsets)
{
	ldns_dnssec_rrsets_free_internal(rrsets, 1);
}