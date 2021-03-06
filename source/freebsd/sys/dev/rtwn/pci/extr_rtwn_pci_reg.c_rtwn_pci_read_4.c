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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  uint16_t ;
struct rtwn_softc {int dummy; } ;
struct rtwn_pci_softc {int /*<<< orphan*/  pc_sh; int /*<<< orphan*/  pc_st; } ;

/* Variables and functions */
 struct rtwn_pci_softc* RTWN_PCI_SOFTC (struct rtwn_softc*) ; 
 int /*<<< orphan*/  bus_space_read_4 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  le32toh (int /*<<< orphan*/ ) ; 

uint32_t
rtwn_pci_read_4(struct rtwn_softc *sc, uint16_t addr)
{
	struct rtwn_pci_softc *pc = RTWN_PCI_SOFTC(sc);
	uint32_t val;

	val = bus_space_read_4(pc->pc_st, pc->pc_sh, addr);
	return le32toh(val);
}