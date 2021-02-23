#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint_t ;
typedef  int /*<<< orphan*/  dt_pfargv_t ;
typedef  int /*<<< orphan*/  dt_pfargd_t ;
struct TYPE_7__ {int /*<<< orphan*/  dn_type; int /*<<< orphan*/ * dn_ctfp; } ;
typedef  TYPE_1__ dt_node_t ;
typedef  int /*<<< orphan*/  ctf_id_t ;
typedef  int /*<<< orphan*/  ctf_file_t ;
struct TYPE_8__ {int cte_bits; } ;
typedef  TYPE_2__ ctf_encoding_t ;
struct TYPE_9__ {int /*<<< orphan*/  ctr_contents; } ;
typedef  TYPE_3__ ctf_arinfo_t ;

/* Variables and functions */
 int /*<<< orphan*/  CTF_ERR ; 
 scalar_t__ CTF_K_ARRAY ; 
 scalar_t__ CTF_K_INTEGER ; 
 scalar_t__ ctf_array_info (int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_3__*) ; 
 scalar_t__ ctf_type_encoding (int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_2__*) ; 
 scalar_t__ ctf_type_kind (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ctf_type_resolve (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
pfcheck_wstr(dt_pfargv_t *pfv, dt_pfargd_t *pfd, dt_node_t *dnp)
{
	ctf_file_t *ctfp = dnp->dn_ctfp;
	ctf_id_t base = ctf_type_resolve(ctfp, dnp->dn_type);
	uint_t kind = ctf_type_kind(ctfp, base);

	ctf_encoding_t e;
	ctf_arinfo_t r;

	return (kind == CTF_K_ARRAY && ctf_array_info(ctfp, base, &r) == 0 &&
	    (base = ctf_type_resolve(ctfp, r.ctr_contents)) != CTF_ERR &&
	    ctf_type_kind(ctfp, base) == CTF_K_INTEGER &&
	    ctf_type_encoding(ctfp, base, &e) == 0 && e.cte_bits == 32);
}