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
struct ecore_vlan_mac_obj {int /*<<< orphan*/  head_reader; } ;
struct bxe_softc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ECORE_MSG (struct bxe_softc*,char*,int /*<<< orphan*/ ) ; 
 int ECORE_SUCCESS ; 

__attribute__((used)) static int __ecore_vlan_mac_h_read_lock(struct bxe_softc *sc,
					struct ecore_vlan_mac_obj *o)
{
	/* If we got here, we're holding lock --> no WRITER exists */
	o->head_reader++;
	ECORE_MSG(sc, "vlan_mac_lock - locked reader - number %d\n",
		  o->head_reader);

	return ECORE_SUCCESS;
}