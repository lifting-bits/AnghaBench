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
typedef  int /*<<< orphan*/  ldns_rdf_type ;
typedef  int /*<<< orphan*/  ldns_rdf ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  ldns_rdf_new_frm_fp_l (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

ldns_status
ldns_rdf_new_frm_fp(ldns_rdf **rdf, ldns_rdf_type type, FILE *fp)
{
	return ldns_rdf_new_frm_fp_l(rdf, type, fp, NULL);
}