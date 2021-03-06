#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u8 ;
typedef  int /*<<< orphan*/  u32 ;
struct xor_cb {TYPE_1__* ops; } ;
struct ppc440spe_adma_desc_slot {struct xor_cb* hw_desc; } ;
struct TYPE_2__ {int /*<<< orphan*/  h; } ;

/* Variables and functions */

__attribute__((used)) static void ppc440spe_rxor_set_region(struct ppc440spe_adma_desc_slot *desc,
	u8 xor_arg_no, u32 mask)
{
	struct xor_cb *xcb = desc->hw_desc;

	xcb->ops[xor_arg_no].h |= mask;
}