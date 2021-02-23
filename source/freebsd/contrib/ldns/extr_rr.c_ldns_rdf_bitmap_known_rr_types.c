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
typedef  int /*<<< orphan*/  ldns_status ;
typedef  int /*<<< orphan*/  ldns_rdf ;

/* Variables and functions */
 int /*<<< orphan*/  ldns_rdf_bitmap_known_rr_types_set (int /*<<< orphan*/ **,int) ; 

ldns_status
ldns_rdf_bitmap_known_rr_types(ldns_rdf** rdf)
{
	return ldns_rdf_bitmap_known_rr_types_set(rdf, 255);
}