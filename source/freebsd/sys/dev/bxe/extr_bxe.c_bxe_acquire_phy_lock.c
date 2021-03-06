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
struct bxe_softc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BXE_PHY_LOCK (struct bxe_softc*) ; 
 int /*<<< orphan*/  HW_LOCK_RESOURCE_MDIO ; 
 int /*<<< orphan*/  bxe_acquire_hw_lock (struct bxe_softc*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void bxe_acquire_phy_lock(struct bxe_softc *sc)
{
	BXE_PHY_LOCK(sc);
	bxe_acquire_hw_lock(sc,HW_LOCK_RESOURCE_MDIO); 
}