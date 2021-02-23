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
struct ucred {struct label* cr_label; } ;
struct mac_lomac {int dummy; } ;
struct label {int dummy; } ;

/* Variables and functions */
 struct mac_lomac* SLOT (struct label*) ; 
 int /*<<< orphan*/  try_relabel (struct mac_lomac*,struct mac_lomac*) ; 

__attribute__((used)) static void
lomac_cred_relabel(struct ucred *cred, struct label *newlabel)
{
	struct mac_lomac *source, *dest;

	source = SLOT(newlabel);
	dest = SLOT(cred->cr_label);

	try_relabel(source, dest);
}