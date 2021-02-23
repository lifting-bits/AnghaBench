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
struct mbuf {int dummy; } ;
struct mac_biba {int dummy; } ;
struct label {int dummy; } ;
struct ipq {int dummy; } ;

/* Variables and functions */
 struct mac_biba* SLOT (struct label*) ; 
 int /*<<< orphan*/  biba_copy_effective (struct mac_biba*,struct mac_biba*) ; 

__attribute__((used)) static void
biba_ipq_create(struct mbuf *m, struct label *mlabel, struct ipq *q,
    struct label *qlabel)
{
	struct mac_biba *source, *dest;

	source = SLOT(mlabel);
	dest = SLOT(qlabel);

	biba_copy_effective(source, dest);
}