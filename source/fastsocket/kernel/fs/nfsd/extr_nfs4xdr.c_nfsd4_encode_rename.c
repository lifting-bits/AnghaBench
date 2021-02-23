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
struct nfsd4_rename {int /*<<< orphan*/  rn_tinfo; int /*<<< orphan*/  rn_sinfo; } ;
struct nfsd4_compoundres {int dummy; } ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int /*<<< orphan*/  ADJUST_ARGS () ; 
 int /*<<< orphan*/  RESERVE_SPACE (int) ; 
 int /*<<< orphan*/  write_cinfo (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 

__attribute__((used)) static __be32
nfsd4_encode_rename(struct nfsd4_compoundres *resp, __be32 nfserr, struct nfsd4_rename *rename)
{
	__be32 *p;

	if (!nfserr) {
		RESERVE_SPACE(40);
		write_cinfo(&p, &rename->rn_sinfo);
		write_cinfo(&p, &rename->rn_tinfo);
		ADJUST_ARGS();
	}
	return nfserr;
}