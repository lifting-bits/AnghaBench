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
struct mac_mls {int dummy; } ;
struct label {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SLOT (struct label*) ; 
 int /*<<< orphan*/  bzero (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void
mls_sysvsem_cleanup(struct label *semalabel)
{

	bzero(SLOT(semalabel), sizeof(struct mac_mls));
}