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
struct mem_ctl_info {int /*<<< orphan*/  pdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  IE31200_ERRSTS ; 
 int /*<<< orphan*/  IE31200_ERRSTS_BITS ; 
 int /*<<< orphan*/  pci_write_bits16 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  to_pci_dev (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void ie31200_clear_error_info(struct mem_ctl_info *mci)
{
	/*
	 * Clear any error bits.
	 * (Yes, we really clear bits by writing 1 to them.)
	 */
	pci_write_bits16(to_pci_dev(mci->pdev), IE31200_ERRSTS,
			 IE31200_ERRSTS_BITS, IE31200_ERRSTS_BITS);
}